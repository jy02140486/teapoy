#include "app.h"

void T_App::event()
{
	if (mKeyboard.get_keycode(CL_KEY_ESCAPE))
	{
		mQuit = true;
	}

	CL_KeepAlive::process();
}
