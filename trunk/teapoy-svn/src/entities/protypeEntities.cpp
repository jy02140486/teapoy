#include "protypeEntities.h"


#define M_PI       3.14159265358979323846


void phyentity::Initialize()
{

	b2Vec2 gravity(0.0f, 10.0f);
	world=new b2World(gravity,true);
	
	timeStep = 480.0f;
	velocityIterations = 10;
	positionIterations = 6;

	
	aabb.lowerBound.Set(-1.0f, -400.0f);
	aabb.upperBound.Set(1.0f, 1.0f);

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(180.0f, 40.0f);
	
	bodyDef.allowSleep=false;

	worldAxis.Set(1.0f, 0.0f);
	
	groundBodyDef.angle=0.0f;
	groundBodyDef.active=true;
	groundBodyDef.type=b2_staticBody;
	groundBodyDef.position.Set(10.0f,400.0f)	;

	groundBody = world->CreateBody(&groundBodyDef);



	setConvexVertex(&shapedef,4,20);

 	groundBox.SetAsEdge(b2Vec2(0.0f,0.0f),b2Vec2(600.0f,0.0f));

	groundBody->CreateFixture(&groundBox,0.0f);
	groundBody->GetFixtureList()->SetFriction(0.0f);
	groundBody->GetFixtureList()->SetRestitution(0.1f);

	mj=NULL;

}

phyentity::~phyentity()
{
 
}


void phyentity::draw(CL_GraphicContext &gc)
{
 	CL_Gradient color(CL_Colorf::mediumspringgreen, CL_Colorf::honeydew);

	for (b2Body* bbbb=world->GetBodyList();bbbb!=NULL;bbbb=bbbb->GetNext())
	{
		if (bbbb->GetFixtureList()->GetShape()->GetType()!=shapedef.e_circle)
			drawbox(&gc,bbbb);
		else
			DrawCircle(&gc,bbbb);
		
	}
	DrawJoints(&gc);
}

void phyentity::updater()
{
	world->Step(1.0f / timeStep,velocityIterations,positionIterations);
	
}


//DrawBodies
void phyentity::drawbox(CL_GraphicContext *gc,b2Body *bodyref)
{
	b2PolygonShape* shape=(b2PolygonShape*)bodyref->GetFixtureList()->GetShape();


	CL_Vec4f red_color(1.0f, 0.0f, 0.0f, 1.0f);
	CL_Vec4f green_color(0.0f, 1.0f, 0.0f, 1.0f);
	CL_Vec4f black_color(0.0f, 0.0f,0.0f, 1.0f);

	

	const int vn=shape->GetVertexCount();
	CL_Vec2i positions[8];
	CL_Vec4f colors[] = { red_color, green_color,red_color, green_color,red_color, green_color,red_color, green_color};
	CL_Vec4f ground[]={black_color,black_color,black_color,black_color,black_color,black_color,black_color,black_color};


	float32 angle=b2_pi/shape->m_vertexCount;
	
	b2Transform tmptf=bodyref->GetTransform();
	b2Vec2 tmpvec;

	for (int i=0;i<vn;i++)
	{
		tmpvec=b2Mul(tmptf,shape->GetVertex(i));
		positions[i]=CL_Vec2f(tmpvec.x,tmpvec.y);	
	}


	CL_PrimitivesArray vecs(*gc);

	vecs.set_attributes(0,positions);


	if (bodyref->GetType()==b2_dynamicBody)
		vecs.set_attributes(1,colors);
	else
		vecs.set_attributes(1,ground);
										
	gc->set_program_object(cl_program_color_only);
	gc->draw_primitives(cl_line_loop,vn,vecs);
}


void phyentity::DrawCircle(CL_GraphicContext *gc,b2Body *bodyref)
{
// 	CL_Gradient color2(CL_Colorf::burlywood, CL_Colorf::honeydew);

	CL_Draw::circle(*gc,
		bodyref->GetPosition().x,
		bodyref->GetPosition().y,
		bodyref->GetFixtureList()->GetShape()->m_radius,
		CL_Colorf::blueviolet);
}

void phyentity::DrawJoints(CL_GraphicContext *gc)
{
	CL_Vec2i positions[2];

	CL_PrimitivesArray vecs(*gc);

	CL_Vec4f red_color(1.0f, 0.0f, 0.0f, 1.0f);

	CL_Vec4f joints[]={red_color,red_color,red_color,red_color,red_color,red_color,red_color,red_color};

	  for(b2Joint *jref=world->GetJointList();jref!=NULL;jref=jref->GetNext())
	  {

		  positions[0]=CL_Vec2f(jref->GetAnchorA().x,jref->GetAnchorA().y);		  
		  positions[1]=CL_Vec2f(jref->GetAnchorB().x,jref->GetAnchorB().y);

		  vecs.set_attributes(0,positions);
		  vecs.set_attributes(1,joints);

		  gc->set_program_object(cl_program_color_only);
		  gc->draw_primitives(cl_lines,2,vecs);

	  }


}

//set vertexes Attributes
void phyentity::setConvexVertex(b2PolygonShape *shapeDef,int n,float32 radius) 

   {  
	   shapeDef->m_vertexCount = n;  

	   float32 Pi=M_PI;

	   float32 angle=Pi * 2 / n;  

	   float32 dx,dy;

	   for (int i= 0; i < n;i++ )  
	   {  
		   dx = radius * cos(angle * i-angle/2);  
		   dy = radius *sin(angle * i-angle/2);  
		   shapeDef->m_vertices[i].Set(dx,dy);  

		   CL_Console::write_line("v%1 x=%2 y=%3",i,dx,dy);
	   }  


	   shapeDef->Set(shapeDef->m_vertices,n);
	//  shapeDef->m_radius=radius;
}  

//AddBody For Debuging
void phyentity::AddBodyTemp()
{
	  b2Body *body=world->CreateBody(&bodyDef);
	  body->CreateFixture(&shapedef,8.0f);
}
