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

	m_pTexture = Text_Maker(adr_Rider, &m_srcRect, &m_disRect,0);

	if (m_pTexture == nullptr)
		std::cout << "1";

	return m_bRunning;
}

SDL_Texture* Game::Text_Maker(const char* Par_Objname, SDL_Rect* scr, SDL_Rect* dis, int extDif)
{
	SDL_Surface* ptSurface = NULL;
	SDL_Texture* texture = NULL;

	if(extDif == ext_bmp)
		ptSurface = SDL_LoadBMP(Par_Objname);							// 그림 데이터를 가져옴
	else
		ptSurface = IMG_Load(Par_Objname);

	texture = SDL_CreateTextureFromSurface(m_pRenderer, ptSurface);			// 가져온 그림 데이터를 가져옴
	SDL_FreeSurface(ptSurface);

	SDL_QueryTexture(texture, NULL, NULL, &scr->w, &scr->h);				// 원본 그림의 크기를 가져오기
	
	/* 2번째 과제 <임시> */

	// 공룡 다리가 나올 원본 상자의 크기
	const int wlegCut = 80;
	const int hlegCut = 45;

	// 공룡 다리가 나올 원본 상자의 좌표
	const int leg_xpos = 50;
	const int leg_ypos = 50;

	// 그림이 나올 좌표
	const int Texture_xPos = 50;
	const int Texture_yPos = 50;

	// 공룡 다리 좌표
	scr->x = leg_xpos;
	scr->y = leg_ypos;

	scr->w -= wlegCut;
	scr->h -= hlegCut;

	dis->w = scr->w;
	dis->h = scr->h;

	dis->x = Texture_xPos;
	dis->y = Texture_yPos;

	/* 3번째 과제 */
	/*
	int full_imageW = SCREEN_WIDTH - scr->w;
	int full_imageH = SCREEN_HEIGHT - scr->h;

	dis->w = scr->w + full_imageW;		// 123
	dis->h = scr->h + full_imageH;		// 87

	dis->x = scr->x = 0;
	dis->y = scr->y = 0;

	*/

	/* 4번째 과제 */
	/*
	dis->w = scr->w;		// 123
	dis->h = scr->h;		// 87

	dis->x = scr->x = 0;
	dis->y = scr->y = 0;
	*/

	return texture;
}

// 참고 자료 : https://gamdekong.tistory.com/173

void Game::update()
{
	SDL_Delay(10);
	// 게임 진행 내용
}

void Game::renderer()
{
	const int chgWay_Max = 640 - m_srcRect.w;			// 물체의 방향이 바뀌는 횟수

	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);

	// 1번째와 3번째 과제시, 사용
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_disRect);

	/* 2번째 실습 <임시> */
	/*
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_disRect);
	SDL_RenderCopy(m_pRenderer, m_pCutTexture, &m_srcCut, &m_disCut);
	SDL_SetTextureColorMod(m_pCutTexture,0,0,0);
	*/
	
	/* 4번째 과제 = SDL_RenderCopyEx 를 이용한 다양한 예제 만들기 */
	/*
	// 오른쪽으로 이동중
	if(obj_Speed >= 0)
		SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_srcRect, &m_disRect, 0, NULL, SDL_FLIP_HORIZONTAL);
	else
		SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_srcRect, &m_disRect, 0, NULL, SDL_FLIP_NONE);

	if (nChgWay_Cnt > chgWay_Max){
		obj_Speed = -obj_Speed;
		nChgWay_Cnt = 0;
	}

	m_disRect.x += obj_Speed;
	nChgWay_Cnt++;
	*/
	
	// 실행해보기
	/*
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_pRenderer);

	// 빨간색 큰 사각형, 시작점의 위치(x,y) + 너비와 높이 (w,y)를 이용해 그림
	SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_RenderFillRect(m_pRenderer, &fillRect);

	// 초록색 사각형의 테두리, 방법은 위와 동일
	SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
	SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);
	SDL_RenderDrawRect(m_pRenderer, &outlineRect);

	// 파란 실선, 시작 점(x,y) + 끝점(x,y)
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
	SDL_RenderDrawLine(m_pRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

	// 노란 점선, 스크린의 절반 맨 위쪽을 기준으로, 4간격으로 점을 찍음 (스크린 맨 아래까지)
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 0, 255);
	for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	{
		SDL_RenderDrawPoint(m_pRenderer, SCREEN_WIDTH / 2, i);
	}
	*/

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