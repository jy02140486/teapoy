#include "WndGroundAdd.h"



WndGroundAdd::WndGroundAdd(void)
{
	drawing=false;
	first=true;
}

WndGroundAdd::~WndGroundAdd(void)
{
}

void WndGroundAdd::Init(CL_GUIManager *gui,CL_DisplayWindowDescription *desc)
{
	window=new CL_Window(gui,*desc);
	window->set_visible(false);
	window->set_draggable(true);
	
	
	label=new CL_Label(window);
	label->set_geometry(CL_Rect(40, 50, CL_Size(200, 20)))	;
	label->set_text("Point two vertexes on the scr");
	
	cirfirm=new CL_PushButton(window);
	cirfirm->set_text("cirfirm");
	cirfirm->set_geometry(CL_Rect(40, 90, CL_Size(200, 20)))	 ;
}

bool WndGroundAdd::isActivated()
{
	if (window->is_visible())
	{
		return true;
	}
	else return false;
}

void WndGroundAdd::setActivated(bool flag)
{		 
		first=true;
	  	 window->set_visible(flag);
}

void WndGroundAdd::AddVertex(b2Vec2 pos,int index)
{
		  vertices[index]=pos;
}

void WndGroundAdd::OnAdd(phyentity *mpphytester)
{

	b2BodyDef bodydef;
	bodydef.type=b2_staticBody;

	int x=abs((vertices[0].x-vertices[1].x)/2);

	int y =abs((vertices[0].y-vertices[1].y)/2);

	bodydef.position.Set(vertices[0].x,vertices[0].y);

	b2Body *body=mpphytester->world->CreateBody(&bodydef);

	b2PolygonShape shape;

	b2Vec2 p(vertices[1].x-vertices[0].x,vertices[1].y-vertices[0].y);
// 	b2Vec2 p2(vertices[1].x-x),abs(vertices[0].y-y);

	shape.SetAsEdge(b2Vec2(0.0f,0.0f),p) ;
	body->CreateFixture(&shape,0.0f);

// 	setActivated(false);

}
void WndGroundAdd::draw(CL_GraphicContext *gc)
{

	CL_Vec4f black_color(0.0f, 0.0f,0.0f, 1.0f);
	CL_Vec4f ground[]={black_color,black_color};

	CL_PrimitivesArray vecs(*gc);

	CL_Vec2i positions[2];

	for (int i=0;i<2;i++)
	{
		positions[i]=CL_Vec2f(vertices[i].x,vertices[i].y);	
	}

	vecs.set_attributes(0,positions);


	vecs.set_attributes(1,ground);

	gc->set_program_object(cl_program_color_only);
	gc->draw_primitives(cl_lines,2,vecs);

}