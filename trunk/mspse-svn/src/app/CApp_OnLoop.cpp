#include "CApp.h"


//========================================================================
void CApp::OnMainLoop()
{

    for(int i = 0;i < CEntity::entityList.size();i++)
    {
        if(!CEntity::entityList[i])
            continue;

        CEntity::entityList[i]->OnLoop();
    }
}
//end=====================================================================