//---------------------------------------------------------------------------

#ifndef frameDelegateH
#define frameDelegateH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "LiskApi.h"
#include "ulkJSON.hpp"
#include <System.Notification.hpp>
//---------------------------------------------------------------------------
class TframDelegate : public TFrame
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label3;
	TEdit *ed_pkey;
	TEdit *ed_address;
	TLabel *Label2;
	TLabel *Label1;
	TLabel *lb_name;
	TLabel *lb_rank;
	TPanel *Panel1;
	TGroupBox *GroupBox2;
	TLabel *lb_votes;
	TLabel *lb_appr;
	TGroupBox *GroupBox3;
	TProgressBar *pbar;
	TLabel *label11;
	TLabel *lb_pblocks;
	TLabel *Label5;
	TLabel *lb_missed;
	TTimer *Timer1;
	TLabel *lb_pos;
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	char * NodeUrl;
	LiskAPI *liskapi;
    void __fastcall enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
public:		// User declarations
	__fastcall TframDelegate(TComponent* Owner,char* nodeurl);
	void	__fastcall TframDelegate::Reload();
};
//---------------------------------------------------------------------------
extern PACKAGE TframDelegate *framDelegate;
//---------------------------------------------------------------------------
#endif
