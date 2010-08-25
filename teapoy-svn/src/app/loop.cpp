#include "app.h"

void T_App::loop()
{
	if (running)		
		mpphytester->getEntities()->updater();
	

	CL_KeepAlive::process();

	mGui.exec(false);
}
