//---------------------------------------------------------------------------

#ifndef TDelegateInfoH
#define TDelegateInfoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "LiskApi.h"
#include "ulkJSON.hpp"
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *FOnData)(UnicodeString username,UnicodeString votes,UnicodeString rank, UnicodeString address,double balance,UnicodeString approval, unsigned int producedblocks,unsigned int missedblocks,int position ,int _pos);
typedef void __fastcall (__closure *FOnForged)(unsigned int blockcount);
typedef void __fastcall (__closure *FOnMissed)(unsigned int blockcount);
class TDelegateInfo : public TThread
{
private:
	UnicodeString UserName;
	LiskAPI *liskapi;
    bool TestNet;
    char* NodeUrl;
	void __fastcall DoOnData(UnicodeString username,UnicodeString votes,UnicodeString rank, UnicodeString address,double balance,UnicodeString approval, unsigned int producedblocks,unsigned int missedblocks,int position ,int _pos);
	void __fastcall DoOnForged(unsigned int blockcount);
	void __fastcall DoOnMissed(unsigned int blockcount);
	void __fastcall Reload();
	void __fastcall enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
protected:

	void __fastcall Execute();
public:
    __fastcall ~TDelegateInfo();
	__fastcall TDelegateInfo(bool CreateSuspended,UnicodeString username,bool isTestNet);
	FOnData OnData;
	FOnMissed OnMissed;
    FOnForged OnForged;
};
//---------------------------------------------------------------------------
#endif
