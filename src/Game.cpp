#include "Game.h"
#include "main.h"

bool Game::init(const char* Stitle, int xpos, int ypos, int Swidth, int Sheight, int flags)
{
	// 윈도우를 생성
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
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

	m_textManger.load(adr_Dog, "Dog", m_pRenderer);
	m_textManger.load(adr_Dog, "Dog_ani", m_pRenderer);

	m_textManger.load(adr_Char, "Player", m_pRenderer);

	return m_bRunning;
}

// 참고 자료 : https://gamdekong.tistory.com/173

void Game::update()
{
	// 게임 진행 내용
	m_DogCurrFrame = ((SDL_GetTicks() / 100) % 6);

	m_CharWalkFrame = ((SDL_GetTicks() / 100) % 8);
	m_CharAttFrame = ((SDL_GetTicks() / 100) % 6);
}

void Game::renderer()
{
	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 0);

	m_textManger.draw("Dog", 0, 0, m_DogW, m_DogH, m_pRenderer);
	m_textManger.drawFrame("Dog_ani", 100, 100, m_DogW, m_DogH, 0, m_DogCurrFrame, m_pRenderer);

	// 플레이어가 걷는 모습
	m_textManger.drawFrame("Player", 200, 200, walk_CharW, m_CharH, 0, m_CharWalkFrame, m_pRenderer);
	
	// 플레이어가 공격하는 모습
	m_textManger.drawFrame("Player", 300, 300, att_CharW, m_CharH, 1, m_CharAttFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
	return m_bRunning;
}

void Game::handleEvent()
{
	SDL_Event gm_event;

	while (SDL_PollEvent(&gm_event)) {			// 이벤트 진행시
		switch (gm_event.type)
		{
		case SDL_QUIT:							// 사용자가 종료를 원할시 종료
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

	//SDL_DestroyTexture(m_pTexture);

	SDL_Quit();
}