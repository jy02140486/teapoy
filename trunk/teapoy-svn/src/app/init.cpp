#include "app.h"

bool T_App::init()
{
	try
	{
	//initail window description
	mWinDesc.set_title("Teapoy");
	mWinDesc.set_allow_resize(true);
	mWinDesc.set_size(CL_Size (800, 600), false);
	//resource directory
	CL_String8 resource = "../../resource/GUITheme/resources.xml";
	CL_String8 theme = "../../resource/GUITheme/theme.css";
	
	//initail resource manager
	mResManager.load(resource);

	//initail gui theme
	mGUITheme.set_resources(mResManager);

	//initail gui
	mpDisplayWindow = new CL_DisplayWindow(mWinDesc);
	mpWinManager = new CL_GUIWindowManagerTexture(*mpDisplayWindow);
	mGui.set_window_manager(*mpWinManager);
	mGui.set_theme(mGUITheme);
	mGui.set_css_document(theme);

	//initail console window
	mpConsole = new CL_ConsoleWindow("Console", 80, 100);

	//initail events
	mInput = mpDisplayWindow->get_ic();
	mKeyboard = mInput.get_keyboard();
	mMouse = mInput.get_mouse();
	//mJoystick = mInput.get_joystick();
	
	}
	catch (CL_Exception &exception)
	{
		CL_Console::write_line("Exception",
			exception.get_message_and_stack_trace());
		mpConsole->display_close_message();
		return false;
	}

	eventInit();
	return true;
}


