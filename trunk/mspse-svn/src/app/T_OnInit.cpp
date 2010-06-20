#include "TeapoyApp.h"

int TeapoyApp::OnInit()
{
	try
	{
		CL_DisplayWindow w("Hello World", 640, 480);
		window		= w;
		CL_GraphicContext g = window.get_gc();
		gc			= g;
		CL_InputDevice k = window.get_ic().get_keyboard();
		keyboard	= k;
		CL_Font f(gc, L"微软雅黑", 30);
		font		= f;

		CL_Console::write_line("初始化成功");
	}
	catch (CL_Exception &exception)
	{
		CL_Console::write_line("Exception caught: " + exception.get_message_and_stack_trace());
		console->display_close_message();

		return -1;
	}





	return 0;
}