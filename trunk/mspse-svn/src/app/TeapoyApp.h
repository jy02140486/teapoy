#ifndef _TEAPOYAPP_H_
#define _TEAPOYAPP_H_

//clanlib引用
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/application.h>



//app类

class TeapoyApp
{
private:

	//app类初始化
	CL_Font				font;
	CL_ConsoleWindow*	console;

	//oninit过程初始化
	CL_DisplayWindow	window;
	CL_GraphicContext	gc;
	CL_InputDevice		keyboard;


public:
	TeapoyApp();


	static int drawSth(CL_GraphicContext gc);

	int OnExecute();

public:

	/** 游戏主过程之初始化 */
	int OnInit();

	/** 游戏主过程之事件处理 */
	int OnEvent();

	/** 游戏主过程之主循环 */
	int OnMainLoop();

	/** 游戏主过程之渲染 */
	int OnRender();

	/** 游戏主过程之清理 */
	int OnCleanup();

	/** 程序渲染线程循环函数 */
	int RenderThreadLoop();


	/** 用户发出退出请求时调用 */
	int OnExit();
};

#endif