#ifndef _CENTITY_H_
    #define _CENTITY_H_

#include <SDL.h>
#include <vector>

#include "CObject.h"
#include "..\lib\CSurface.h"


class CEntity
{
public:
    static std::vector<CEntity*>    entityList;

protected:
    /**  */
    CObject         ObjControl;
    /**  */
    SDL_Surface*    surEntity;

public:
    float           x;
    float           y;

    int             width;
    int             height;

    /**  */
    int             objState;

public:
    CEntity();

    virtual ~CEntity();

public:
    /**  */
    virtual bool OnLoad(char* fileURI, int Width, int Height,
        int maxFrames);

    /**  */
    virtual void OnLoop();

    /**  */
    virtual void OnRender(SDL_Surface* surDest);

    /** */
    virtual void OnCleanup();
};

#endif