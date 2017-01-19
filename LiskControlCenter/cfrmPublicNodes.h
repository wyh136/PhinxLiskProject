//---------------------------------------------------------------------------

#ifndef cfrmPublicNodesH
#define cfrmPublicNodesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include "ulkJSON.hpp"
#include "TPublicNodeWatcher.h"
//---------------------------------------------------------------------------
class TfrmPublicNodes : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TListView *lvMain;
	TListView *lvTest;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TEdit *edt_owner;
	TLabel *Label2;
	TEdit *edt_url;
	TButton *bt_new;
	TButton *bt_del;
	TButton *bt_save;
	TButton *bt_Cancel;
	TGroupBox *GroupBox2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall lvMainSelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall lvTestSelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall bt_newClick(TObject *Sender);
	void __fastcall bt_delClick(TObject *Sender);
	void __fastcall bt_CancelClick(TObject *Sender);
	void __fastcall bt_saveClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);


private:	// User declarations
	void __fastcall LoadPublicNodes(bool isTestNet);
    void __fastcall SavePublicNodes(bool isTestNet);
	void __fastcall enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
public:		// User declarations
	__fastcall TfrmPublicNodes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPublicNodes *frmPublicNodes;
//---------------------------------------------------------------------------
#endif
