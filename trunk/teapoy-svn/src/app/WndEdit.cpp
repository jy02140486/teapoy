#include "WndEdit.h"

void WndEdit::Init(CL_GUIManager *gui,CL_DisplayWindowDescription *desc)
{
	window=new CL_Window(gui,*desc);						 
	window->set_visible(false);
	window->set_draggable(true);


	label=new CL_Label(window);
	label->set_geometry(CL_Rect(40, 50, CL_Size(200, 20)))	;
	label->set_text("Edit current scene now");

	cirfirm=new CL_PushButton(window);
	cirfirm->set_text("cirfirm edit");
	cirfirm->set_geometry(CL_Rect(40, 90, CL_Size(200, 20)))	 ;

}

bool WndEdit::isActivated()
{

	if (window->is_visible())
	{
		return true;
	}
	else return false;
}

void WndEdit::setActivated(bool flag)
{	
// 	bodyA=NULL;
// 	bodyB=NULL;
// 
	window->set_visible(flag);
}
