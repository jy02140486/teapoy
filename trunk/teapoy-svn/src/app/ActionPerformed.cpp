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

void T_App::OnbuttonGrdClick()
{
	   if (!addground->window->is_visible())
	   {
		   addground->window->set_visible(true);

	   }
	   else
	   addground->window->set_visible(false);

	   CL_Console::write_line("");
 
}

void T_App::OnAddGround()
{
	b2BodyDef bodydef;
	bodydef.type=b2_staticBody;
	
	int x=abs((addground->vertices[0].x-addground->vertices[1].x)/2);

	int y =abs((addground->vertices[0].y-addground->vertices[1].y)/2);

	bodydef.position.Set(x,y);

	b2Body *body=mpphytester->world->CreateBody(&bodydef);

	b2PolygonShape shape;
	
	b2Vec2 p1(abs(addground->vertices[0].x-x),abs(addground->vertices[0].y-y));
	b2Vec2 p2(abs(addground->vertices[1].x-x),abs(addground->vertices[1].y-y));

	shape.SetAsEdge(p1,p2) ;
	body->CreateFixture(&shape,0.0f);

// 	  CL_Console::write_line("former:%1",addground->cur);
// 
// 	  CL_Console::write_line("later:%1",addground->cur);
//  
// 	  b2BodyDef bodyDef;
// 	  bodyDef.type = b2_staticBody;
// 	  bodyDef.position.Set(180.0f, 40.0f);
// 
// 	  b2Body *body=mpphytester->world->CreateBody(&bodyDef);
// 	  body->CreateFixture(&shapedef,8.0f);
	 addground->setActivated(false);
}

