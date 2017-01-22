//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "frameDelegate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TframDelegate *framDelegate;

__fastcall TframDelegate::~TframDelegate()
{   try{
	if(liskapi)liskapi->~LiskAPI();
	if(tgi)tgi->Terminate();
	}catch(...){}
}


__fastcall TframDelegate::TframDelegate(TComponent* Owner,bool isTest,UnicodeString username)
	: TFrame(Owner)
{

	if(isTest)
	{
	   NodeUrl=AnsiString(TEST_PUBLIC_NODE).c_str();
	   GroupBox1->Caption=" Delegater Infomation [ TestNet ]";
	}else{
	   NodeUrl=AnsiString(MAIN_PUBLIC_NODE).c_str();
       GroupBox1->Caption=" Delegater Infomation [ MainNet ]";
	}
	UserName=username;
	tgi=new TDelegateInfo(true,UserName,isTest);
	tgi->OnData=OnData;
	tgi->OnMissed=OnMissed;
	tgi->OnForged=OnForged;
	tgi->Resume();

 }

//---------------------------------------------------------------------------
void __fastcall TframDelegate::OnData(UnicodeString username,UnicodeString votes,UnicodeString rank, UnicodeString address,double balance,UnicodeString approval, unsigned int producedblocks,unsigned int missedblocks,int position ,int _pos)
{
	lb_name->Caption=username;
	lb_rank->Caption=rank;
	ed_address->Text=address;
	lb_balance->Caption=lb_balance->Caption.sprintf(L"%2f LSK",balance);
	lb_votes->Caption=votes;
	lb_appr->Caption=approval;
	lb_pblocks->Caption=producedblocks;
	lb_missed->Caption=missedblocks;
	pbar->Position=position;
	if(_pos>19){
		lb_pos->Caption="forging position : > 20";
	}else{
		lb_pos->Caption="forging position : "+IntToStr(_pos);
	}
}

void __fastcall TframDelegate::OnForged(unsigned int blockcount)
{
	TMessage msg;
	msg.Msg=WM_FORGE_GOTBLOCK;
	msg.WParam=blockcount;
	SendMessage(MainFrmHand,msg.Msg,msg.WParam,0);
}

void __fastcall TframDelegate::OnMissed(unsigned int blockcount)
{
    TMessage msg;
	msg.Msg=WM_FORGE_MISSBLOCK;
	msg.WParam=blockcount;
	SendMessage(MainFrmHand,msg.Msg,msg.WParam,0);
}


