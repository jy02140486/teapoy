#include "app.h"
#include "time.h"

void T_App::loop()
{
	if (running)		
	{
		bgr->Update();
	}

	mpphytester->getEntities()->updater();
   
	time_t Btime;

	time(&Btime);

	if (Btime-Atime>1/33)
	{
		double i=Btime-Atime;
		CL_Console::write_line("%1",slider_vertical->get_position());
		CL_Console::write_line("%1",1.0f/mpphytester->timeStep);

		time(&Atime);	
		CL_KeepAlive::process();
	}
}
