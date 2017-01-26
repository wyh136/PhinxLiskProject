//---------------------------------------------------------------------------

#ifndef frmdlgH
#define frmdlgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "forgeframe.h"
#include <Vcl.ExtCtrls.hpp>
#include "frameDelegate.h"
//---------------------------------------------------------------------------
class TfrmDlgdashbrd : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmDlgdashbrd(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDlgdashbrd *frmDlgdashbrd;
//---------------------------------------------------------------------------
#endif
