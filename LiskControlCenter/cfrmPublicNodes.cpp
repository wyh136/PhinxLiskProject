//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "frmMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPublicNodes *frmPublicNodes;
void __fastcall (__closure *enumfuc)(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
//---------------------------------------------------------------------------
__fastcall TfrmPublicNodes::TfrmPublicNodes(TComponent* Owner)
	: TForm(Owner)
{

}

void __fastcall TfrmPublicNodes::enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue)
{
        if(data==NULL){Continue=false;return;}
		TListItems *items=(TListItems *)data;
		TListItem *item=items->Add();
		item->Caption=IntToStr(items->Count);
		item->SubItems->Add(((TlkJSONobject *)Elem)->getString("owner"));
		item->SubItems->Add(((TlkJSONobject *)Elem)->getString("URL"));
		Continue=true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPublicNodes::LoadPublicNodes(bool isTestNet)
{
	UnicodeString path=ExtractFileDir(ParamStr(0))+"\\public_nodes\\";
	TListView *lv=NULL;
	if(isTestNet)
	{
		path+="testnet.json";
		lv=lvTest;
	}
	else
	{
			path+="mainnet.json";
			lv=lvMain;
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
	lv->Items->Clear();
	nodes->ForEach(enumfuc,lv->Items);
    json->Free();
	delete ss;

}

void __fastcall TfrmPublicNodes::SavePublicNodes(bool isTestNet)
{
	UnicodeString path=ExtractFileDir(ParamStr(0))+"\\public_nodes\\";
	TListView *lv=NULL;
	if(isTestNet)
	{
		path+="testnet.json";
		lv=lvTest;
	}
	else
	{
			path+="mainnet.json";
			lv=lvMain;
	}
	if(lv->Items->Count<1)return;
	TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText("{\"nodes\":[]}");
	TlkJSONlist *nodes=(TlkJSONlist *)json->Field["nodes"];
	TlkJSONobject *item=NULL;
	for(int i=0;i<lv->Items->Count;i++){
		item=(TlkJSONobject *)TlkJSON::ParseText("{\"owner\":\"\",\"URL\":\"\"}");
		item->Field["owner"]->Value=lv->Items->Item[i]->SubItems->Strings[0] ;
		item->Field["URL"]->Value=lv->Items->Item[i]->SubItems->Strings[1];
		nodes->Add(item);
	}
	TStringList *ss=new TStringList();
	ss->Text=TlkJSON::GenerateText(json);
	ss->SaveToFile(path);
	json->Free();
    delete ss;

}


void __fastcall TfrmPublicNodes::FormCreate(TObject *Sender)
{
	LoadPublicNodes(true);
	LoadPublicNodes(false);
}
//---------------------------------------------------------------------------


void __fastcall TfrmPublicNodes::FormClose(TObject *Sender, TCloseAction &Action)

{
	Action=caFree;
}
//---------------------------------------------------------------------------



void __fastcall TfrmPublicNodes::lvMainSelectItem(TObject *Sender, TListItem *Item,
		  bool Selected)
{
	edt_owner->Text=Item->SubItems->Strings[0];
	edt_url->Text=Item->SubItems->Strings[1];
	Selected=true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPublicNodes::lvTestSelectItem(TObject *Sender, TListItem *Item,
          bool Selected)
{
	Edit1->Text=Item->SubItems->Strings[0];
	Edit2->Text=Item->SubItems->Strings[1];
	Selected=true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPublicNodes::bt_newClick(TObject *Sender)
{
		if(edt_owner->Text.Trim()==""||edt_url->Text.Trim()=="")
		{
			return;
		}
		TListItem *item=lvMain->Items->Add();
		item->Caption=IntToStr(lvMain->Items->Count);
		item->SubItems->Add(edt_owner->Text.Trim());
		item->SubItems->Add(edt_url->Text.Trim());
}
//---------------------------------------------------------------------------

void __fastcall TfrmPublicNodes::bt_delClick(TObject *Sender)
{
	if(lvMain->SelCount<1)return;
	lvMain->DeleteSelected();
	edt_owner->Text="";
	edt_url->Text="";
}
//---------------------------------------------------------------------------


void __fastcall TfrmPublicNodes::bt_CancelClick(TObject *Sender)
{
	edt_owner->Text="";
	edt_url->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TfrmPublicNodes::bt_saveClick(TObject *Sender)
{
	SavePublicNodes(false);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPublicNodes::Button1Click(TObject *Sender)
{
	if(Edit1->Text.Trim()==""||Edit2->Text.Trim()=="")
		{
			return;
		}
		TListItem *item=lvTest->Items->Add();
		item->Caption=IntToStr(lvTest->Items->Count);
		item->SubItems->Add(Edit1->Text.Trim());
		item->SubItems->Add(Edit2->Text.Trim());
}
//---------------------------------------------------------------------------

void __fastcall TfrmPublicNodes::Button2Click(TObject *Sender)
{
	if(lvTest->SelCount<1)return;
	lvTest->DeleteSelected();
	Edit1->Text="";
	Edit2->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TfrmPublicNodes::Button3Click(TObject *Sender)
{
	  SavePublicNodes(true);
}
//---------------------------------------------------------------------------


void __fastcall TfrmPublicNodes::Button4Click(TObject *Sender)
{
    Edit1->Text="";
	Edit2->Text="";
}
//---------------------------------------------------------------------------

