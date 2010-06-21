#ifndef APP_H
#define APP_H 
#include "precomp.h"

class T_App 
{
public:
	T_App ();
	int  start();

	//initial game enviroment
	bool init();

	//processing game events
	void event();

	//processing game logics
	void loop();

	//render the game
	void render();

	//quit the game
	void closeWindow();

private:
	CL_GUIManager mGui;
	CL_DisplayWindow *mpDisplayWindow;
	CL_GUIWindowManagerTexture *mpWinManager;
	CL_DisplayWindowDescription mWinDesc;

	//console window
	CL_ConsoleWindow *mpConsole;

	//input context
	CL_InputContext mInput;

	//keyboard context
	CL_InputDevice mKeyboard;

	//mouse context
	CL_InputDevice mMouse;

	//joystick context
	//CL_InputDevice mJoystick;

	bool mQuit;

};

#endif
