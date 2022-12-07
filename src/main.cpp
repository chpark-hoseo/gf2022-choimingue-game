﻿#include "Game.h"
#include <main.h>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
    Uint32 frameStart, frameTime;

    TheGame::Instance()->init("Zelda_Game", 100, 100, TheGame::Instance()->SCREEN_WIDTH, TheGame::Instance()->SCREEN_HEIGHT, 0);
    
    while (TheGame::Instance()->running())
    {
        frameStart = SDL_GetTicks();

        TheGame::Instance()->handleEvent();
        TheGame::Instance()->update();
        TheGame::Instance()->renderer();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME) {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }

    TheGame::Instance()->clean();

    return 0;
}