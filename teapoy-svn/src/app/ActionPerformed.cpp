#include "app.h"
#include "event.h"

void T_App::OnButton1click()
{
	 mpphytester->AddBodyTemp();
}

void T_App::OnSliderMove()
{
	//		  mpphytester->velocityIterations=slider_vertical->get_position();
	mpphytester->timeStep=slider_vertical->get_position();
}