//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("forgeframe.cpp", ffrmServers); /* TFrame: File Type */
USEFORM("frameDelegate.cpp", framDelegate); /* TFrame: File Type */
USEFORM("cfrmPublicNodes.cpp", frmPublicNodes);
USEFORM("frmdlg.cpp", frmDlgdashbrd);
USEFORM("frmvotesmgr.cpp", frmVotes);
USEFORM("frmMain.cpp", MainFrm);
USEFORM("frmSpeed.cpp", frmSpeedTest);
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
