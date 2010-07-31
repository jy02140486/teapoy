#include "app.h"

void T_App::loop()
{
	mpphytester->getEntities()->updater();

	CL_KeepAlive::process();

	mGui.exec(false);
}
