#include "app.h"

T_App::T_App()
{
	/* code */
}

int T_App::start()
{
	if (init() == false)
	{
		return -1;
	}

	while (!mQuit)
	{
		mGui.exec(false);
		loop();
	}

	return 0;
}

void T_App::msgHandling()
{

}

void T_App::onMouseUp(const CL_InputEvent &, const CL_InputState &)
{
	 
}

void T_App::onMouseDown(const CL_InputEvent &, const CL_InputState &)
{
//  	mpphytester->phyentity::Push(SM_MOUSEDOWN);
// 	mpDisplayWindow->get_gc().clear(CL_Colorf::red);
}

void T_App::onMouseMove(const CL_InputEvent &, const CL_InputState &)
{

}
// void T_App::onMouseMove(const CL_InputEvent &, const CL_InputState &)
// {
// 	if (mMouse.get_keycode(0))
// 	{
// 		b2Vec2 pos(mMouse.get_x(),mMouse.get_y());
// 		mpphytester->mjd.target.Set(pos.x,pos.y);
// 	}
// }	

