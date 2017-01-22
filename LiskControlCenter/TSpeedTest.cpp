//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#include "mymsg.h"
#include "TSpeedTest.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TSpeedTest::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TSpeedTest::TSpeedTest(bool CreateSuspended,TListItem *item)
	: TThread(CreateSuspended)
{
	Item=item;
	liskapi=new LiskAPI(AnsiString(Item->SubItems->Strings[1]).c_str());
	this->FreeOnTerminate=true;
}
//---------------------------------------------------------------------------
void __fastcall TSpeedTest::Execute()
{
	//---- Place thread code here ----
	int ret=-1;
	char *data=NULL;
	try{
		data=liskapi->Ping();
	}catch(...)
	{
		data=NULL;
	}
	if(data!=NULL){
		TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(UnicodeString(data));
		if(json->getBoolean("success")){
			ret=1;
		}else{
			ret=0;
		}
        json->Free();

	}
     DoFinished(Item,ret);
}
//---------------------------------------------------------------------------
void __fastcall TSpeedTest::DoFinished(TListItem *item,int state)
{
	if(OnFinished)OnFinished(item,state);
}
