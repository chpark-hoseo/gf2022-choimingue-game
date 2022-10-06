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

	m_pCTexture = Text_Maker(adr_Cat, &m_srcCat, &m_disCat, 1);		// 고양이 같은 개 사진
	m_disCat.w = m_srcCat.w = 128;
	m_disCat.y = 300;

	m_pDTexture = Text_Maker(adr_Dog, &m_srcDog, &m_disDog, 1);		// 강아지 사진

	m_pBgTexture = Text_Maker(adr_Bg, &m_srcBg, &m_disBg, 1);		// 배경 사진
	m_disBg.w = m_srcBg.w = 640;

	return m_bRunning;
}

SDL_Texture* Game::Text_Maker(const char* Par_Objname, SDL_Rect* scr, SDL_Rect* dis, int extDif)
{
	SDL_Surface* ptSurface = NULL;
	SDL_Texture* texture = NULL;

	if (extDif == ext_bmp)
		ptSurface = SDL_LoadBMP(Par_Objname);							// 그림 데이터를 가져옴
	else
		ptSurface = IMG_Load(Par_Objname);

	texture = SDL_CreateTextureFromSurface(m_pRenderer, ptSurface);			// 가져온 그림 데이터를 가져옴
	SDL_FreeSurface(ptSurface);

	SDL_QueryTexture(texture, NULL, NULL, &scr->w, &scr->h);				// 원본 그림의 크기를 가져오기

	dis->w = scr->w;
	dis->h = scr->h;

	dis->x = scr->x = 0;
	dis->y = scr->y = 0;

	return texture;
}

// 참고 자료 : https://gamdekong.tistory.com/173

void Game::update()
{
	// <이 부분을 바꿨습니다.>

	m_srcCat.x = 128 * ((SDL_GetTicks() / 100) % 6);

	m_disCat.x += 2;

	if (m_disCat.x >= 30 && m_disCat.x <= 90) {
		m_disCat.y = (float)1 / 5 * (m_disCat.x - 30) * (m_disCat.x - 90) + 300;
	}

	if (m_disDog.y < SCREEN_HEIGHT - m_disDog.h) {
		m_disDog.y += 9.81 + (m_disDog.y / 100.0);
	}

	SDL_Delay(20);

	// 게임 진행 내용
}

void Game::renderer()
{
	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);

	SDL_RenderCopy(m_pRenderer, m_pBgTexture, &m_srcBg, &m_disBg);				// 배경
	SDL_RenderCopy(m_pRenderer, m_pCTexture, &m_srcCat, &m_disCat);				// 움직이는 고양이
	SDL_RenderCopy(m_pRenderer, m_pDTexture, &m_srcDog, &m_disDog);				// 떨어지는 강아지

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

	SDL_DestroyTexture(m_pCTexture);

	SDL_Quit();
}