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

	////resource directory
	CL_String resource("resource/GUITheme/resources.xml");
	CL_String theme("resource/GUITheme/theme.css");
	
	////initail resource manager
	mResManager.load(resource);

	//////initail gui theme
	mGUITheme.set_resources(mResManager);

	////initail gui
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
	comWindowDesc.set_title("Componet GUI");
	comWindowDesc.set_size(CL_Size(300, 320), false);
	comWindowDesc.set_allow_resize(true);
	comWindowDesc.set_layered(true);
	comWindowDesc.show_border(false);
	mpComWindow = new CL_Window(&mGui, comWindowDesc);
	mpComWindow->set_draggable(true);
	//mpComWindow->set_blocks_default_action(true);

	//initail button
	//CL_ComboBox  combox(mpComWindow);
	mpButton = new CL_PushButton(mpComWindow);
	CL_Rect r = mpComWindow->get_client_area();
	//CL_PushButton mpButton(mpComWindow);
	mpButton->set_geometry(r.set_height(10));
	//mpButton->get_text("FUCK");
	//button.set_toggle(true);
	//button.set_visible(true, true);
	//button.set_icon(`<const CL_Image &icon>`);
	//CL_ComboBox combox(mpComWindow);
	//combox.set_visible(true, true);
	//combox.set_dropdown_height(20);
	//combox.set_default(true);
	//button.set_text("Button");
	//CL_GUILayout layout;
	//button.set_layout(layout);
	//button.set_visible(true, true);
	//CL_Image buttonImage(button.get_gc(), "../../resource/GUITheme/Images/ButtonHot.png");
	//button.set_icon(buttonImage);
	////button.set_selected_in_component_group(true);

	//initail console window
	//mpConsole = new CL_ConsoleWindow("Console", 80, 100);

	//initail events
	mInput = mpDisplayWindow->get_ic();
	mKeyboard = mInput.get_keyboard();
	mMouse = mInput.get_mouse();
	//mJoystick = mInput.get_joystick();
	
	}
	catch (CL_Exception &exception)
	{
		CL_Console::write_line("Exception:Init error",
			exception.get_message_and_stack_trace());
		//mpConsole->display_close_message();
		return false;
	}

	eventInit();
	return true;
}

