#ifndef ENT_H
#define ENT_H

#include "Box2D/Box2D.h"
#include "../app/precomp.h"

class phyentity
{
public:
	b2World *world;
	b2AABB aabb;

	b2BodyDef bodyDef;

	b2PolygonShape shapedef;

	b2Vec2 worldAxis;

	float32 timeStep ;
	int32 velocityIterations ;
	int32 positionIterations ;

	b2BodyDef groundBodyDef,groundBodyDef2;
	b2Body* groundBody,*groundBody2;

	b2PolygonShape groundBox;

	b2MouseJointDef mjd;
	b2MouseJoint* mj;

	//funtions
	void Initialize();
	phyentity* getEntities(){return this;}
	void draw(CL_GraphicContext &gc);
	void updater();

	~phyentity();
	
	void setConvexVertex(b2PolygonShape *shapeDef,int n,float32 radius);
	void drawbox(CL_GraphicContext *gc,b2Body *bodyref);
	void AddBodyTemp();
	void DrawJoints(CL_GraphicContext *gc);
};

#endif