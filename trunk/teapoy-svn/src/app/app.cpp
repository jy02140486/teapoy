#include "app.h"

T_App::T_App() : mQuit(false)
{
	/* code */
}

int T_App::start()
{
	if (init() == false)
	{
		return 0;
	}

	while (!mQuit)
	{
		event();
		loop();
		render();
	}

	mpConsole->display_close_message();
	return 0;
}

void T_App::closeWindow()
{
	mQuit = true;
}
