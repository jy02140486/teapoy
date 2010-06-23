#include "app.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear();
	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
	mpDisplayWindow->flip();
}
