#ifndef	 WNDGROUNDADD_H
#define WNDGROUNDADD_H

#include "precomp.h"
#include "Box2D/Box2D.h"
#include "../lib/IDraw.h"
#include "../entities/protypeEntities.h"


class WndGroundAdd:public Idraw
{   

	public:
	CL_Window *window;
	CL_Label *label;
	CL_PushButton *cirfirm;

	bool first;
	bool drawing;
	b2Vec2 vertices[2];
	WndGroundAdd(void);
	~WndGroundAdd(void);

	void Init(CL_GUIManager *gui,CL_DisplayWindowDescription *desc);
	bool isActivated();
	bool isDrawing(){ return drawing;}
	
	void setActivated(bool flag);
	void AddVertex(b2Vec2 pos,int index);
	void draw(CL_GraphicContext *gc);
	void OnAdd(phyentity *mpphytester);
};
#endif