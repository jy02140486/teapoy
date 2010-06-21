#ifndef EVENT_H
#define EVENT_H 
#include "precomp.h"

class T_Event
{
public:
	T_Event();

protected:
	
	CL_DisplayWindowDescription		mWinDesc;
	CL_DisplayWindow *				mpDisplayWindow;
	CL_GUIManager					mGui;
	CL_GUIWindowManagerTexture *	mpWinManager;
	

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

	//����Ϊslots��
	CL_Slot		slotWindowClose;
	CL_Slot		slotKeyboardUp;
	CL_Slot		slotMouseMove;
	CL_Slot		slotMouseDown;

	int		eventInit();

	//����Ϊ�¼�������庯����
	//-�����¼�
	void	onExitApp();

	//-�����¼�
	void onKeyboardUp(const CL_InputEvent &, const CL_InputState &);


	//-����¼�
	void onMouseMove(const CL_InputEvent &, const CL_InputState &);
	void onMouseDown(const CL_InputEvent &, const CL_InputState &);
};
#endif
