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

}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::FormCreate(TObject *Sender)
{
	lisknetinfo=new TLiskNetInfo(false,"https://login.lisk.asia:2443",MainFrm);

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

	  if(frmdlg==NULL)frmdlg=new  TfrmDlgdashbrd(MainFrm);
	  frmdlg->Show();

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


