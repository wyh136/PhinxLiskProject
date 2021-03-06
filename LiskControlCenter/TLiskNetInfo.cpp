//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "TLiskNetInfo.h"
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TLiskNetInfo::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TLiskNetInfo::TLiskNetInfo(bool CreateSuspended,bool isTest,TMainFrm *frm)
	: TThread(CreateSuspended)
{
	mainfrm=frm;
	if(isTest){
		nodeurl=TEST_PUBLIC_NODE;
	}else{
        nodeurl=MAIN_PUBLIC_NODE;
	}
	liskapi=new LiskAPI(AnsiString(nodeurl).c_str());
    this->FreeOnTerminate=true;
}
//---------------------------------------------------------------------------
void __fastcall TLiskNetInfo::Execute()
{
	NameThreadForDebugging(System::String(L"LiskNetInfo"));
	//---- Place thread code here ----
	TlkJSONobject *jo;
    char *data=NULL;
	while(!this->Terminated){
		try{
			data=liskapi->GetStatus();
			if(data){
				jo=(TlkJSONobject *)TlkJSON::ParseText(UnicodeString( data));
				mainfrm->sbar->Panels->Items[1]->Text=nodeurl;
				if(jo->getBoolean("success"))
				  mainfrm->sbar->Panels->Items[0]->Text="Online";
				else
				  mainfrm->sbar->Panels->Items[0]->Text="Offline";
			   mainfrm->sbar->Panels->Items[2]->Text="blocks : "+ IntToStr(jo->getInt("height"));
			   mainfrm->sbar->Panels->Items[3]->Text="supply : "+ FloatToStr(jo->getDouble("supply")/100000000 );
			   Sleep(10000);
			   jo->Free();
			}
		}catch(...)
        {}
	}
}
//---------------------------------------------------------------------------
__fastcall TLiskNetInfo::~TLiskNetInfo()
{
	if(liskapi)liskapi->~LiskAPI();
}
