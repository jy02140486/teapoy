﻿#include "CObject.h"

//========================================================================
CObject::CObject()
{
    CurrentFrame    = 0;
    MaxFrames       = 0;
    FrameInc        = 1;
    FrameRate       = 100; //Milliseconds
    OldTime         = 0;
    Oscillate       = false;
}

//========================================================================
void CObject::OnObject()
{
    if(OldTime + FrameRate > SDL_GetTicks())
    {
        return;
    }

    OldTime = SDL_GetTicks();

    CurrentFrame += FrameInc;

    if(Oscillate)
    {
        if(FrameInc > 0)
        {
            if(CurrentFrame >= MaxFrames)
            {
                FrameInc = -FrameInc;
            }
        }else
        {
            if(CurrentFrame <= 0)
            {
                FrameInc = -FrameInc;
            }
        }
    }
    else
    {
        if(CurrentFrame >= MaxFrames)
        {
            CurrentFrame = 0;
        }
    }
}

//========================================================================
void CObject::SetFrameRate(int Rate)
{
    FrameRate = Rate;
}

//========================================================================
void CObject::SetCurrentFrame(int Frame)
{
    if(Frame < 0 || Frame >= MaxFrames)
    return;
    CurrentFrame = Frame;
}

//========================================================================
int CObject::GetCurrentFrame()
{
    return CurrentFrame;
}