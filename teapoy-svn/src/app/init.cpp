#include "app.h"

bool T_App::init()
{
	try
	{
	//initail window description
	mWinDesc.set_title("Teapoy");
	mWinDesc.set_allow_resize(true);
	mWinDesc.set_size(CL_Size (800, 600), false);
	//initail gui
	mpDisplayWindow = new CL_DisplayWindow(mWinDesc);
	mpWinManager = new CL_GUIWindowManagerTexture(*mpDisplayWindow);
	mGui.set_window_manager(*mpWinManager);

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


