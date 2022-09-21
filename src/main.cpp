﻿// SDL 
//
// written by changhoonpark@gmail.com

#include "main.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	Game* game = NULL;
	bool g_brunning;

	int s_width = 640;				// 실행할 프로그램의 길이
	int s_heigh = 480;				//					 높이

	g_brunning = game->init("GameClass", 100, 100, s_width, s_heigh, 0);

	// 게임의 창이 띄워졌는지 확인
	if (!g_brunning)
		return 0;

	while (game->running())
	{
		game->handleEvent();
		game->update();
		game->renderer();
	}
}