#include "Game.h"
#include "main.h"

bool Game::init(const char* Stitle, int xpos, int ypos, int Swidth, int Sheight, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		// 윈도우를 생성
		m_pWindow = SDL_CreateWindow(Stitle, xpos, ypos, Swidth, Sheight, flags);

		if (m_pWindow != NULL) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != NULL)
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			else
				return false;
		}
		else
			return false;
	}
	else 
		return false;

	m_bRunning = true;				// 정상작동
	return m_bRunning;
}

void Game::update()
{
	// 게임 진행 내용
}

void Game::renderer()
{
	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);				// 검은색으로 표시
	SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
	return m_bRunning;
}

void Game::handleEvent()
{
	SDL_Event gm_event;

	if (SDL_PollEvent(&gm_event))			// 이벤트 진행시
	{
		switch (gm_event.type)
		{
		case SDL_QUIT:						// 사용자가 종료를 원할시 종료
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}