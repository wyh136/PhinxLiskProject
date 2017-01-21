//---------------------------------------------------------------------------

#ifndef frmSpeedH
#define frmSpeedH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "TSpeedTest.h"
#include "ulkJSON.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "mymsg.h"
//---------------------------------------------------------------------------
class TfrmSpeedTest : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TListView *lv;
	TMemo *Memo1;
	TGroupBox *GroupBox2;
	TTimer *Timer1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
    void __fastcall LoadPublicNodes(bool isTestNet);
    void __fastcall enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
public:		// User declarations
	__fastcall TfrmSpeedTest(TComponent* Owner);
	void __fastcall StartTest();
	void __fastcall OnFinished(TListItem *item,int state);
    void __fastcall SaveBestNodes();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSpeedTest *frmSpeedTest;
//---------------------------------------------------------------------------
#endif