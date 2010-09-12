#include "app.h"
#include "../entities/querryback.h"

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

	//ops of editing scene
	if (edit->isActivated()&&edit->bodyref!=NULL)
	{
		edit->bodyref->SetAwake(false);

		edit->bodyref=NULL;
	}
		// 	}
// 	if (edit->isActivated())
// 	{
// 		for(b2Body* temp=mpphytester->world->GetBodyList();temp!=NULL;temp=temp->GetNext())
// 			temp->SetAwake(false);
// 
// 		edit->bodyref=  body;
// 		return;
// 	}
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

	b2Vec2 m_mouseWorld (mMouse.get_x(),mMouse.get_y());

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

		//ops of editing scene
		if (edit->isActivated())
		{
			for(b2Body* temp=mpphytester->world->GetBodyList();temp!=NULL;temp=temp->GetNext())
				temp->SetAwake(false);

			edit->bodyref=  body;
// 			return;
		}

		if (!addjoint->isActivated())
		{
			mpphytester->mjd.bodyA = mpphytester->groundBody;
			mpphytester->mjd.bodyB = body;
			mpphytester->mjd.target = m_mouseWorld;
			mpphytester->mjd.maxForce = 1000.0f * body->GetMass();
	
			mpphytester->mj = (b2MouseJoint*)mpphytester->world->CreateJoint(&mpphytester->mjd);
	
			body->SetAwake(true);
			}
		else
		{
			addjoint->ConnectBody(body,body->GetPosition());
		}
	}

 //ops of adding groundbody
	if (addground->isActivated())
	{
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
	//ÅäÖÃÊÂ¼þ²å²Û
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
