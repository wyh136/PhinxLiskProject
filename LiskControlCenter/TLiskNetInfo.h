//---------------------------------------------------------------------------

#ifndef TLiskNetInfoH
#define TLiskNetInfoH
//---------------------------------------------------------------------------
#include "frmMain.h"
#include "LiskAPI.h"
#include "mymsg.h"
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TLiskNetInfo : public TThread
{
private:
	UnicodeString nodeurl;
	TMainFrm *mainfrm;
    LiskAPI *liskapi;
protected:
	void __fastcall Execute();
public:
	__fastcall TLiskNetInfo(bool CreateSuspended,bool isTest,TMainFrm *frm);
    __fastcall ~TLiskNetInfo();
};
//---------------------------------------------------------------------------
#endif
