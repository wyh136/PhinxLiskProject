//---------------------------------------------------------------------------

#ifndef TPublicNodeWatcherH
#define TPublicNodeWatcherH
//---------------------------------------------------------------------------
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include "ulkJSON.hpp"
//---------------------------------------------------------------------------
class TPublicNodeWatcher : public TThread
{
private:
	TListItems *listitems;
	TIdHTTP *http;
	TIdSSLIOHandlerSocketOpenSSL *ssl;
	TEncoding *encoding;
	void __fastcall GetStatu(TListItem *item);
protected:
	void __fastcall Execute();

public:
	__fastcall TPublicNodeWatcher(bool CreateSuspended,TListItems *items);
    __fastcall ~TPublicNodeWatcher();
};
//---------------------------------------------------------------------------
#endif
