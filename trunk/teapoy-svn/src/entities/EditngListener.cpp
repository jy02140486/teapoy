#include "EditngListener.h"

void EditingListener:: EndContact(b2Contact* contact)
{

		b2Body*body=contact->GetFixtureA()->GetBody();

		for(b2JointEdge* j=body->GetJointList();j!=NULL;j=j->next)
			if (j->joint->GetType()==/*b2JointType.*/e_mouseJoint)
			{
				b2Body *temp=contact->GetFixtureB()->GetBody();
				temp->SetAwake(false);
				return;
			}
	
		body=contact->GetFixtureB()->GetBody();
		
		for(b2JointEdge* j=body->GetJointList();j!=NULL;j=j->next)
		if (j->joint->GetType()==/*b2JointType.*/e_mouseJoint)
		{
			b2Body *temp=contact->GetFixtureA()->GetBody();
			temp->SetAwake(false);
			return;
		}
}