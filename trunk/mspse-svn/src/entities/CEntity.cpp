#include "CEntity.h"



std::vector<CEntity*> CEntity::entityList;

//========================================================================
CEntity::CEntity()
{
    surEntity = NULL;

    x = y = 0.0f;

    width = height = 0;

    objState = 0;
}

//========================================================================
CEntity::~CEntity()
{
}

//========================================================================
bool CEntity::OnLoad(char* fileURI, int width, int height,
    int maxFrames)
{
    if((surEntity = CSurface::OnLoad(fileURI)) == NULL)
    {
        return false;
    }

    CSurface::Transparent(surEntity, 255, 0, 255);

    this->width = width;
    this->height = height;

    ObjControl.MaxFrames = maxFrames;

    return true;
}

//========================================================================
void CEntity::OnLoop()
{
    ObjControl.OnObject();
}

//========================================================================
void CEntity::OnRender(SDL_Surface* surDest)
{
    if(surEntity == NULL || surDest == NULL) return;

    CSurface::OnDraw(surDest, surEntity, x, y,
        objState * width, ObjControl.GetCurrentFrame() * height,
        width, height);
}

//========================================================================
void CEntity::OnCleanup()
{
    if(surEntity)
    {
        SDL_FreeSurface(surEntity);
    }

    surEntity = NULL;
}
//end=====================================================================