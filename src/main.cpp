#include "Game.h"
#include <main.h>

int main(int argc, char* argv[])
{
    if (TheGame::getInstace()->init("Chapter 2", 100, 100,
        TheGame::getInstace()->SCREEN_WIDTH,
        TheGame::getInstace()->SCREEN_HEIGHT,
        false))
    {

        while (TheGame::getInstace()->running())
        {
            TheGame::getInstace()->handleEvent();
            TheGame::getInstace()->update();
            TheGame::getInstace()->renderer();
            SDL_Delay(10);
        }

    }
    else{
        std::cout << "Game Init failure" << SDL_GetError() << std::endl;
    }

    TheGame::getInstace()->clean();

    return 0;
}