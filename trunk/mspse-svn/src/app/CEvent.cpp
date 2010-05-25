#include "CEvent.h"


//========================================================================
CEvent::CEvent()
{
}

//========================================================================
CEvent::~CEvent()
{
}

//========================================================================
void CEvent::OnEvent(SDL_Event* sdlEvent)
{
    switch(sdlEvent->type)
    {
        case SDL_ACTIVEEVENT:
        {
            switch(sdlEvent->active.state)
            {
                case SDL_APPMOUSEFOCUS:
                {
                    if ( sdlEvent->active.gain )
                        OnMouseFocus();
                    else
                        OnMouseBlur();

                    break;
                }
                case SDL_APPINPUTFOCUS:
                    {
                        if ( sdlEvent->active.gain )
                            OnInputFocus();
                        else
                            OnInputBlur();

                        break;
                    }
                case SDL_APPACTIVE:
                    {
                        if ( sdlEvent->active.gain )
                            OnRestore();
                        else
                            OnMinimize();

                        break;
                    }
            }//switch(sdlEvent->active.state)
            break;
        }//case SDL_ACTIVEEVENT:
        
        
        case SDL_KEYDOWN:
        {
            OnKeyDown(sdlEvent->key.keysym.sym,
                sdlEvent->key.keysym.mod,
                sdlEvent->key.keysym.unicode);
            
            break;
        }
        
        case SDL_KEYUP:
        {
            OnKeyUp(sdlEvent->key.keysym.sym,
                sdlEvent->key.keysym.mod,
                sdlEvent->key.keysym.unicode);
            
            break;
        }
        
        case SDL_MOUSEMOTION:
        {
            OnMouseMove(sdlEvent->motion.x,
                sdlEvent->motion.y,
                sdlEvent->motion.xrel,
                sdlEvent->motion.yrel,
                (sdlEvent->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,
                (sdlEvent->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,
                (sdlEvent->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        {
            switch(sdlEvent->button.button)
            {
                case SDL_BUTTON_LEFT:
                {
                    OnLButtonDown(sdlEvent->button.x,
                        sdlEvent->button.y);
                
                    break;
                }
                case SDL_BUTTON_RIGHT:
                {
                    OnRButtonDown(sdlEvent->button.x,
                        sdlEvent->button.y);

                    break;
                }
                case SDL_BUTTON_MIDDLE:
                {
                        OnMButtonDown(sdlEvent->button.x,
                            sdlEvent->button.y);
                        break;
                }
            }//switch(sdlEvent->button.button)

            break;
        }//case SDL_MOUSEBUTTONDOWN:

        case SDL_MOUSEBUTTONUP:
        {
            switch(sdlEvent->button.button)
            {
                case SDL_BUTTON_LEFT:
                {
                    OnLButtonUp(sdlEvent->button.x,sdlEvent->button.y);
                    
                    break;
                }
                case SDL_BUTTON_RIGHT:
                {
                    OnRButtonUp(sdlEvent->button.x,sdlEvent->button.y);
                    
                    break;
                }
                case SDL_BUTTON_MIDDLE:
                {
                    OnMButtonUp(sdlEvent->button.x,sdlEvent->button.y);
                    
                    break;
                }
            }//switch(sdlEvent->button.button)
            break;
        }//case SDL_MOUSEBUTTONUP:

        case SDL_JOYAXISMOTION:
        {
            OnJoyAxis(sdlEvent->jaxis.which,
                sdlEvent->jaxis.axis,sdlEvent->jaxis.value);
            break;
        }

        case SDL_JOYBALLMOTION:
        {
            OnJoyBall(sdlEvent->jball.which,
            sdlEvent->jball.ball,
            sdlEvent->jball.xrel,sdlEvent->jball.yrel);
            break;
        }

        case SDL_JOYHATMOTION:
        {
            OnJoyHat(sdlEvent->jhat.which,
            sdlEvent->jhat.hat,sdlEvent->jhat.value);
            break;
        }

        case SDL_JOYBUTTONDOWN:
        {
            OnJoyButtonDown(sdlEvent->jbutton.which,
            sdlEvent->jbutton.button);
            break;
        }

        case SDL_JOYBUTTONUP:
        {
            OnJoyButtonUp(sdlEvent->jbutton.which,
            sdlEvent->jbutton.button);
            break;
        }

        case SDL_QUIT:
        {
            OnExit();
            break;
        }

        case SDL_SYSWMEVENT:
        {
            //Ignore
            break;
        }

        case SDL_VIDEORESIZE:
        {
            OnResize(sdlEvent->resize.w,sdlEvent->resize.h);
            break;
        }

        case SDL_VIDEOEXPOSE:
        {
            OnExpose();
            break;
        }

        default:
        {
            OnUser(sdlEvent->user.type,
                sdlEvent->user.code,
                sdlEvent->user.data1,sdlEvent->user.data2);
            break;
        }
    }//switch(sdlEvent->type)
}//void CEvent::OnEvent(SDL_Event* sdlEvent)

//========================================================================
void CEvent::OnInputFocus()
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnInputBlur()
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnMouseFocus()
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnMouseBlur()
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnMouseMove(int mX, int mY, int relX, int relY,
    bool Left,bool Right,bool Middle)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnMouseWheel(bool Up, bool Down)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnLButtonDown(int mX, int mY)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnLButtonUp(int mX, int mY)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnRButtonDown(int mX, int mY)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnRButtonUp(int mX, int mY)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnMButtonDown(int mX, int mY)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnMButtonUp(int mX, int mY)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnJoyButtonDown(Uint8 which,Uint8 button)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnJoyButtonUp(Uint8 which,Uint8 button)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnMinimize()
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnRestore()
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnResize(int w,int h)
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnExpose()
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnExit()
{
    //Pure virtual, do nothing
}

//========================================================================
void CEvent::OnUser(Uint8 type, int code, void* data1, void* data2)
{
    //Pure virtual, do nothing
}

//end=====================================================================