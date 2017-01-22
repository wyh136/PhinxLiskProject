//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "TFetchVotes.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TFetchVotes::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
double sum=0.0;
__fastcall TFetchVotes::TFetchVotes(bool CreateSuspended,bool isTestNet,TListItems *items)
	: TThread(CreateSuspended)
{
	TestNet=isTestNet;
	if(isTestNet)
	{
		liskapi=new LiskAPI(AnsiString(TEST_PUBLIC_NODE).c_str());
		username=TEST_USERNAME;
        publickey=TEST_PKEY;
	}
	else
	{
		liskapi=new LiskAPI(AnsiString(MAIN_PUBLIC_NODE).c_str());
		username=MAIN_USERNAME;
		publickey=MAIN_PKEY;
	}
	this->FreeOnTerminate=true;
	Items=items;
}


void __fastcall TFetchVotes::enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue)
{
		if(Items==NULL){Continue=false;return;}
		TListItem *item=Items->Add();
		item->Caption=Items->Count;
		TlkJSONobject *jo=(TlkJSONobject *)Elem;
		if(jo->Field["username"]->SelfTypeName()=="jsNull")
			item->SubItems->Add("--");
		else
			item->SubItems->Add(jo->getString("username"));
		item->SubItems->Add(jo->getString("address"));
		double b=jo->getString("balance").ToDouble()/100000000;
		item->SubItems->Add(FormatFloat("###,#0.##",b));
		sum+=b;
		item->SubItems->Add(FormatFloat("###,#0.##",sum));
		Continue=true;
}
//---------------------------------------------------------------------------
void __fastcall TFetchVotes::Execute()
{
	NameThreadForDebugging(System::String(L"TFetchVotes"));
	//---- Place thread code here ----
	//if(publickey=="")return;
	char *data=liskapi->GetVotersByPubkey(AnsiString(publickey).c_str());
	TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(UnicodeString(data));

	if(json->getBoolean("success")){
		TlkJSONlist *voters=(TlkJSONlist *)json->Field["accounts"];

		enumfuc=enumlist;
		voters->ForEach(enumfuc,Items);
		//DoOnVoters(voters->Count,list);

	}else{
		//DoOnVoters(-1,NULL);
	}
    json->Free();

}
//---------------------------------------------------------------------------
void __fastcall TFetchVotes::DoOnVoters(int count,TThreadList *voters)
{
	if(OnVoters)OnVoters(count,voters);
}
