//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "TForgeJob.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TForgeJob::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TForgeJob::TForgeJob(bool CreateSuspended,TListItem *NodeItem,char *nodeurl,UnicodeString pkey)
	: TThread(CreateSuspended)
{
	if(NodeItem==NULL)return;
	nodeitem=NodeItem;
	publickey=pkey;
	url=nodeurl;
	liskapi=new LiskAPI(url);
    this->FreeOnTerminate=true;
}
//---------------------------------------------------------------------------
void __fastcall TForgeJob::Execute()
{
	//---- Place thread code here ----

	char *data=NULL;
    if(nodeitem==NULL)return;
	while(!this->Terminated){

		try{
			data=liskapi->ForgingStatu(AnsiString(publickey).c_str());
            if(data!=NULL)
			{
			   TlkJSONobject *	jo=(TlkJSONobject *)TlkJSON::ParseText(UnicodeString(data));
			   if(jo->getBoolean("success"))
				{
					nodeitem->Checked=jo->getBoolean("enabled");
				}
				jo->Free();
			}
			data=liskapi->SyncStatus();
			if(data!=NULL)
			{
			   TlkJSONobject *	jo=(TlkJSONobject *)TlkJSON::ParseText(UnicodeString(data));
				if(jo->getBoolean("success"))
				{
				  nodeitem->SubItems->Strings[1]=IntToStr(jo->getInt("height"));
				  nodeitem->SubItems->Strings[2]=jo->getString("broadhash");
				  nodeitem->SubItems->Strings[3]=IntToStr(jo->getInt("consensus"));
				  if(jo->getBoolean("syncing"))
					  nodeitem->SubItems->Strings[4]="Syncing";
				  else
					  nodeitem->SubItems->Strings[4]="Synced";
				}
                jo->Free();
			 }
		}catch(...)
		{

		}



	   Sleep(3000);
	}
}
//---------------------------------------------------------------------------
__fastcall TForgeJob::~TForgeJob()
{
      if(liskapi)liskapi->~LiskAPI();
}
