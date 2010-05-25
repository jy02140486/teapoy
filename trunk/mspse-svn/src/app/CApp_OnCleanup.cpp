#include "CApp.h"


//========================================================================
void CApp::OnCleanup() {

    SDL_KillThread( renderThread );

    SDL_FreeSurface(surBg);
    SDL_FreeSurface(surRoot);

    for(int i = 0;i < CEntity::entityList.size();i++)
    {
        if(!CEntity::entityList[i])
            continue;

        CEntity::entityList[i]->OnCleanup();
    }

    CEntity::entityList.clear();

    SDL_Quit();
}
//end=====================================================================