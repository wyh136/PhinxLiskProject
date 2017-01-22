//---------------------------------------------------------------------------

#include <vcl.h>
#include "TLiskNetInfo.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainFrm *MainFrm;
TfrmPublicNodes *frmPnodes=NULL;
TLiskNetInfo *lisknetinfo=NULL;
TfrmDlgdashbrd *frmdlg=NULL;
TfrmSpeedTest *frmspeed=NULL;
HWND MainFrmHand;
UnicodeString MAIN_PUBLIC_NODE;
UnicodeString TEST_PUBLIC_NODE;
//---------------------------------------------------------------------------
TForm* __fastcall TMainFrm::FormExist(UnicodeString szCaption)
{
        //遍历主窗体的子窗体
		for(int i=0;i<this->MDIChildCount;i++)
        {
				TForm *pForm=this->MDIChildren[i];
                if(pForm->Caption==szCaption)
                        return pForm;//如果窗体存在，返回窗体指针
        }
        return NULL;//如果不存在返回NULL
}
//---------------------------------------------------------------------------
__fastcall TMainFrm::TMainFrm(TComponent* Owner)
	: TForm(Owner)
{
    MainFrmHand=this->Handle;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::FormCreate(TObject *Sender)
{
	LoadConfig();
	lisknetinfo=new TLiskNetInfo(false,false,MainFrm);

}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::FormDestroy(TObject *Sender)
{
	if(lisknetinfo){
		lisknetinfo->Terminate();
	}
}
//---------------------------------------------------------------------------




void __fastcall TMainFrm::mn_pubnodesClick(TObject *Sender)
{
	 frmPnodes=(TfrmPublicNodes *)FormExist("Public Nodes Editor");
	 if(frmPnodes==NULL){
		frmPnodes=new  TfrmPublicNodes(MainFrm);
		frmPnodes->Caption="Public Nodes Editor";
	  }else{
		 frmPnodes->SetFocus();
	  }
	 frmPnodes->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainFrm::ForgingDashboard1Click(TObject *Sender)
{


	  frmdlg=(TfrmDlgdashbrd *)FormExist("Delegater DashBoard");
	 if(frmdlg==NULL){
		frmdlg=new  TfrmDlgdashbrd(MainFrm);
		frmdlg->Caption="Delegater DashBoard";
	  }else{
		 frmdlg->SetFocus();
	  }
	 frmdlg->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainFrm::FormClose(TObject *Sender, TCloseAction &Action)
{
	   for(int i=0;i<this->MDIChildCount;i++)
	   {
            this->MDIChildren[i]->Close();
	   }
	   ticon->Visible=false;
       ticon->Free();
}
//---------------------------------------------------------------------------


void __fastcall TMainFrm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(Application->MessageBoxW(L"Do you want minimized window?",L"Appliction Notice",MB_YESNO)==IDYES)
	{
		ticon->Visible=true;
		ticon->BalloonHint="I'm here,and keep working!";
		ticon->BalloonTitle="Lisk Dashboard";
		ticon->ShowBalloonHint();
		CanClose=false;
		this->Hide();
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::ticonDblClick(TObject *Sender)
{
	this->Show();
    this->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TMainFrm::NotifyEvent(TMessage &Message)
{
	switch(Message.Msg)
	{
		case WM_FORGE_GOTBLOCK:ShowNotify("New Block Forged! ","Forge Notification"); break;
		case WM_FORGE_MISSBLOCK:ShowNotify("You have missed a block..","Forge Notification"); break;
		case WM_FORGE_SEVER_OFFLINE:ShowNotify("You server seems like offline..","Server Notification"); break;
		case WM_FORGE_SEVER_ONLINE:ShowNotify("You server online now","Server Notification"); break;
		case WM_VOTES_INCOMING:ShowNotify("You recieve a new vote!","Votes Notification"); break;
		case WM_VOTES_REMOVE:ShowNotify("You lost a vote!","Votes Notification"); break;
		case WM_BALANCE_INCOMING:ShowNotify("Lisk recieved!","BALANCE Notification");break;
		case WM_BALANCE_SENDOUT:ShowNotify("Lisk sent out!","BALANCE Notification");break;
	}
}

void __fastcall TMainFrm::NodeApply(TMessage &Message)
{
   switch(Message.Msg)
	{
		case WM_NODE_APPLY:ApplyNewNodes();break;
    }
}
void __fastcall TMainFrm::ShowNotify(UnicodeString text,UnicodeString title)
{
		ticon->Visible=true;
		ticon->BalloonHint=text;
		ticon->BalloonTitle=title;
		ticon->ShowBalloonHint();

}


void __fastcall TMainFrm::ApplyNewNodes()
{
     TForm *form=(TForm *)FormExist("Delegater DashBoard");
	 if(form)form->Close();
	 LoadConfig();
     if(lisknetinfo)lisknetinfo->Terminate();
	 lisknetinfo=new TLiskNetInfo(false,false,MainFrm);
     ShowNotify("Connected to the Best node","Best Node");

}

void __fastcall TMainFrm::LoadConfig()
{

	UnicodeString path=ExtractFileDir(ParamStr(0))+"\\config.json";
	TStringList *ss=new TStringList();
	ss->Clear();
	try{
		ss->LoadFromFile(path);
	}catch(...)
	{
		ss->Text="{}";
	}
	TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(ss->Text);
	TlkJSONobject *node=(TlkJSONobject *)json->Field["servers"];
	MAIN_PUBLIC_NODE=node->getString("mainnet");
	TEST_PUBLIC_NODE=node->getString("testnet");
	delete ss;
    json->Free();

}


void __fastcall TMainFrm::SpeedTest1Click(TObject *Sender)
{
	 frmspeed=(TfrmSpeedTest *)FormExist("Public Node Speed Testing");
	 if(frmspeed==NULL){
		frmspeed=new  TfrmSpeedTest(MainFrm);
		frmspeed->Caption="Public Node Speed Testing";
	  }else{
		 frmspeed->SetFocus();
	  }
	 frmspeed->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::VotesManager1Click(TObject *Sender)
{
      //todo
}
//---------------------------------------------------------------------------

