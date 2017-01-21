//---------------------------------------------------------------------------

#ifndef TSpeedTestH
#define TSpeedTestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "LiskApi.h"
#include "ulkJSON.hpp"
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TOnFinished)(TListItem *item,int state);
class TSpeedTest : public TThread
{
private:
	LiskAPI *liskapi;
	TListItem *Item;
protected:
	void __fastcall Execute();
	void __fastcall DoFinished(TListItem *item,int state);
public:
	__fastcall TSpeedTest(bool CreateSuspended,TListItem *item);
	TOnFinished OnFinished;
};
//---------------------------------------------------------------------------
#endif
