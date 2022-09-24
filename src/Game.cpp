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

	// 1.왜 bmp확장자인가?
	SDL_Surface* ptSurface = SDL_LoadBMP("assets/rider.bmp");			// 그림 데이터를 가져옴
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, ptSurface);	// 가져온 그림 데이터를 가져옴

	if (m_pTexture == NULL)
		std::cout << "2";
	SDL_FreeSurface(ptSurface);

	// 2. 왜? 원본과 대상을 따로 분리할 필요가 있는가? -> 어차피 데이터를 
	//			똑같이 넣을거면, 다를 필요가 없다.
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_srcRect.w, &m_srcRect.h);	// 원본 그림의 크기를 가져오기

	m_disRect.w = m_srcRect.w;
	m_disRect.h = m_srcRect.h;

	m_disRect.x = m_srcRect.x = 0;
	m_disRect.y = m_srcRect.y = 0;

	return m_bRunning;
}

// 참고 자료 : https://gamdekong.tistory.com/173

void Game::update()
{
	// 게임 진행 내용
}

void Game::renderer()
{
	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);				// 검은색으로 표시
	// 텍스처의 일부를 현재 렌더링 대상에 복사합니다.
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_disRect);
	
	SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
	return m_bRunning;
}

void Game::handleEvent()
{
	SDL_Event gm_event;

	if (SDL_PollEvent(&gm_event)) {			// 이벤트 진행시
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
	SDL_Quit();
}