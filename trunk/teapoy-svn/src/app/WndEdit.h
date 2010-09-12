#ifndef WNDEDIT_H
#define WNDEDIT_H

#include "precomp.h"
#include "Box2D/Box2D.h"

class WndEdit
{
public:
	CL_Window *window;
	CL_Label *label;
	CL_PushButton *cirfirm;

	b2Body* bodyref;

	void Init(CL_GUIManager *gui,CL_DisplayWindowDescription *desc);
	void setActivated(bool flag);
	bool isActivated();
protected:
private:
};
#endif
