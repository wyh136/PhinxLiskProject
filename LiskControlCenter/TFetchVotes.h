//---------------------------------------------------------------------------

#ifndef TFetchVotesH
#define TFetchVotesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "mymsg.h"
#include "ulkJSON.hpp"
#include "LiskApi.h"
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *FOnVoters)(int count,TThreadList *voters);
class TFetchVotes : public TThread
{
private:
	LiskAPI *liskapi;
	bool TestNet;
	UnicodeString username;
	UnicodeString publickey;
    TListItems *Items;
	void __fastcall (__closure *enumfuc)(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
	void __fastcall DoOnVoters(int count,TThreadList *voters);
	void __fastcall enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);
protected:
	void __fastcall Execute();
public:
	__fastcall TFetchVotes(bool CreateSuspended,bool isTestNet,TListItems *items);
    FOnVoters OnVoters;
};
//---------------------------------------------------------------------------
#endif
