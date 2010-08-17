#ifndef	 WNDGROUNDADD_H
#define WNDGROUNDADD_H

#include "precomp.h"

class WndGroundAdd
{   

	public:
	CL_Window *window;
	CL_Label *label;

	WndGroundAdd(void);
	~WndGroundAdd(void);

	void Init(CL_GUIManager *gui,CL_DisplayWindowDescription *desc);
	bool isActivated();
};
#endif