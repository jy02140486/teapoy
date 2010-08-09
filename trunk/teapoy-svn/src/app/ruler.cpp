#include "app.h"
#include "event.h"

void T_App::initRulers(CL_Window *refwnd)
{
	std::list<CL_Label*>::iterator itr;

	CL_Label *ref;
	for (int i=0;i<refwnd->get_height();i+=20)
	{
		rulers.push_back(new CL_Label(refwnd));

 		itr=rulers.end();
  		
		itr--;

// 		if ((*itr)==NULL)
// 		{
// 			CL_Console::write_line("asdfafea");
// 		}
		ref=(*itr);
		ref->set_geometry(CL_Rect(4,i,CL_Size(20,10)));
		
		char *temp=new char(10);
		sprintf(temp,"%d",i);
		CL_StringRef str=temp;


		ref->set_text(str);
	}
}