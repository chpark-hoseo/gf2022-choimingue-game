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

	// <이 부분을 바꿨습니다.>
	m_pTexture = Text_Maker(adr_Char, &m_srcChar, &m_disChar, 1);
	m_pTexture_v2 = Text_Maker(adr_Char_ver2, &m_srcChar_v2, &m_disChar_v2, 1);

	if (m_pTexture == nullptr)
		std::cout << "1";

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

	// <이 부분을 바꿨습니다.>
	// 애니메이션 만드는 방법 : 원본과 대상을 크기에 따라 잘라줌 + 원본 상자의 x 좌표를 이동하면서 애니메이션을 진행
	dis->w = scr->w = 89;
	dis->h = scr->h;

	dis->x = scr->x = 0;
	dis->y = scr->y = 0;

	m_disChar.x = 400;
	m_disChar.y = 200;
	m_disChar_v2.x = 500;

	return texture;
}

// 참고 자료 : https://gamdekong.tistory.com/173

void Game::update()
{
	// <이 부분을 바꿨습니다.>

	m_srcChar.x = 89 * ((SDL_GetTicks() / 100) % 8);
	m_srcChar_v2.x = 89 * ((SDL_GetTicks() / 50) % 8);

	// <<산을 타는 움직임을 재현했습니다.>>

	SDL_Delay(50);

	if (m_disChar.x <= 400 && m_disChar.x >= 300) {
		m_angle ++;
		m_disChar.x -= 3;
		m_disChar.y -= 3;
	}

	else if (m_disChar.x < 300) {
		if (m_angle >= 0) {
			m_angle -= 4;
			m_disChar.y -= 1;
			std::cout << m_angle;
		}
			m_disChar.x -= 3;
	}

	// 게임 진행 내용
}

void Game::renderer()
{
	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);

	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_srcChar, &m_disChar, m_angle, NULL, SDL_FLIP_NONE);
	SDL_RenderCopy(m_pRenderer, m_pTexture_v2, &m_srcChar_v2, &m_disChar_v2);

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

	SDL_DestroyTexture(m_pTexture);

	SDL_Quit();
}