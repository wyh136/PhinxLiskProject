//---------------------------------------------------------------------------

#ifndef TForgeJobH
#define TForgeJobH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "LiskAPI.h"
#include "forgeframe.h"
#include "ulkJSON.hpp"
//---------------------------------------------------------------------------
class TForgeJob : public TThread
{
private:
	TListItem *nodeitem;
	LiskAPI *liskapi;
	char *url;
    UnicodeString publickey;
protected:
	void __fastcall Execute();
public:
	__fastcall TForgeJob(bool CreateSuspended,TListItem *NodeItem,char *nodeurl,UnicodeString pkey);
	 __fastcall ~TForgeJob();
};
//---------------------------------------------------------------------------
#endif
