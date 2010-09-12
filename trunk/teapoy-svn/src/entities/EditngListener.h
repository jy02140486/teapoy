#ifndef EDITINGLISTENER_H
#define EDITINGLISTENER_H

#include "box2d\box2d.h"

class   EditingListener:public b2ContactListener
{
public:
	 void EndContact(b2Contact* contact);
protected:
private:
};
#endif