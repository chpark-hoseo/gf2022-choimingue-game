#include "Game.h"
#include <main.h>

Game* g_game = 0;

int main(int argc, char* argv[])
{
    g_game = new Game();

    g_game->init("Chapter 2", 100, 100, g_game->SCREEN_WIDTH, g_game->SCREEN_HEIGHT, 0);

    while (g_game->running())
    {
        g_game->handleEvent();
        g_game->update();
        g_game->renderer();
    }

    g_game->clean();

    return 0;
}