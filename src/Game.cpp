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

	m_pZdTexture = Text_Maker(adr_Char, &m_srcZd, &m_disZd, 1);
	m_disZd.w = m_srcZd.w = Pwalk_FrameW;

	m_pBgTexture = Text_Maker(adr_Bg, &m_srcBg, &m_disBg, 1);
	m_pKnTexture = Text_Maker(adr_Kskull, &m_srcKn, &m_disKn, 1);
	m_pAxTexture = Text_Maker(adr_Askull, &m_srcAx, &m_disAx, 1);

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
	if (texture == nullptr)
		std::cout << "Error";

	SDL_FreeSurface(ptSurface);

	SDL_QueryTexture(texture, NULL, NULL, &scr->w, &scr->h);				// 원본 그림의 크기를 가져오기

	dis->w = scr->w;			// 123
	dis->h = scr->h;			// 87

	dis->x = scr->x = 0;
	dis->y = scr->y = 0;

	Text_Ctrl(Par_Objname, scr, dis);

	return texture;
}
void Game::Text_Ctrl(const char* Par_Objname, SDL_Rect* scr, SDL_Rect* dis)
{
	if (Par_Objname == adr_Char) {
		dis->y = 310;
	}

	// 몬스터들은 1.3배 키움
	else if (Par_Objname == adr_Askull) {
		dis->w = scr->w * 1.3;
		dis->h = dis->h * 1.3;

		dis->x = 300;
		dis->y = 310;
	}

	else if (Par_Objname == adr_Kskull) {
		dis->w = scr->w * 1.3;
		dis->h = dis->h * 1.3;

		dis->x = 500;
		dis->y = 300;
	}
	else
		dis->y = 50;
}

// 참고 자료 : https://gamdekong.tistory.com/173

void Game::update()
{
	SDL_Delay(10);
	// 게임 진행 내용
	if (obj_AniFrame == Pwalk_FrameW) {
		m_srcZd.x = 0;
		m_srcZd.x = obj_AniFrame * (SDL_GetTicks() / 100 % 8);
	}

	else if (obj_AniFrame == PAttack_FrameW) {
		m_srcZd.x = 0;
		m_srcZd.x = Pwalk_FrameW * 8 + obj_AniFrame * (SDL_GetTicks() / 100 % 6);
	}

	else 
		m_srcZd.x = 0;
}

void Game::renderer()
{

	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);


	SDL_RenderCopy(m_pRenderer, m_pBgTexture, &m_srcBg, &m_disBg);

	if(isRight)
		SDL_RenderCopyEx(m_pRenderer, m_pZdTexture, &m_srcZd, &m_disZd, 0, NULL,SDL_FLIP_HORIZONTAL);

	else
		SDL_RenderCopy(m_pRenderer, m_pZdTexture, &m_srcZd, &m_disZd);
	
	SDL_RenderCopy(m_pRenderer, m_pKnTexture, &m_srcKn, &m_disKn);
	SDL_RenderCopy(m_pRenderer, m_pAxTexture, &m_srcAx, &m_disAx);

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
		case SDL_KEYDOWN:
			switch (gm_event.key.keysym.sym)
			{
			case SDLK_LEFT: // 왼쪽키, 이동
				m_disZd.x -= obj_pWSpeed;
				isRight = false;
				obj_AniFrame = Pwalk_FrameW;
				break;

			case SDLK_RIGHT: // 오른쪽키, 이동
				m_disZd.x += obj_pWSpeed;
				isRight = true;
				obj_AniFrame = Pwalk_FrameW;
				break;

			case SDLK_a:	// a키, 이동
				m_disZd.w = m_srcZd.w = PAttack_FrameW;
				obj_AniFrame = PAttack_FrameW;
				break;

			default:
				break;
			}
			break;
		case SDL_KEYUP:
			m_disZd.w = m_srcZd.w = Pwalk_FrameW;
			obj_AniFrame = 0;
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

	SDL_DestroyTexture(m_pBgTexture);
	SDL_DestroyTexture(m_pZdTexture);
	SDL_DestroyTexture(m_pAxTexture);
	SDL_DestroyTexture(m_pKnTexture);

	SDL_Quit();
}