// SDL 
//
// written by changhoonpark@gmail.com

#include "main.h"
#include "stdlib.h"
#include <SDL2/SDL.h>


// 이번 실습때, 쓸 요소 (2주차)
SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

// 함수를 나누기 (3주차)
bool g_bRunning = false;		// 윈도우가 제대로 생성됐는지 확인하는 변수
bool init(const char* Stitle, int xpos, int ypos, int Swidth, int Sheight, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		// 윈도우를 생성
		g_pWindow = SDL_CreateWindow(Stitle, xpos, ypos, Swidth, Sheight, flags);

		if (g_pWindow != NULL)
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		else
			return false;
	}

	return true;
}
void render()
{
	SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
	SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);
	SDL_Delay(1000);
}

int main(int argc, char* argv[])
{
	int swidth = 640;			// 모니터 폭
	int sheight = 480;			// 모니터 높이
	int rCount = 0;				// 렌더링을 실행한 횟수
	const int out_Count = 10;	// 종료할 수 있는 최소 수치

	if (init("Breaking Up HelloSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		swidth, sheight, SDL_WINDOW_SHOWN)) {
		g_bRunning = true;
	}
	else
		return 1;

	// 제대로 생성됐다면, 적용
	while (g_bRunning)
	{
		render();
	}
	// 밀리 세컨드 기준 1000 = 1초
	SDL_Quit();
	return 0;
}