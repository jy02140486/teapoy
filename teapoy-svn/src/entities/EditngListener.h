#ifndef EDITINGLISTENER_H
#define EDITINGLISTENER_H

#include "Box2D/Box2D.h"

class   EditingListener:public b2ContactListener
{
public:
	 void EndContact(b2Contact* contact);
protected:
private:
};
#endif
