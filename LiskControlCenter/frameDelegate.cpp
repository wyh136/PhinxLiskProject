//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "frameDelegate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TframDelegate *framDelegate;
int pos=-1,old_forged=0,old_missed=0;
void __fastcall TframDelegate::enumlist(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue)
{
	pos++;
	TlkJSONstring *v=(TlkJSONstring *)Elem;
	UnicodeString *pkey=(UnicodeString *)data;
	if(v->Value.operator UnicodeString()==*pkey)
	{
		lb_pos->Caption="forging position : "+IntToStr(pos);
		Continue=false;
		return;
	}
	if(pos>19){
        lb_pos->Caption="forging position : > 20";
	}
	Continue=true;


}
//---------------------------------------------------------------------------
void __fastcall TframDelegate::Reload()
{
	UnicodeString data="";
	try{
		data=UnicodeString(liskapi->GetDelegateByName("phinx"));
	}catch(...)
	{
        return;
	}
	UnicodeString pkey="";

	if(data!=""){
		TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(data);
		if(json->getBoolean("success"))
		{

			TlkJSONobject *jo=(TlkJSONobject *)json->Field["delegate"];
			float vote=jo->Field["vote"]->Value.operator unsigned __int64() / 100000000000000.0;
			lb_name->Caption=jo->getString("username");
			lb_rank->Caption=IntToStr(jo->getInt("rate"));
			ed_address->Text=jo->getString("address");
			ed_pkey->Text=jo->getString("publicKey");
			pkey=jo->getString("publicKey");
			lb_votes->Caption=FormatFloat("00.00",vote);
			lb_appr->Caption=FloatToStr(jo->getDouble("approval"))+" %";
			lb_pblocks->Caption=IntToStr(jo->getInt("producedblocks"));
			if(old_forged<jo->getInt("producedblocks")&&old_forged>0){
               lb_pos->Caption="New Block has Forged!";
			   old_forged=jo->getInt("producedblocks");
			}
			lb_missed->Caption=IntToStr(jo->getInt("missedblocks"));
			if(old_missed<jo->getInt("missedblocks")&&old_missed>0){
				lb_pos->Caption="A Block has Missed!";
				old_missed=jo->getInt("missedblocks");
			}
			pbar->Position=jo->getInt("productivity");

		}
		json->Free();
	}
	data=UnicodeString(liskapi->GetNextForgers(20));
	if(data!=""&&pkey!=""){
		pos=0 ;
		TlkJSONobject *json=(TlkJSONobject *)TlkJSON::ParseText(data);

		if(json->getBoolean("success"))
		{
			TlkJSONlist *nodes=(TlkJSONlist *)json->Field["delegates"];
			nodes->ForEach(enumlist,&pkey);
		}
        json->Free();

	}


}
__fastcall TframDelegate::TframDelegate(TComponent* Owner,char* nodeurl)
	: TFrame(Owner)
{
	NodeUrl=nodeurl;
	liskapi=new LiskAPI(NodeUrl);
 }

//---------------------------------------------------------------------------
void __fastcall TframDelegate::Timer1Timer(TObject *Sender)
{
	Reload();
}
//---------------------------------------------------------------------------

