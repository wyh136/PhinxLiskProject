//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#include "TPublicNodeWatcher.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TPublicNodeWatcher::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TPublicNodeWatcher::TPublicNodeWatcher(bool CreateSuspended,TListItems *items)
	: TThread(CreateSuspended)
{
	if(items==NULL){
		this->Terminate();
		return;
	}
	listitems=items;
	this->FreeOnTerminate=true;
	http = new TIdHTTP();
	http->Request->ContentType = "application/json";
}
//---------------------------------------------------------------------------
void __fastcall TPublicNodeWatcher::Execute()
{
	NameThreadForDebugging(System::String(L"TPublicNodeWatcher"));
	//---- Place thread code here ----
	while(!this->Terminated)
	{
		for(int i=0;i<listitems->Count;i++)
		{
			GetStatu(listitems->Item[i]);
		}
		Sleep(10000);
	}
}
//---------------------------------------------------------------------------
void __fastcall TPublicNodeWatcher::GetStatu(TListItem *item)
{
	UnicodeString url=item->SubItems->Strings[2];
	if(url.LowerCase().SubString(0,5)=="https")
	{
        if(ssl==NULL)ssl=new TIdSSLIOHandlerSocketOpenSSL();
		http->IOHandler=ssl;
	}else{
        http->IOHandler=NULL;
	}
	UnicodeString result = http->Get(url+"/api/loader/status/sync");
	TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(result);
	item->SubItems->Strings[1]=IntToStr(json->getInt("height"));
	if(json->getBoolean("syncing"))
	{
		item->SubItems->Strings[3] ="Syncing "+IntToStr(json->getInt("blocks"))+" blocks left";
	}else{

		item->SubItems->Strings[3]="Synced";
	}
	json->Free();
}

__fastcall TPublicNodeWatcher::~TPublicNodeWatcher()
{
	 if(ssl)ssl->Free();
	 if(http)http->Free();
}


