#include "app.h"
#include "querryback.h"

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
	if (mpphytester->mj!=NULL)
	{
		mpphytester->world->DestroyJoint(mpphytester->mj);
		mpphytester->mj=NULL;
	}


	if (addground->isActivated()&&!addground->first)
	{
		b2Vec2 m_mouseWorld(mMouse.get_x(),mMouse.get_y())  ;
		addground->drawing=false;
		addground->AddVertex(m_mouseWorld,1);
		addground->OnAdd(mpphytester);
	}
}

bool T_App::isClkOnBoard(b2Vec2 pos,CL_Rect Area)
{
	CL_Vec2i temp;
	temp.x=pos.x;
	temp.y=pos.y;

	if (Area.contains(temp))
	{
		return true;
	}
 return false;
}


void T_App::onMouseDown(const CL_InputEvent &, const CL_InputState &)
{
//  	mpphytester->phyentity::Push(SM_MOUSEDOWN);
// 	mpDisplayWindow->get_gc().clear(CL_Colorf::red);
	b2Vec2 m_mouseWorld (mMouse.get_x(),mMouse.get_y());


// 	if (isClkOnBoard(m_mouseWorld,mpComWindow->get_geometry()))
// 	{
// 		return;
// 	}


	if (mpphytester->mj != NULL)
	{
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
		if (!addjoint->isActivated())
		{
			mpphytester->mjd.bodyA = mpphytester->groundBody;
			mpphytester->mjd.bodyB = body;
			mpphytester->mjd.target = m_mouseWorld;
			mpphytester->mjd.maxForce = 1000.0f * body->GetMass();
	
			//	mpphytester->mjd.frequencyHz=1/30.0f;
	
			mpphytester->mj = (b2MouseJoint*)mpphytester->world->CreateJoint(&mpphytester->mjd);
	
			body->SetAwake(true);
			}
		else
		{
			addjoint->ConnectBody(body,body->GetPosition());
		}
	}


	if (addground->isActivated())
	{
// 		if (addground->first)
// 		{
// 			addground->first=false;
// 			return;
// 		}
		addground->drawing=true;

		addground->AddVertex(m_mouseWorld,0);
	}
}

void T_App::onMouseMove(const CL_InputEvent &, const CL_InputState &)
{
	b2Vec2 m_mouseWorld (mMouse.get_x(),mMouse.get_y());

	if (mpphytester->mj)
	{
		mpphytester->mj->SetTarget(m_mouseWorld);
	}

	if (addground->isActivated()&&addground->isDrawing())
	{
		addground->vertices[1]=m_mouseWorld;
		addground->first=false;
	}
}


int T_App::eventInit()
{
	//�����¼����
	slotMouseMove = mMouse.sig_pointer_move().connect(this,
		&T_App::onMouseMove);
	slotMouseDown = mMouse.sig_key_down().connect(this,
		&T_App::onMouseDown);
	slotMouseUp=mMouse.sig_key_up().connect(this,
		&T_App::onMouseUp);
	slotKeyboardUp=mKeyboard.sig_key_up().connect(this, 
		&T_App::onKeyboardUp);

	return 0;
}

void T_App::onKeyboardUp(const CL_InputEvent &key,
						   const CL_InputState &state)
{
	if(key.id == CL_KEY_ESCAPE)
		if (mpComWindow->is_visible())
		{
			mpComWindow->set_visible(false);
		}
		else
			mpComWindow->set_visible(true);
}