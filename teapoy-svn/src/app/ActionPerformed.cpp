#include "app.h"
#include "event.h"

void T_App::OnButton1click()
{
// 	 mpphytester->AddBodyTemp();
	if (!WndAdd->is_visible()	  )
	{
		WndAdd->set_visible(true);
	}
	else WndAdd->set_visible(false);
}

void T_App::OnSliderMove()
{
	//		  mpphytester->velocityIterations=slider_vertical->get_position();
	mpphytester->timeStep=slider_vertical->get_position();
}

void T_App::OnAddCusBodyClick()
{
	switch(b2BodyTypelist->get_selected_item())
	{
	case 0:
		if (highth->get_text().empty()||
			width->get_text().empty()||
			mass->get_text().empty())
			;
		else{
			b2BodyDef b2d;
			b2d.type = b2_dynamicBody;
			b2d.position.Set(180.0f, 40.0f);

			b2Body *body=mpphytester->world->CreateBody(&b2d);
			b2PolygonShape shapedef;
			shapedef.SetAsBox(width->get_text_int(),highth->get_text_int()) ;
			body->CreateFixture(&shapedef,mass->get_text_float());

		}	
		break;
	case 1:
		if (R->get_text().empty()||
			mass->get_text().empty())
		;
		else{
			b2BodyDef b2d;
			b2d.type = b2_dynamicBody;
			b2d.position.Set(180.0f, 40.0f);

			b2Body *body=mpphytester->world->CreateBody(&b2d);
			b2CircleShape shapedef;
			shapedef.m_radius=R->get_text_int();
			body->CreateFixture(&shapedef,mass->get_text_float());
		}
		break;
	case 2:
	    break;
	case 3:
	    break;
	default:
	    break;
	}
	  
// CL_Console::write_line("%1",mpphytester->world->GetBodyCount());
}

void T_App::OnbuttonGrdClick()
{
	if (addground->isActivated())
	{
		addground->setActivated(false);
	}										
	else addground->setActivated(true);
}


void T_App::OnbuttonJntClick()
{
	  if (addjoint->isActivated())
	  {
		  addjoint->setActivated(false);
		  running=true;
	  }
	  else {
		  addjoint->setActivated(true);
		  running=false;
	  }
}

void T_App::OnAddJnt()
{
	b2DistanceJointDef jointDef;
	if (addjoint->bodyA)
	{
		CL_Console::write_line("a pos %1 %2",addjoint->archA.x,addjoint->archA.y);
	}
	if (addjoint->bodyB)
	{
		CL_Console::write_line("b pos %1 %2",addjoint->archB.x,addjoint->archB.y);
	}

	jointDef.Initialize(addjoint->bodyA,addjoint->bodyB,addjoint->archA,addjoint->archB);
	
// 	jointDef.length=addjoint->lenth->get_value_float();


	mpphytester->world->CreateJoint(&jointDef);

	addjoint->setActivated(false);
	running=true;
}

void T_App::OnBodyTypeChange(int value, CL_ComboBox *combobox)
{
	switch(b2BodyTypelist->get_selected_item())
	{
	case 0:
		CL_Console::write_line("1");
		mbd->set_visible(true);
		cbd->set_visible(false);
		break;
	case 1:
		CL_Console::write_line("2");
		mbd->set_visible(false);
		cbd->set_visible(true);
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}

}

void T_App::OnButtonEditClick()
{
	if (edit->isActivated())
	{
		edit->setActivated(false);
		running=true;
	}
	else{
		edit->setActivated(true);
		running=false;
	}
}