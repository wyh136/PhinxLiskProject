//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("frameDelegate.cpp", framDelegate); /* TFrame: File Type */
USEFORM("frmdlg.cpp", frmDlgdashbrd);
USEFORM("cfrmPublicNodes.cpp", frmPublicNodes);
USEFORM("forgeframe.cpp", ffrmServers); /* TFrame: File Type */
USEFORM("frmvotesmgr.cpp", frmVotes);
USEFORM("frmMain.cpp", MainFrm);
USEFORM("frmSpeed.cpp", frmSpeedTest);
USEFORM("DM.cpp", dm1); /* TDataModule: File Type */
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Emerald Light Slate");
		Application->Title = "Lisk Control Center";
		Application->CreateForm(__classid(TMainFrm), &MainFrm);
		Application->CreateForm(__classid(Tdm1), &dm1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
