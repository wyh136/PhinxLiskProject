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
 int pos=-1,old_forged=0,old_missed=0;
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
     TestNet=isTestNet;
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


}
//---------------------------------------------------------------------------
void __fastcall TDelegateInfo::DoOnData(UnicodeString username,UnicodeString votes,UnicodeString rank, UnicodeString address,double balance,UnicodeString approval, unsigned int producedblocks, unsigned int missedblocks,int position,int _pos )
{
		if(OnData)OnData(username,votes,rank,address,balance,approval, producedblocks,missedblocks,position, _pos);
}



void __fastcall TDelegateInfo::Reload()
{
	char* data="";
	UnicodeString username="";
	UnicodeString rank="";
	UnicodeString address="";
	double balance=0.0;
	UnicodeString approval="";
	unsigned int producedblocks=0;
	unsigned int missedblocks=0;
	UnicodeString votes="";
	int position=0;
    int test=0;
	while(!this->Terminated){
	try{
	repeat:
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
			pkey=jo->getString("publicKey");
			votes=FormatFloat("00.00",vote);
			approval=FloatToStr(jo->getDouble("approval"))+" %";
			producedblocks=jo->getInt("producedblocks");
			missedblocks=jo->getInt("missedblocks");
			position=jo->getInt("productivity");
			if(old_forged==0) old_forged=producedblocks;
			if(old_missed==0) old_missed=missedblocks;
			if(producedblocks>old_forged)
			{
				 DoOnForged(producedblocks);
				 old_forged= producedblocks;
			}

			if(missedblocks>old_missed)
			{
				DoOnMissed(missedblocks);
				old_missed= missedblocks;
			}

			if(TestNet){
				TEST_USERNAME=username;
				TEST_PKEY=pkey;
			}else{
				MAIN_USERNAME=username;
				MAIN_PKEY=pkey;
			}

		}
		json->Free();
	}
		Sleep(20);
		data=liskapi->Balance(AnsiString(address).c_str());
	if(data&&pkey!=""){
		pos=0 ;
		TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(UnicodeString(data));

		if(json->getBoolean("success"))
		{
			balance=StrToFloat(json->getString("balance"))/100000000;
		}else{
			balance=0;
		}
		json->Free();


		Sleep(50);
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

	}

    }catch(...)
	{
        goto repeat;
	}
	DoOnData(username,votes,rank,address,balance,approval, producedblocks,missedblocks,position,pos);
	}
		Sleep(10000);
}


void __fastcall TDelegateInfo::DoOnForged(unsigned int blockcount)
{
	if(OnForged)OnForged(blockcount);
}

void __fastcall TDelegateInfo::DoOnMissed(unsigned int blockcount)
{
   if(OnMissed)OnMissed(blockcount);
}
