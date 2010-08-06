#include "app.h"
#include <stdio.h>
#include "event.h"

void T_App::initRulers()
{
	std::list<CL_Label*>::iterator itr;

	CL_Label *ref;
	for (int i=0;i<mpComWindow->get_height();i+=20)
	{
		rulers.push_back(new CL_Label(mpComWindow));

 		itr=rulers.end();
  		
		itr--;

// 		if ((*itr)==NULL)
// 		{
// 			CL_Console::write_line("asdfafea");
// 		}
		ref=(*itr);
		ref->set_geometry(CL_Rect(4,i,CL_Size(20,10)));
		
		char *temp=new char(10);
		//CL_StringRef str= sprintf("%d", i);


		//ref->set_text(str);
	}
}
