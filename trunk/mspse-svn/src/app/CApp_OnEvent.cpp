﻿#include "CApp.h"


//========================================================================
void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

//========================================================================
void CApp::OnExit() {
    rendering = false;
	running = false;
}
//end=====================================================================