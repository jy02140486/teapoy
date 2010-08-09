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
	  CL_Console::write_line("%1",mpphytester->world->GetBodyCount());
}