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
#include "TDelegateInfo.h"
#include "mymsg.h"
//---------------------------------------------------------------------------
class TframDelegate : public TFrame
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label3;
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
	TLabel *lb_pos;
	TLabel *lb_balance;
private:	// User declarations
	char * NodeUrl;
	bool TestNet;
	UnicodeString UserName;
	TDelegateInfo *tgi;
	LiskAPI *liskapi;
	void __fastcall OnForged(unsigned int blockcount);
    void __fastcall OnMissed(unsigned int blockcount);
	void __fastcall enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
    void __fastcall OnData(UnicodeString username,UnicodeString votes,UnicodeString rank, UnicodeString address,double balance,UnicodeString approval, unsigned int producedblocks,unsigned int missedblocks,int position ,int _pos);
	__fastcall ~TframDelegate();
public:		// User declarations
	__fastcall TframDelegate(TComponent* Owner,bool isTest,UnicodeString username);

};
//---------------------------------------------------------------------------
extern PACKAGE TframDelegate *framDelegate;
//---------------------------------------------------------------------------
#endif
