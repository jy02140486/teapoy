#ifndef APP_H
#define APP_H 
#include "precomp.h"
#include "event.h"

class T_App : public T_Event	
{
public:
	T_App ();
	int  start();
	 	CL_Slider *slider_vertical;
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


	
	//void repaint();
private:


};

#endif
