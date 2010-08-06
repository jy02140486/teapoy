#include "event.h"
#include "querryback.h"

T_Event::T_Event()
{
	mQuit = false;
	

}

int T_Event::eventInit()
{
	//配置事件插槽
	slotWindowClose = mpDisplayWindow->sig_window_close().connect(this, 
		&T_Event::onExitApp);
	slotKeyboardUp = mKeyboard.sig_key_up().connect(this, 
		&T_Event::onKeyboardUp);
	slotMouseMove = mMouse.sig_pointer_move().connect(this,
		&T_Event::onMouseMove);
	slotMouseDown = mMouse.sig_key_down().connect(this,
			&T_Event::onMouseDown);
		slotMouseUp=mMouse.sig_key_up().connect(this,
		&T_Event::onMouseUp);
	


	return 0;
}





//以下为事件处理具体函数：
//-其他事件
void T_Event::onExitApp()
{
	mQuit = true;
}

//-键盘事件

void T_Event::onKeyboardUp(const CL_InputEvent &key,
						   const CL_InputState &state)
{
	if(key.id == CL_KEY_ESCAPE)
		mQuit = true;
}



//-鼠标事件
void T_Event::onMouseMove(const CL_InputEvent &key, const CL_InputState &state)
{

	b2Vec2 m_mouseWorld (mMouse.get_x(),mMouse.get_y());

	if (mpphytester->mj)
	{
		mpphytester->mj->SetTarget(m_mouseWorld);
	}

}

void T_Event::onMouseDown(const CL_InputEvent &key, const CL_InputState &state)
{
	 	
	b2Vec2 m_mouseWorld (mMouse.get_x(),mMouse.get_y());

	if (mpphytester->mj != NULL)
	{
	//
		return;
	}

	// Make a small box.
	b2AABB aabb;
	b2Vec2 d;
	d.Set(0.01f, 0.01f);
	aabb.lowerBound = m_mouseWorld - d;
	aabb.upperBound = m_mouseWorld + d;

	// Query the world for overlapping shapes.
	//declare obj
	QueryCallback callingback(m_mouseWorld);	    
	mpphytester->world->QueryAABB(&callingback, aabb);


	if (callingback.m_fixture)
	{
		b2Body* body = callingback.m_fixture->GetBody();
	//	b2MouseJointDef mpphytester->mjd;
		mpphytester->mjd.bodyA = mpphytester->groundBody;
		mpphytester->mjd.bodyB = body;
		mpphytester->mjd.target = m_mouseWorld;
		mpphytester->mjd.maxForce = 1000.0f * body->GetMass();
		
	//	mpphytester->mjd.frequencyHz=1/30.0f;

		mpphytester->mj = (b2MouseJoint*)mpphytester->world->CreateJoint(&mpphytester->mjd);
		
		body->SetAwake(true);
		CL_Console::write_line("crap");
	}

}

void T_Event::onMouseUp(const CL_InputEvent &, const CL_InputState &)
{
	if (mpphytester->mj!=NULL)
	{
		mpphytester->world->DestroyJoint(mpphytester->mj);
		mpphytester->mj=NULL;
	}
}
