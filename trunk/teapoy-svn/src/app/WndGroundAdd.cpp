#include "WndGroundAdd.h"


WndGroundAdd::WndGroundAdd(void)
{
}

WndGroundAdd::~WndGroundAdd(void)
{
}

void WndGroundAdd::Init(CL_GUIManager *gui,CL_DisplayWindowDescription *desc)
{
	window=new CL_Window(gui,*desc);
	window->set_visible(false);
	
	label=new CL_Label(window);
	label->set_geometry(CL_Rect(40, 50, CL_Size(200, 20)))	;
	label->set_text("Point two vertexes on the scr");
}

bool WndGroundAdd::isActivated()
{
	if (window->is_visible())
	{
		return true;
	}
	else return false;
}