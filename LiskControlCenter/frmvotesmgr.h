//---------------------------------------------------------------------------

#ifndef frmvotesmgrH
#define frmvotesmgrH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TFetchVotes.cpp"
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmVotes : public TForm
{
__published:	// IDE-managed Components
	TListView *lv;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	TFetchVotes *tfv;
	void __fastcall OnVoters(int count,TThreadList *voters);
public:		// User declarations
	__fastcall TfrmVotes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmVotes *frmVotes;
//---------------------------------------------------------------------------
#endif
