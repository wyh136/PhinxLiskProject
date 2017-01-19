//---------------------------------------------------------------------------

#ifndef frmMainH
#define frmMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <ulkJSON.hpp>
#include "cfrmPublicNodes.h"
#include "frmdlg.h"
//---------------------------------------------------------------------------
class TMainFrm : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *sbar;
	TMainMenu *MM;
	TMenuItem *mm_network;
	TMenuItem *mn_pubnodes;
	TMenuItem *nm_LiskExplorers;
	TMenuItem *N1;
	TMenuItem *DisplayTestNet1;
	TMenuItem *DelegaterTools1;
	TMenuItem *ForgingDashboard1;
	TMenuItem *VotesManager1;
	TMenuItem *ReportGenerator1;
	TMenuItem *Wallet1;
	TMenuItem *OpenWallet1;
	TMenuItem *MultiSignature1;
	TMenuItem *N2;
	TMenuItem *AddressBook1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall mn_pubnodesClick(TObject *Sender);
	void __fastcall ForgingDashboard1Click(TObject *Sender);
private:	// User declarations
    TForm* __fastcall FormExist(UnicodeString szCaption);
public:		// User declarations
	__fastcall TMainFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainFrm *MainFrm;
//---------------------------------------------------------------------------
#endif
