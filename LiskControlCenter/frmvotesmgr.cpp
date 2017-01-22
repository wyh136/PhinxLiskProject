//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "frmvotesmgr.h"
//---------------------------------------------------------------------------

#pragma resource "*.dfm"
TfrmVotes *frmVotes;
//---------------------------------------------------------------------------
__fastcall TfrmVotes::TfrmVotes(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmVotes::FormCreate(TObject *Sender)
{
	tfv=new TFetchVotes(true,false,lv->Items);
	tfv->OnVoters=OnVoters;
    tfv->Resume();
}
//---------------------------------------------------------------------------
void __fastcall  TfrmVotes::OnVoters(int count,TThreadList *voters)
{
    //
}
void __fastcall TfrmVotes::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action=caFree;
}
//---------------------------------------------------------------------------

