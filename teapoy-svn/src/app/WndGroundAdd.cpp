#include "WndGroundAdd.h"


WndGroundAdd::WndGroundAdd(void)
{
	cur=0;
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
	  	 window->set_visible(flag);
		 cur=-1;
}

void WndGroundAdd::AddVertex(b2Vec2 pos)
{
	  if (cur==0)
	  {
		  vertices[cur]=pos;
		  cur=1;
	  }
	   else	 if(cur==1)
	   { 
		   vertices[cur]=pos;
		   cur=0;
	  }
	  else
	  {	  cur=0;
		  vertices[cur]=pos;
	   }
}

void WndGroundAdd::draw(CL_GraphicContext *gc)
{
	if (cur==-1)
	{
		return;
	}
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