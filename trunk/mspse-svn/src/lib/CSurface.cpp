#include "CSurface.h"


//========================================================================
CSurface::CSurface()
{
}

//========================================================================
SDL_Surface* CSurface::OnLoad(char* fileURI)
{
	SDL_Surface* surTemp = NULL;
	SDL_Surface* surReturn = NULL;

	if((surTemp = SDL_LoadBMP(fileURI)) == NULL) {
        //加载图片失败提示
		return NULL;
	}

	surReturn = SDL_DisplayFormat(surTemp);
	SDL_FreeSurface(surTemp);

	return surReturn;
}

//========================================================================
bool CSurface::OnDraw(SDL_Surface* surDest, SDL_Surface* surSrc,
    int dest_x, int dest_y)
{
    if(surDest == NULL || surSrc == NULL) {
        return false;
    }

    SDL_Rect destR;

    destR.x = dest_x;
    destR.y = dest_y;

    SDL_BlitSurface(surSrc, NULL, surDest, &destR);

    return true;
}

//========================================================================
bool CSurface::OnDraw(SDL_Surface* surDest, SDL_Surface* surSrc,
    int dest_x, int dest_y,
    int src_x, int src_y, int src_w, int src_h)
{
    if(surDest == NULL || surSrc == NULL) {
        return false;
    }

    SDL_Rect destR;

    destR.x = dest_x;
    destR.y = dest_y;

    SDL_Rect srcR;

    srcR.x = src_x;
    srcR.y = src_y;
    srcR.w = src_w;
    srcR.h = src_h;

    SDL_BlitSurface(surSrc, &srcR, surDest, &destR);

    return true;
}

//========================================================================
bool CSurface::Transparent(SDL_Surface* surDest, int R, int G, int B)
{
    if(surDest == NULL)
    {
        return false;
    }

    SDL_SetColorKey(surDest, SDL_SRCCOLORKEY | SDL_RLEACCEL,
        SDL_MapRGB(surDest->format, R, G, B));

    return true;
}
//end=====================================================================