#include "Game.h"
#include <main.h>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
    uint32_t frameStart, frameTime;

    if (TheGame::getInstace()->init("Chapter 2", 100, 100,
        TheGame::getInstace()->SCREEN_WIDTH,
        TheGame::getInstace()->SCREEN_HEIGHT,
        false))
    {

        while (TheGame::getInstace()->running())
        {
            frameStart = SDL_GetTicks();                // 시간 재기 시작

            TheGame::getInstace()->handleEvent();
            TheGame::getInstace()->update();
            TheGame::getInstace()->renderer();

            frameTime = SDL_GetTicks() - frameStart;    // 걸린 시간 확인

            // 만약 걸린 시간이 딜레이 보다 길면, 조정
            if (frameTime < DELAY_TIME) {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }

    }
    else{
        std::cout << "Game Init failure" << SDL_GetError() << std::endl;
    }

    TheGame::getInstace()->clean();

    return 0;
}