#ifndef	 WNDGROUNDADD_H
#define WNDGROUNDADD_H

#include "precomp.h"
#include "Box2D/Box2D.h"


class WndGroundAdd
{   

	public:
	CL_Window *window;
	CL_Label *label;
	CL_PushButton *cirfirm;

	int cur;
	b2Vec2 vertices[2];
	WndGroundAdd(void);
	~WndGroundAdd(void);

	void Init(CL_GUIManager *gui,CL_DisplayWindowDescription *desc);
	bool isActivated();
	
	void setActivated(bool flag);
	void AddVertex(b2Vec2 pos);
	void draw(CL_GraphicContext *gc);

};
#endif