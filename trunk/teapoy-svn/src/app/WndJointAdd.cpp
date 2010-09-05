#include "WndJointAdd.h"

WndJointAdd::WndJointAdd(void)
{
}

WndJointAdd::~WndJointAdd(void)
{
}

void WndJointAdd::Init(CL_GUIManager *gui,CL_DisplayWindowDescription *desc)
{
	window=new CL_Window(gui,*desc);
	window->set_visible(false);
	window->set_draggable(true);


	label=new CL_Label(window);
	label->set_geometry(CL_Rect(40, 50, CL_Size(200, 20)))	;
	label->set_text("");

	cirfirm=new CL_PushButton(window);
	cirfirm->set_text("cirfirm");
	cirfirm->set_geometry(CL_Rect(40, 90, CL_Size(200, 20)))	 ;

	Jointmenu.insert_item("DistanceJoint",0,0)	;
	Jointmenu.insert_item("PrismaticJoint",1,1) ;

	b2JointTypeList=new CL_ComboBox(window);
	b2JointTypeList->set_popup_menu(Jointmenu);
	b2JointTypeList->set_geometry(CL_Rect(40, 70, CL_Size(200, 20)))	;
	
	b2JointTypeList->func_item_selected().set(this, &WndJointAdd::showcom, b2JointTypeList);
	b2JointTypeList->set_selected_item(0);

	lenth= new CL_Spin(window);
	lenth->set_geometry(CL_Rect(40, 140, CL_Size(200, 20)));
	lenth->set_number_of_decimal_places(3);
	lenth->set_value(50);
	lenth->set_step_size(5);
	lenth->set_ranges(1, 800);
	lenth->set_floating_point_mode(false);
	lenth->set_visible(false);

	bodyA=NULL;
	bodyB=NULL;
}

bool WndJointAdd::isActivated()
{

	if (window->is_visible())
	{
		return true;
	}
	else return false;
}

void WndJointAdd::setActivated(bool flag)
{	
	bodyA=NULL;
	bodyB=NULL;

	window->set_visible(flag);
}

void WndJointAdd::showcom(int value, CL_ComboBox *combobox)
{
	
	 switch(b2JointTypeList->get_selected_item())
	 {
	 case 0:
		 CL_Console::write_line("1");
		 lenth->set_visible(true);
	 	break;
	 case 1:
		 CL_Console::write_line("2");
	 	break;
	 case 2:
	     break;
	 case 3:
	     break;
	 default:
	     break;
	 }

// 	 cirfirm->set_visible(true);

}

void WndJointAdd::ConnectBody(b2Body* body,b2Vec2 pos)
{
	 if (bodyA==NULL&&bodyB==NULL)
	 {
		   bodyA=body;
		   archA=pos;
		   return;
	 }

	 if (bodyA==NULL||bodyB==NULL)
	 {
		 bodyB=body;
		 archB=pos;
		 return;
	 }

	 if (bodyA&&bodyB)
	 {
		 bodyA=body;
		 archA=pos;
		 return;
	 }
}

void WndJointAdd::draw(CL_GraphicContext *gc)
{

}