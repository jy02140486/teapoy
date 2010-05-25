#include "CApp.h"


//========================================================================
CApp::CApp()
{
    surRoot = NULL;
    surBg = NULL;
    

    running     = true;
    rendering   = true;
}
				  //holyshit
//========================================================================
int CApp::OnExecute()
{
    if(OnInit() == false) {
        //提示游戏初始化失败
        return -1;
    }

    renderThread = SDL_CreateMemberThread(this, &CApp::RenderThreadLoop);

    SDL_Event sdlEvent;

    while(running) {
        while(SDL_PollEvent(&sdlEvent)) {
            OnEvent(&sdlEvent);
        }

        OnMainLoop();
    }

    OnCleanup();

    return 0;
}

//========================================================================
int CApp::RenderThreadLoop()
{
    static Uint32 next_time = 0;
    Uint32  now = 0;
    Uint32  delay_time = 0;
    char ch[200];
    stringstream ss;

    while( rendering == true )
    {
        OnRender();

        ss.clear();
        ss<<now;
        ss<<"|";
        
        SDL_WM_SetCaption( ss.str().c_str(), NULL );


        now = SDL_GetTicks();
        if ( next_time <= now ) {
            next_time = now + 30;
            delay_time = 0;
        }
        delay_time = next_time - now;

        SDL_Delay(delay_time);

    }

    return 0;
}

//========================================================================
int main(int argc, char* argv[])
{
    CApp theApp;
    return theApp.OnExecute();
}

//end=====================================================================
