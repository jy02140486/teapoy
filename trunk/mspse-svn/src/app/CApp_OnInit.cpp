#include "CApp.h"


//========================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    if((surRoot = SDL_SetVideoMode(640, 480, 32,
        SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
        return false;
    }

	if((surBg = CSurface::OnLoad("resources/bg.bmp")) == NULL)
    {
		return false;
	}

    objTest.MaxFrames = 8;
    //objTest.Oscillate = true;

    if(entity1.OnLoad("resources/yoshi.bmp", 64, 64, 8) == false)
    {
        return false;
    }

    if(entity2.OnLoad("resources/yoshi.bmp", 64, 64, 8) == false)
    {
        return false;
    }

    entity1.x = 100;
    entity2.x = 200;

    CEntity::entityList.push_back(&entity1);
    CEntity::entityList.push_back(&entity2);
	
   
	
	return true;
}
//end=====================================================================