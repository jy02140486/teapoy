#include "app.h"

void T_App::render()
{
	mpDisplayWindow->flip();
	mGui.exec(false);
}
