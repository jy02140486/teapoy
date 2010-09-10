#include "app.h"

void T_App::render()
{
	mpDisplayWindow->get_gc().clear(CL_Colorf::yellowgreen);

	bgr->draw(&mpDisplayWindow->get_gc());

 	mpphytester->draw(mpDisplayWindow->get_gc());

	if (addground->isActivated())
	{
		addground->draw(&mpDisplayWindow->get_gc());
	}
	
	
	mpWinManager->draw_windows(mpDisplayWindow->get_gc());
	
	mpDisplayWindow->flip();
}
