#ifndef _CAPP_H_
    #define _CAPP_H_
/** 标准头文件 */
#include <SDL.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>

/** 项目头文件 */
#include "../entities/CObject.h"
#include "CEvent.h"
#include "../lib/CSurface.h"
#include "../entities/CEntity.h"
#include "../lib/MSDL_Thread.h"
#include <Box2D/Box2d.h>

using namespace std;



/** 游戏主类 */
class CApp : public CEvent {
private:
    
    /** 程序运行时布尔值，false是调用 OnCleanup()，退出游戏 */
    bool            running;

    /** 程序渲染线程句柄 */
    SDL_Thread *    renderThread;

    /** 程序根表面，所有的表面绘图基于此之上 */
    SDL_Surface*    surRoot;

    SDL_Surface*	surBg;

    CObject         objTest;

    CEntity         entity1;
    CEntity         entity2;

public:
    /** 程序渲染时布尔值，false表示停止渲染 */
    bool      rendering;

public:
    CApp();

    int OnExecute();

public:

    /** 游戏主过程之初始化 */
    bool OnInit();

    /** 游戏主过程之事件处理 */
    void OnEvent(SDL_Event* sdlEvent);

    /** 游戏主过程之主循环 */
    void OnMainLoop();

    /** 游戏主过程之渲染 */
    void OnRender();

    /** 游戏主过程之清理 */
    void OnCleanup();

    /** 程序渲染线程循环函数 */
    int RenderThreadLoop();


    /** 用户发出退出请求时调用 */
    void OnExit();
};

#endif
