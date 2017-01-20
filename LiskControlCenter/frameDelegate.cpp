//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "frameDelegate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TframDelegate *framDelegate;
int old_forged=0,old_missed=0;
__fastcall TframDelegate::~TframDelegate()
{
	if(liskapi)liskapi->~LiskAPI();
	if(tgi)tgi->Terminate();
}


__fastcall TframDelegate::TframDelegate(TComponent* Owner,char* nodeurl,bool isTest,UnicodeString username)
	: TFrame(Owner)
{
	NodeUrl=nodeurl;
	if(isTest)
	{
	   GroupBox1->Caption=" Delegater Infomation [ TestNet ]";
	}else{
       GroupBox1->Caption=" Delegater Infomation [ MainNet ]";
	}
	UserName=username;
	tgi=new TDelegateInfo(true,UserName,nodeurl);
	tgi->OnData=OnData;
	tgi->Resume();
 }

//---------------------------------------------------------------------------
void __fastcall TframDelegate::OnData(UnicodeString username,UnicodeString votes,UnicodeString rank, UnicodeString address,UnicodeString publickey,UnicodeString approval, UnicodeString producedblocks,UnicodeString missedblocks,int position ,int _pos)
{
	lb_name->Caption=username;
	lb_rank->Caption=rank;
	ed_address->Text=address;
	ed_pkey->Text=publickey;
	lb_votes->Caption=votes;
	lb_appr->Caption=approval;
	lb_pblocks->Caption=producedblocks;
			if(old_forged<producedblocks&&old_forged>0){
			   PostMessage(MainFrmHand,WM_FORGE_GOTBLOCK,StrToInt(producedblocks),0);
			   old_forged=StrToInt(producedblocks);
			}
	lb_missed->Caption=missedblocks;
			if(old_missed<missedblocks&&old_missed>0){
				PostMessage(MainFrmHand,WM_FORGE_MISSBLOCK,StrToInt(missedblocks),0);
				old_missed=StrToInt(missedblocks);
			}
	pbar->Position=position;
	if(_pos>19){
		lb_pos->Caption="forging position : > 20";
	}else{
		lb_pos->Caption="forging position : "+IntToStr(_pos);
	}
}




