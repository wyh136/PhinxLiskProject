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
#include "frmSpeed.h"
#include <Vcl.ExtCtrls.hpp>
#include "mymsg.h"
#include "frmvotesmgr.h"
//---------------------------------------------------------------------------

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
	TMenuItem *DelegaterTools1;
	TMenuItem *ForgingDashboard1;
	TMenuItem *VotesManager1;
	TMenuItem *ReportGenerator1;
	TMenuItem *Wallet1;
	TMenuItem *OpenWallet1;
	TMenuItem *MultiSignature1;
	TMenuItem *N2;
	TMenuItem *AddressBook1;
	TTrayIcon *ticon;
	TMenuItem *SpeedTest1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall mn_pubnodesClick(TObject *Sender);
	void __fastcall ForgingDashboard1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall ticonDblClick(TObject *Sender);
	void __fastcall SpeedTest1Click(TObject *Sender);
	void __fastcall VotesManager1Click(TObject *Sender);
private:	// User declarations
	TForm* __fastcall FormExist(UnicodeString szCaption);
	void __fastcall NotifyEvent(TMessage &Message);
	void __fastcall NodeApply(TMessage &Message);
    void __fastcall ApplyNewNodes();
	void __fastcall ShowNotify(UnicodeString text,UnicodeString title);
	void __fastcall LoadConfig();
public:		// User declarations
	__fastcall TMainFrm(TComponent* Owner);
	BEGIN_MESSAGE_MAP
		MESSAGE_HANDLER(WM_FORGE_GOTBLOCK, TMessage, NotifyEvent)
		MESSAGE_HANDLER(WM_FORGE_MISSBLOCK, TMessage, NotifyEvent)
		MESSAGE_HANDLER(WM_FORGE_SEVER_OFFLINE , TMessage, NotifyEvent)
		MESSAGE_HANDLER(WM_FORGE_SEVER_ONLINE, TMessage, NotifyEvent)
		MESSAGE_HANDLER(WM_VOTES_INCOMING, TMessage, NotifyEvent)
		MESSAGE_HANDLER(WM_VOTES_REMOVE , TMessage, NotifyEvent)
		MESSAGE_HANDLER(WM_BALANCE_INCOMING, TMessage, NotifyEvent)
		MESSAGE_HANDLER(WM_BALANCE_SENDOUT , TMessage, NotifyEvent)
        MESSAGE_HANDLER(WM_NODE_APPLY , TMessage, NodeApply)
	END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TMainFrm *MainFrm;
//---------------------------------------------------------------------------
#endif


