#include "event.h"

T_Event::T_Event()
{
	mQuit = false;

	
}

int T_Event::eventInit()
{
	//�����¼����
	slotWindowClose = mpDisplayWindow->sig_window_close().connect(this, 
		&T_Event::onExitApp);
	slotKeyboardUp = mKeyboard.sig_key_up().connect(this, 
		&T_Event::onKeyboardUp);
	slotMouseMove = mMouse.sig_pointer_move().connect(this,
		&T_Event::onMouseMove);
	slotMouseDown = mMouse.sig_key_down().connect(this,
		&T_Event::onMouseDown);


	return 0;
}





//����Ϊ�¼�������庯����
//-�����¼�
void T_Event::onExitApp()
{
	mQuit = true;
}

//-�����¼�

void T_Event::onKeyboardUp(const CL_InputEvent &key,
						   const CL_InputState &state)
{
	if(key.id == CL_KEY_ESCAPE)
		mQuit = true;
}

//-����¼�
void T_Event::onMouseMove(const CL_InputEvent &key, const CL_InputState &state)
{
}

void T_Event::onMouseDown(const CL_InputEvent &key, const CL_InputState &state)
{
}