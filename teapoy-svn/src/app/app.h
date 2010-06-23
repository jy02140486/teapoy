#ifndef APP_H
#define APP_H 
#include "precomp.h"
#include "event.h"

class T_App : public T_Event
{
public:
	T_App ();
	int  start();

	//initial game enviroment
	bool init();

	//processing game logics
	void loop();

	//render the game
	void render();

	void repain();
private:


};

#endif
