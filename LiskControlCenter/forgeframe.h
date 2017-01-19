//---------------------------------------------------------------------------

#ifndef forgeframeH
#define forgeframeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "ulkJSON.hpp"
//---------------------------------------------------------------------------
class TffrmServers : public TFrame
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TListView *lv;
	void __fastcall lvAdvancedCustomDrawItem(TCustomListView *Sender, TListItem *Item,
          TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw);

private:	// User declarations
    void __fastcall (__closure *enumfuc)(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
	bool testnet;
	void __fastcall enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
	UnicodeString username;
	UnicodeString publickey;
    UnicodeString address;
 public:		// User declarations
	__fastcall TffrmServers(TComponent* Owner,bool isTestNet);
    void __fastcall StopJobs();
	void __fastcall LoadPublicNodes();
	void __fastcall LoadDelegateInfo();
};
//---------------------------------------------------------------------------
extern PACKAGE TffrmServers *ffrmServers;
//---------------------------------------------------------------------------
#endif
