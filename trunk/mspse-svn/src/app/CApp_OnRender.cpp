#include "CApp.h"


//========================================================================
void CApp::OnRender() {
	CSurface::OnDraw(surRoot, surBg, 0, 0);

    for(int i = 0;i < CEntity::entityList.size();i++)
    {
        if(!CEntity::entityList[i])
            continue;

        CEntity::entityList[i]->OnRender(surRoot);
    }

	SDL_Flip(surRoot);
}
//end=====================================================================