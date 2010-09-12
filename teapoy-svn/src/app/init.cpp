#include "app.h"
#include "event.h"

bool T_App::init()
{
	try
	{
		
	//initail window description
	mWinDesc.set_title("Teapoy");
	mWinDesc.set_allow_resize(true);
	mWinDesc.set_size(CL_Size (800, 600), false);
	//mWinDesc.set_refresh_rate(50);

	//resource directory
// 	CL_String resource("../../resource/GUITheme/resources.xml");
// 	CL_String theme("../../resource/GUITheme/theme.css");
	
	CL_String resource("resource/GUITheme/resources.xml");
	CL_String theme("resource/GUITheme/theme.css");

	//initail resource manager
	mResManager.load(resource);

	////initail gui theme
	mGUITheme.set_resources(mResManager);

	//initail gui
	mpDisplayWindow = new CL_DisplayWindow(mWinDesc);
	mpWinManager = new CL_GUIWindowManagerTexture(*mpDisplayWindow);
	mGui.set_window_manager(*mpWinManager);
	mGui.set_theme(mGUITheme);
	mGui.set_css_document(theme);

	mpWinManager->func_repaint().set(this, &T_App::render);

	//initail GUIComponet window
		CL_DisplayWindowDescription comWindowDesc;
		comWindowDesc.show_border(false);
		comWindowDesc.set_allow_resize(true);
		comWindowDesc.set_title("settings");
		comWindowDesc.set_size(CL_Size(300, 320),false);
		comWindowDesc.set_allow_resize(true);
		comWindowDesc.set_layered(true);

		mpComWindow = new CL_Window(&mGui, comWindowDesc);
		mpComWindow->set_draggable(true);

		comWindowDesc.set_position(CL_Rect(480,0,CL_Size(320,200)),false);
		comWindowDesc.show_border(false);
		comWindowDesc.set_allow_resize(true);
		comWindowDesc.set_title("Add a body");
		comWindowDesc.set_size(CL_Size(300, 320),false);
		comWindowDesc.set_allow_resize(true);
		comWindowDesc.set_layered(true);

		WndAdd=new CL_Window(&mGui,comWindowDesc);
		WndAdd->set_draggable(true);
		WndAdd->set_visible(false);
		
		AddCusBody=new CL_PushButton(WndAdd);
		AddCusBody->set_geometry(CL_Rect(40,50,CL_Size(70,30)));
		AddCusBody->set_text("Comfirm");
		AddCusBody->func_clicked().set(this,&T_App::OnAddCusBodyClick);
		
		comWindowDesc.set_position(CL_Rect(480,0,CL_Size(220,100)),false);
		comWindowDesc.show_border(false);
		comWindowDesc.set_allow_resize(true);
		comWindowDesc.set_title("Edit scene");
		comWindowDesc.set_size(CL_Size(300, 320),false);
		comWindowDesc.set_allow_resize(true);
		comWindowDesc.set_layered(true);

		edit=new WndEdit();
		edit->Init(&mGui,&comWindowDesc);
		edit->cirfirm->func_clicked().set(this,&T_App::OnButtonEditClick);

		b2BodyTypelist=new CL_ComboBox(WndAdd);
		b2BodyTypelist->set_geometry(CL_Rect(40, 110, CL_Size(200, 20)));
// 		b2BodyTypelist->

		BodyTypemenu.insert_item("Matrix",0);
		BodyTypemenu.insert_item("Circle",1);

		b2BodyTypelist->set_popup_menu(BodyTypemenu);
		b2BodyTypelist->set_selected_item(0);
		b2BodyTypelist->func_item_selected().set(this,&T_App::OnBodyTypeChange,b2BodyTypelist);

		mbd=new CL_Label(WndAdd);
		mbd->set_geometry(CL_Rect(80, 150, CL_Size(320, 60)));


		highth=new CL_LineEdit(mbd);
		highth->set_geometry(CL_Rect(40, 0, CL_Size(40, 20)));
		lbh=new CL_Label(mbd);
		lbh->set_text("hight");
		lbh->set_geometry(CL_Rect(0,0, CL_Size(40, 20)))	;

		width=new CL_LineEdit(mbd);
		width->set_geometry(CL_Rect(40,30, CL_Size(40, 20)));
		lbw=new CL_Label(mbd);
		lbw->set_text("width");
		lbw->set_geometry(CL_Rect(0, 30, CL_Size(40, 20)))	;

		mass=new CL_LineEdit(WndAdd);
		mass->set_geometry(CL_Rect(140, 260, CL_Size(40, 20)));
		lbm=new CL_Label(WndAdd);
		lbm->set_text("mass");
		lbm->set_geometry(CL_Rect(100, 260, CL_Size(40, 20)))	;
		
		cbd=new CL_Label(WndAdd);
		cbd->set_geometry(CL_Rect(80, 150, CL_Size(320, 60)));
		cbd->set_visible(false);

		R=new CL_LineEdit(cbd);
		R->set_geometry(CL_Rect(40,0, CL_Size(40, 20)));

		rbm=new CL_Label(cbd);
		rbm->set_geometry(CL_Rect(0,0, CL_Size(40, 20)));
		rbm->set_text("Radius");


		button1=new CL_PushButton(mpComWindow);
		button1->set_geometry(CL_Rect(40,50,CL_Size(70,30)));
		button1->set_text("Add a Body");
		button1->func_clicked().set(this,&T_App::OnButton1click);

		buttonGrd=new CL_PushButton(mpComWindow);
		buttonGrd->set_geometry(CL_Rect(40,80,CL_Size(70,30)));
		buttonGrd->set_text("Add a GroundBody");
		buttonGrd->func_clicked().set(this,&T_App::OnbuttonGrdClick);

		buttonJnt=new CL_PushButton(mpComWindow);
		buttonJnt->set_geometry(CL_Rect(120,50,CL_Size(70,30)));
		buttonJnt->set_text("Add a Joint");
		buttonJnt->func_clicked().set(this,&T_App::OnbuttonJntClick);


		buttonEdit=new CL_PushButton(mpComWindow);
		buttonEdit->set_geometry(CL_Rect(120,80,CL_Size(70,30)));
		buttonEdit->set_text("Edit Scene");

		
		//CL_Rect *a=new CL_Rect()

		slider_vertical = new CL_Slider(mpComWindow);
		slider_vertical->set_geometry(CL_Rect(40, 130, CL_Size(200, 20)));
		slider_vertical->set_max(480);
		slider_vertical->set_min(0);
		slider_vertical->set_position(480);

		slider_vertical->func_value_changed().set(this,&T_App::OnSliderMove)	;

		Label1=new CL_Label(mpComWindow);
		Label1->set_text("timestep");
		Label1->set_geometry(CL_Rect(40,115,CL_Size(28,15)));

		addground=new WndGroundAdd();
		comWindowDesc.set_position(CL_Rect(480,40,CL_Size(320,200)),false)   ;
		addground->Init(&mGui,&comWindowDesc);

		addjoint=new WndJointAdd();
		comWindowDesc.set_position(CL_Rect(480,40,CL_Size(320,200)),false)	;
		addjoint->Init(&mGui,&comWindowDesc);
		addjoint->cirfirm->func_clicked().set(this,&T_App::OnAddJnt);


		//initail console window
   initRulers(mpComWindow);
   initRulers(WndAdd);
   initRulers(addground->window);

	//initail events
	mInput = mpDisplayWindow->get_ic();
	mKeyboard = mInput.get_keyboard();
	mMouse = mInput.get_mouse();
	//mJoystick = mInput.get_joystick();

	mpConsole = new CL_ConsoleWindow("Console", 80, 100);
	
	bgr=new CBackGround();
	
	bgr->Init(&(mpDisplayWindow->get_gc()));

	}
	catch (CL_Exception &exception)
	{
		CL_Console::write_line("Exception:Init error",
			exception.get_message_and_stack_trace());
// 		mpConsole->display_close_message();
		CL_Console::write_line(exception.get_message_and_stack_trace());

		return true;
	}

	running=true;

	mpphytester=new phyentity();
	mpphytester->Initialize();

	T_Event::eventInit();
	T_App::eventInit();

// 	slotMouseDown = mMouse.sig_key_down().connect(this,
// 		&T_App::onMouseDown);

	return true;
}

