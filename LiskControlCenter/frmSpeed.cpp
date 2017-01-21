//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmSpeed.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSpeedTest *frmSpeedTest;
int counter=0;
TListItem *best_test=NULL,*best_main=NULL;
void __fastcall (__closure *enumfuc)(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
//---------------------------------------------------------------------------
__fastcall TfrmSpeedTest::TfrmSpeedTest(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSpeedTest::LoadPublicNodes(bool isTestNet)
{
	UnicodeString path=ExtractFileDir(ParamStr(0))+"\\public_nodes\\";
	if(isTestNet)
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
		ss->Text="{\"nodes\":[]}";
	}
	TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(ss->Text);
	TlkJSONlist *nodes=(TlkJSONlist *)json->Field["nodes"];
	enumfuc=enumlist;
	if(isTestNet)
		nodes->ForEach(enumfuc,NULL);
	else
		nodes->ForEach(enumfuc,&isTestNet);
	json->Free();
	if(lv->Items->Count>0){
        Button1->Enabled=true;
	}
	delete ss;

}
//---------------------------------------------------------------------------
void __fastcall TfrmSpeedTest::enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue)
{
		TListItem *item=lv->Items->Add();
		item->Caption=IntToStr(lv->Items->Count);
		item->SubItems->Add(((TlkJSONobject *)Elem)->getString("owner"));
		item->SubItems->Add(((TlkJSONobject *)Elem)->getString("URL"));

		if(data==NULL){
			item->SubItems->Add("Testnet");
		}else{
        	item->SubItems->Add("Mainnet");
		}
		item->SubItems->Add("0");
		Continue=true;
}
void __fastcall TfrmSpeedTest::FormCreate(TObject *Sender)
{
	 LoadPublicNodes(false);
	 LoadPublicNodes(true);

}
//---------------------------------------------------------------------------

void __fastcall TfrmSpeedTest::FormClose(TObject *Sender, TCloseAction &Action)

{
          Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSpeedTest::StartTest()
{
	 Button1->Enabled=false;
     Button2->Enabled=false;
	 Timer1->Enabled=true;
	 counter=lv->Items->Count;
	 for(int i=0;i<lv->Items->Count;i++)
	 {
		lv->Items->Item[i]->SubItems->Strings[3]="0";
		TSpeedTest *tst=new TSpeedTest(true,lv->Items->Item[i]);
		lv->Items->Item[i]->Data=tst;
		tst->OnFinished=OnFinished;
		tst->Resume();
	 }


}


void __fastcall TfrmSpeedTest::OnFinished(TListItem *item,int state)
{
	TSpeedTest *tst=(TSpeedTest *)item->Data;
	counter--;
	if(tst!=NULL)tst->Terminate();
	if(item->Data!=NULL)item->Data=NULL;
	switch(state){
		case -1:   item->SubItems->Strings[3]="OFF";break;
		case 0:    item->SubItems->Strings[3]="ERROR";break;
		case 1:	   item->SubItems->Strings[3]=item->SubItems->Strings[3];break;
	}

}
void __fastcall TfrmSpeedTest::Timer1Timer(TObject *Sender)
{
	for(int i=0;i<lv->Items->Count;i++)
	 {
        TListItem *Item=lv->Items->Item[i];
		if(Item->Data!=NULL)
		{
			Item->SubItems->Strings[3]=StrToInt(Item->SubItems->Strings[3])+1;
		}
	 }

	if(counter==0){

	   Memo1->Lines->Add("Testing finished.");
       SaveBestNodes();
	}

}
//---------------------------------------------------------------------------
void __fastcall TfrmSpeedTest::SaveBestNodes()
{
            Timer1->Enabled=false;
		int ping_test=-1,bestping_test=-1,ping_main=-1,bestping_main=-1;
		TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText("{\"servers\":{\"mainnet\":\"\",\"testnet\":\"\"}}");
		TlkJSONlist *nodes=(TlkJSONlist *)json->Field["servers"];
		for(int i=0;i<lv->Items->Count;i++)
		{
			if(lv->Items->Item[i]->SubItems->Strings[3]=="ERROR"||lv->Items->Item[i]->SubItems->Strings[3]=="OFF")
			continue;

			if(lv->Items->Item[i]->SubItems->Strings[2]=="Testnet")
			{	ping_test=StrToInt(lv->Items->Item[i]->SubItems->Strings[3]);
				if(ping_test=-1||ping_test<bestping_test)
				{	bestping_test=ping_test;
					best_test=lv->Items->Item[i];
				}
			}else{
				ping_main=StrToInt(lv->Items->Item[i]->SubItems->Strings[3]);
				if(ping_main=-1||ping_main<bestping_main)
				{	bestping_main=ping_main;
					best_main=lv->Items->Item[i];
				}
			}
		}
	if(best_main){
		 nodes->Field["mainnet"]->Value=best_main->SubItems->Strings[1];
	}
    if(best_test){
		 nodes->Field["testnet"]->Value=best_test->SubItems->Strings[1];
	}
	Memo1->Lines->Add("Best mainnet node is :"+best_main->SubItems->Strings[1]);
	Memo1->Lines->Add("Best testnet node is :"+best_test->SubItems->Strings[1]);
	UnicodeString path=ExtractFileDir(ParamStr(0))+"\\config.json";
	TStringList *ss=new TStringList();
	ss->Text=TlkJSON::GenerateText(json);
	ss->SaveToFile(path);
	json->Free();
	delete ss;
	Memo1->Lines->Add("Best node save successful!");
    SendMessage(MainFrmHand,WM_NODE_APPLY,0,0);
	Button1->Enabled=true;
	Button2->Enabled=true;
}
void __fastcall TfrmSpeedTest::Button1Click(TObject *Sender)
{
    StartTest();
}
//---------------------------------------------------------------------------


void __fastcall TfrmSpeedTest::Button2Click(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

