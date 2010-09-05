#ifndef WNDJOINTADD_H
#define  WNDJOINTADD_H

#include "precomp.h"
#include "Box2D/Box2D.h"

#include "../lib/IDraw.h"

class WndJointAdd: public Idraw
{
public:

	CL_Window *window;
	CL_Label *label;
	CL_PushButton *cirfirm;

	CL_ComboBox *b2JointTypeList;
	b2Body* bodyA;
	b2Body* bodyB;
	b2Vec2 archA;
	b2Vec2 archB;
	CL_PopupMenu Jointmenu;

	CL_Spin *lenth;


	WndJointAdd(void);
	~WndJointAdd(void);
	void Init(CL_GUIManager *gui,CL_DisplayWindowDescription *desc);
	bool isActivated();
	void setActivated(bool flag);
	void showcom(int value, CL_ComboBox *combobox);
	void ConnectBody(b2Body* body,b2Vec2 pos);
	void draw(CL_GraphicContext *gc);
};
 #endif