#ifndef APP_H
#define APP_H 

#include "precomp.h"
#include "event.h"
#include <list>
#include<stdio.h>

class T_App : public T_Event	
{
public:
	T_App ();
	int  start();

	//GUIComponets
	CL_PushButton *button1;
	CL_Slider *slider_vertical;
	CL_Label *Label1;
	std::list<CL_Label*> rulers;

	//Sub	Components
	CL_Window *WndAdd;
	CL_PushButton *AddCusBody;
	CL_ComboBox *b2BodyTypelist;
	CL_LineEdit *highth,*width,*mass;
	CL_Label *lbw,*lbh,*lbm;


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
	void OnButton1click();
	void OnSliderMove();
	void initRulers(CL_Window *refwnd);
  	void OnAddCusBodyClick();

	//void repaint();
private:


};

#endif
