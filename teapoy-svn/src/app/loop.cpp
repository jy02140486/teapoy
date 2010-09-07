#include "app.h"

void T_App::loop()
{
	if (running)		
	{
		mpphytester->getEntities()->updater();
	}
	bgr->Update();

	CL_KeepAlive::process();

	mGui.exec(false);
}
