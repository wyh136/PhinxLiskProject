//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#include "TDelegateInfo.h"
#include "mymsg.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TDelegateInfo::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
 int pos=-1;
__fastcall TDelegateInfo::TDelegateInfo(bool CreateSuspended,UnicodeString username,bool isTestNet)
	: TThread(CreateSuspended)
{
	 if(isTestNet)
	 {
		NodeUrl=AnsiString(TEST_PUBLIC_NODE).c_str();
	 }else{
		NodeUrl=AnsiString(MAIN_PUBLIC_NODE).c_str();
	 }
	 liskapi=new LiskAPI(NodeUrl);
	 UserName=username;
     this->FreeOnTerminate=true;
}

__fastcall TDelegateInfo::~TDelegateInfo()
{

    if(liskapi)delete liskapi;
}
//---------------------------------------------------------------------------

void __fastcall TDelegateInfo::enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue)
{
	pos++;
	TlkJSONstring *v=(TlkJSONstring *)Elem;
	UnicodeString *pkey=(UnicodeString *)data;
	if(v->Value.operator UnicodeString()==*pkey)
	{
		Continue=false;
		return;
	}
	Continue=true;


}


void __fastcall TDelegateInfo::Execute()
{
	//---- Place thread code here ----
	Reload();
	Sleep(10000);

}
//---------------------------------------------------------------------------
void __fastcall TDelegateInfo::DoOnData(UnicodeString username,UnicodeString votes,UnicodeString rank, UnicodeString address,UnicodeString publickey,UnicodeString approval, unsigned int producedblocks, unsigned int missedblocks,int position,int _pos )
{
		if(OnData)OnData(username,votes,rank,address,publickey,approval, producedblocks,missedblocks,position, _pos);
}

void __fastcall TDelegateInfo::Reload()
{
	char* data="";
	UnicodeString username="";
	UnicodeString rank="";
	UnicodeString address="";
	UnicodeString publickey="";
	UnicodeString approval="";
	unsigned int producedblocks=0;
	unsigned int missedblocks=0;
	UnicodeString votes="";
	int position=0;
	while(!this->Terminated){
	try{
		data=liskapi->GetDelegateByName(AnsiString(UserName).c_str());

	UnicodeString pkey="";
	if(data){
		TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(UnicodeString(data));
		if(json->getBoolean("success"))
		{
 			TlkJSONobject *jo=(TlkJSONobject *)json->Field["delegate"];
			float vote=jo->Field["vote"]->Value.operator unsigned __int64() / 100000000000000.0;
			username=jo->getString("username");
			rank=IntToStr(jo->getInt("rate"));
			address=jo->getString("address");
			publickey=jo->getString("publicKey");
			pkey=jo->getString("publicKey");
			votes=FormatFloat("00.00",vote);
			approval=FloatToStr(jo->getDouble("approval"))+" %";
			producedblocks=jo->getInt("producedblocks");
			missedblocks=jo->getInt("missedblocks");
			position=jo->getInt("productivity");

		}
		json->Free();
	}
		Sleep(10);
		data=liskapi->GetNextForgers(20);
	if(data&&pkey!=""){
		pos=0 ;
		TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(UnicodeString(data));

		if(json->getBoolean("success"))
		{
			TlkJSONlist *nodes=(TlkJSONlist *)json->Field["delegates"];
			nodes->ForEach(enumlist,&pkey);
		}
        json->Free();

	}
    }catch(...)
	{

	}
	DoOnData(username,votes,rank,address,publickey,approval, producedblocks,missedblocks,position,pos);
    Sleep(10000);
	}
}

