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
	CL_String resource("../../resource/GUITheme/resources.xml");
	CL_String theme("../../resource/GUITheme/theme.css");
	
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
		//mpComWindow->set_blocks_default_action(true);
	
		CL_Rect buttoinarea(mpComWindow->get_client_area().left+10
			,mpComWindow->get_client_area().top+60,
			CL_Size(30,80));
			//initail button
// 		CL_PushButton button(mpComWindow);
// 		
// 		button.set_geometry(buttoinarea);
// 		button.set_text("FUCK");
// 		button.set_toggle(true);
// 		button.set_visible(true,true);
// 
		button1=new CL_PushButton(mpComWindow);
		button1->set_geometry(CL_Rect(40,50,CL_Size(70,30)));
		button1->set_text("Add a Body");
		button1->func_clicked().set(this,&T_App::OnButton1click);
		
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
// 		Label1=new CL_Label(mpComWindow);
// 		Label1->set_geometry(CL_Rect(10, 100, 20, 20))	;
// 		Label1->set_text("ggg");
// 		CL_PushButton button1(mpComWindow);
// 		button1.set_geometry(CL_Rect(100, 100, 200, 120));
// 		button1.set_text("Okay!");
	//	button1.func_clicked().set(&on_button1_clicked, &button1);

		
// 		CL_ComboBox combox(mpComWindow);
// 		combox.set_visible(true, true);
// 		combox.set_dropdown_height(20);
// 		combox.set_default(true);
// 		//button.set_text("Button");
// 		//CL_GUILayout layout;
// 		//button.set_layout(layout);
// 		button.set_visible(true, true);
		//CL_Image buttonImage(button.get_gc(), "../../resource/GUITheme/Images/ButtonHot.png");
		//button.set_icon(buttonImage);
		////button.set_selected_in_component_group(true);

		//initail console window
   initRulers();

	//initail events
	mInput = mpDisplayWindow->get_ic();
	mKeyboard = mInput.get_keyboard();
	mMouse = mInput.get_mouse();
	//mJoystick = mInput.get_joystick();

// 	slotWindowClose = mpDisplayWindow->sig_window_close().connect(this, 
// 		&T_Event::onExitApp);
// 	slotKeyboardUp = mKeyboard.sig_key_up().connect(this, 
// 		&T_App::onKeyboardUp);
// 	slotMouseMove = mMouse.sig_pointer_move().connect(this,
// 		&T_App::onMouseMove);
// 
// 	slotMouseUp=mMouse.sig_key_up().connect(this,
// 		&T_App::onMouseUp);

	mpConsole = new CL_ConsoleWindow("Console", 80, 100);
	
	}
	catch (CL_Exception &exception)
	{
		CL_Console::write_line("Exception:Init error",
			exception.get_message_and_stack_trace());
		mpConsole->display_close_message();
		return false;
	}
	mpphytester=new phyentity();
	mpphytester->Initialize();
	T_App::eventInit();

// 	slotMouseDown = mMouse.sig_key_down().connect(this,
// 		&T_App::onMouseDown);

	return true;
}

