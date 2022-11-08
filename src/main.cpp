#include "Game.h"
#include <main.h>

int main(int argc, char* argv[])
{

    TheGame::Instance()->init("Chapter 2", 100, 100, TheGame::Instance()->SCREEN_WIDTH, TheGame::Instance()->SCREEN_HEIGHT, 0);

    while (TheGame::Instance()->running())
    {
        TheGame::Instance()->handleEvent();
        TheGame::Instance()->update();
        TheGame::Instance()->renderer();
    }

    TheGame::Instance()->clean();

    return 0;
}