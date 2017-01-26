//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmdlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "forgeframe"
#pragma link "frameDelegate"
#pragma resource "*.dfm"
TfrmDlgdashbrd *frmDlgdashbrd;
TffrmServers *ffrmsvr_main=NULL;
TffrmServers *ffrmsvr_test=NULL;
TframDelegate *ffrmdelegate=NULL;
//---------------------------------------------------------------------------
__fastcall TfrmDlgdashbrd::TfrmDlgdashbrd(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgdashbrd::FormCreate(TObject *Sender)
{
	ffrmsvr_test=new TffrmServers(Panel2,true);
	ffrmsvr_test->Name="ffrmsvr_test";
	ffrmsvr_test->Parent=Panel2;
	ffrmsvr_test->Align=alTop;
 	UnicodeString username=ffrmsvr_test->LoadDelegateInfo();
	ffrmsvr_test->LoadPublicNodes();

	ffrmdelegate=new TframDelegate(Panel2,true,username);
	ffrmdelegate->Name="ffrmdelegate_test";
	ffrmdelegate->Align=alClient;
    ffrmdelegate->Parent=Panel2;



	ffrmsvr_main=new TffrmServers(Panel1,false);
	ffrmsvr_main->Name="ffrmsvr_main";
	ffrmsvr_main->Parent=Panel1;
	ffrmsvr_main->Align=alTop;
	username=ffrmsvr_main->LoadDelegateInfo();
	ffrmsvr_main->LoadPublicNodes();

	ffrmdelegate=new TframDelegate(Panel1,false,username);
	ffrmdelegate->Name="ffrmdelegate_main";
	ffrmdelegate->Parent=Panel1;
	ffrmdelegate->Align=alClient;



}

//---------------------------------------------------------------------------
void __fastcall TfrmDlgdashbrd::FormClose(TObject *Sender, TCloseAction &Action)
{
			try{
			ffrmsvr_main->StopJobs();
			ffrmsvr_test->StopJobs();
			Action=caFree;
            }catch(...){}
}
//---------------------------------------------------------------------------
