#include "app.h"

void T_App::loop()
{
	if (running)		
	{
		bgr->Update();
	}

	mpphytester->getEntities()->updater();


	CL_KeepAlive::process();

	mGui.exec(false);
}
