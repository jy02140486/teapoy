#include "Bgr.h"
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

CBackGround::CBackGround()
{

}

CBackGround::~CBackGround()
{

}

void CBackGround::Init(CL_GraphicContext *gc)
{
	srand(time(NULL));

	time(&mrka);
	try
	{
// 		sd1.add_frame(CL_ImageProviderFactory::load("resource/Sprites/1.png"));
// 		sd1.add_frame(CL_ImageProviderFactory::load("resource/Sprites/2.png"));
// 		sd1.add_frame(CL_ImageProviderFactory::load("resource/Sprites/3.png"));
// 		sd1.add_frame(CL_ImageProviderFactory::load("resource/Sprites/1.png"));

		for(int i=1;i<10;i++)
		{	
			std::string str="resource/Sprites/a0";
			char* num=new char(10);
			sprintf(num,"%d.png",i);
			str.append(num);
			sd1.add_frame(CL_ImageProviderFactory::load(str.data()));
			CL_Console::write_line(str.data());
// 			delete[]num;
		}

		sd1.add_frame(CL_ImageProviderFactory::load("resource/Sprites/a10.png"));

		sd1.set_frame_delay(1,1);

		clouds=new CL_Sprite(*gc,sd1);

// 		cloud.push_front(clouds);
// 		cloud.push_front(clouds);
// 		cloud.push_front(clouds);
		
		int width,height;
		for (int i=0;i<NUMCLOUDS;i++)
		{
			width=rand()%800;
			height=rand()%600;
			pos.push_front(CL_Vec2f(width,height));
		}
		CL_Console::write_line("%1",pos.size());

		std::list<CL_Vec2f>::iterator itr=pos.begin();
		CL_Console::write_line("%1 %2",		(*itr).x,		(*itr).y);
	}
	catch (CL_Exception* e)
	{
		CL_Console::write_line("Crap");
// 		CL_Console::write_line(e->get_message_and_stack_trace());
		return;
	}
}
void CBackGround::Update()
{

	clouds->update();

	time(&mrkb);
	
	if (mrkb-mrka<1)
	{
 return;
	}

	time(&mrka);

// 	CL_Vec2f temp;
	for (std::list<CL_Vec2f>::iterator itr=pos.begin();itr!=pos.end();itr++)
	  {
		if ((*itr).x--<-200)
		{
			 (*itr).x=800;
			 (*itr).y=rand()%600;
		} 
		else
		{
			(*itr).x-=1;
		}
	  }

}

void CBackGround::draw(CL_GraphicContext *gc)
{
	for (std::list<CL_Vec2f>::iterator itr=pos.begin();itr!=pos.end();itr++)
	{
		 clouds->draw(*gc,(*itr).x,(*itr).y);
	}

}
