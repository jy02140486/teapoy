#include "app.h"

T_App::T_App()
{
	/* code */
}

int T_App::start()
{
	if (init() == false)
	{
		return -1;
	}

	while (!mQuit)
	{
		loop();
		render();
	}

	mpConsole->display_close_message();
	return 0;
}
