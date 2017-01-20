//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TForgeJob.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TffrmServers *ffrmServers;
UnicodeString exepath="";

//---------------------------------------------------------------------------
__fastcall TffrmServers::TffrmServers(TComponent* Owner,bool isTestNet)
	: TFrame(Owner)
{
	exepath=ExtractFileDir(ParamStr(0));
	testnet=isTestNet;
}
//---------------------------------------------------------------------------
void __fastcall TffrmServers::StopJobs()
{
	for(int i=0;i<lv->Items->Count;i++)
	{
		  if(lv->Items->Item[i]->Data==NULL)return;
		  TForgeJob *fjob=(TForgeJob *)lv->Items->Item[i]->Data;
          fjob->Terminate();
	}


}


//---------------------------------------------------------------------------
void __fastcall TffrmServers::enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue)
{
		if(data==NULL){Continue=false;return;}
		TListItems *items=(TListItems *)data;
		TListItem *item=items->Add();
		item->Caption=IntToStr(items->Count);
		item->SubItems->Add(((TlkJSONobject *)Elem)->getString("url"));
		item->SubItems->Add("");
		item->SubItems->Add("");
		item->SubItems->Add("");
		item->SubItems->Add("");
		TForgeJob *fjob=new TForgeJob(false,item,AnsiString(((TlkJSONobject *)Elem)->getString("url")).c_str(), publickey);
	    item->Data=(void *)fjob;
		Continue=true;
}
//---------------------------------------------------------------------------
void __fastcall TffrmServers::LoadPublicNodes()
{

	UnicodeString path=exepath+"\\forge_serves\\";
	if(testnet)
	{
		path+="testnet.json";
		GroupBox1->Caption="Server Array [ TestNet ]" ;
	}
	else
	{
			path+="mainnet.json";
			GroupBox1->Caption="Server Array [ MainNet ]" ;
	}
	TStringList *ss=new TStringList();
	ss->Clear();
	try{
		ss->LoadFromFile(path);
	}catch(...)
	{
		ss->Text="{\"servers\":[]}";
	}
	TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(ss->Text);
	TlkJSONlist *nodes=(TlkJSONlist *)json->Field["servers"];
	enumfuc=enumlist;
	lv->Items->Clear();
	nodes->ForEach(enumfuc,lv->Items);
	delete ss;
    json->Free();

}

UnicodeString __fastcall TffrmServers::LoadDelegateInfo()
{

	UnicodeString path=exepath+"\\delegate_set\\";
	if(testnet)
	{
		path+="testnet.json";
	}
	else
	{
			path+="mainnet.json";
	}
	TStringList *ss=new TStringList();
	ss->Clear();
	try{
		ss->LoadFromFile(path);
	}catch(...)
	{
		ss->Text="{}";
	}
	TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(ss->Text);
	username=json->getString("username");
	publickey=json->getString("publickey");
	address=json->getString("address");
	delete ss;
	json->Free();
	return username;

}

