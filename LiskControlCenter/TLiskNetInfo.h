//---------------------------------------------------------------------------

#ifndef TLiskNetInfoH
#define TLiskNetInfoH
//---------------------------------------------------------------------------
#include "frmMain.h"
#include "LiskAPI.h"
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TLiskNetInfo : public TThread
{
private:
	char *nodeurl;
	TMainFrm *mainfrm;
    LiskAPI *liskapi;
protected:
	void __fastcall Execute();
public:
	__fastcall TLiskNetInfo(bool CreateSuspended,char *liskurl,TMainFrm *frm);
    __fastcall ~TLiskNetInfo();
};
//---------------------------------------------------------------------------
#endif
