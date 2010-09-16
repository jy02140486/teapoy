#ifndef APP_H
#define APP_H 

#include "precomp.h"
#include "event.h"
#include <list>
#include<stdio.h>

//Sub Wnds
#include "WndGroundAdd.h"
#include "WndJointAdd.h"
#include "WndEdit.h"
#include "Bgr.h"

class T_App : public T_Event	
{
public:
	T_App ();
	int  start();

	//PhyObj Manager
	phyentity *mpphytester;
	bool running;

	//GUIComponets
	CL_PushButton *button1,*buttonGrd,*buttonJnt,*buttonEdit;
	CL_Slider *slider_vertical;
	CL_Label *Label1;
	std::list<CL_Label*> rulers;

	//Sub	Components
	CL_Window *WndAdd;
	CL_PushButton *AddCusBody;
	CL_ComboBox *b2BodyTypelist;
	CL_LineEdit *highth,*width,*mass,*R;
	CL_Label *lbw,*lbh,*lbm,*rbm;
	CL_PopupMenu BodyTypemenu;

	CL_Label *mbd,*cbd;
	//Sub Wnds
	WndGroundAdd *addground;
	WndJointAdd *addjoint;
	WndEdit *edit;

	//Customize Comms
	CBackGround *bgr;

	time_t Atime;
	DWORD mrk;

	//initial game enviroment
	bool init();

	//processing game logics
	void loop();

	//render the game
	void render();

	void msgHandling();
	void onMouseMove(const CL_InputEvent &, const CL_InputState &);
	void onMouseDown(const CL_InputEvent &, const CL_InputState &);
	void onMouseUp(const CL_InputEvent &, const CL_InputState &);
	void initRulers(CL_Window *refwnd);
	void onKeyboardUp(const CL_InputEvent &key,
		const CL_InputState &state);

	//GUI component on MainBoard respon
	void OnButton1click();
	void OnSliderMove();
	void OnAddCusBodyClick();
	void OnbuttonGrdClick();
	void OnbuttonJntClick();
	void OnButtonEditClick();

	void OnBodyTypeChange(int value, CL_ComboBox *combobox);

	//GUI component on SubBoard respon
	void OnAddJnt();


	int eventInit();

	bool isClkOnBoard(b2Vec2 pos,CL_Rect Area);

	//void repaint();
private:


};

#endif
