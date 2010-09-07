#ifndef BGR_H
#define BGR_H

#include "precomp.h"
#include "../lib/IDraw.h"
#include <list>
#include <time.h>

#define NUMCLOUDS	4

class CBackGround:public Idraw
{
public:	
	CL_SpriteDescription sd1;
	CL_Sprite *clouds;
	std::list<CL_Vec2f> pos;

	time_t mrka,mrkb;

	CBackGround();
	~CBackGround();

	void Init(CL_GraphicContext *gc);
	void draw(CL_GraphicContext *gc);
	void Update();
};
#endif