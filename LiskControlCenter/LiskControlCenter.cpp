//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("frameDelegate.cpp", framDelegate); /* TFrame: File Type */
USEFORM("forgeframe.cpp", ffrmServers); /* TFrame: File Type */
USEFORM("cfrmPublicNodes.cpp", frmPublicNodes);
USEFORM("frmdlg.cpp", frmDlgdashbrd);
USEFORM("frmSpeed.cpp", frmSpeedTest);
USEFORM("frmMain.cpp", MainFrm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Cobalt XEMedia");
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
