#include "Game.h"
#include "main.h"

bool Game::init(const char* Stitle, int xpos, int ypos, int Swidth, int Sheight, int flags)
{
	// �����츦 ����
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

	m_bRunning = true;				// �����۵�

	m_pGdTexture = Text_Maker(adr_Char, &m_srcGd, &m_disGd, 1);
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
		ptSurface = SDL_LoadBMP(Par_Objname);							// �׸� �����͸� ������
	else
		ptSurface = IMG_Load(Par_Objname);

	texture = SDL_CreateTextureFromSurface(m_pRenderer, ptSurface);			// ������ �׸� �����͸� ������
	if (texture == nullptr)
		std::cout << "Error";

	SDL_FreeSurface(ptSurface);

	SDL_QueryTexture(texture, NULL, NULL, &scr->w, &scr->h);				// ���� �׸��� ũ�⸦ ��������

	dis->w = scr->w;		// 123
	dis->h = scr->h;		// 87

	dis->x = scr->x = 0;
	dis->y = scr->y = 0;

	Text_Ctrl(Par_Objname, scr, dis);

	return texture;
}
void Game::Text_Ctrl(const char* Par_Objname, SDL_Rect* scr, SDL_Rect* dis)
{
	if (Par_Objname == adr_Char) {
		dis->w = scr->w * 2;
		dis->h = scr->h * 2.3;

		dis->y = 400;
	}

	else if (Par_Objname == adr_Askull) {
		dis->w = scr->w * 1.3;
		dis->h = dis->h * 1.3;

		dis->x = 300;
		dis->y = 380;
	}

	else if (Par_Objname == adr_Kskull) {
		dis->w = scr->w * 1.3;
		dis->h = dis->h * 1.3;

		dis->x = 500;
		dis->y = 380;
	}
	else return;
}

// ���� �ڷ� : https://gamdekong.tistory.com/173

void Game::update()
{
	SDL_Delay(10);
	// ���� ���� ����
}

void Game::renderer()
{

	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);

	SDL_RenderCopy(m_pRenderer, m_pBgTexture, &m_srcBg, &m_disBg);
	SDL_RenderCopy(m_pRenderer, m_pGdTexture, &m_srcGd, &m_disGd);
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

	while (SDL_PollEvent(&gm_event)) {			// �̺�Ʈ �����
		switch (gm_event.type)
		{
		case SDL_QUIT:							// ����ڰ� ���Ḧ ���ҽ� ����
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

	SDL_DestroyTexture(m_pBgTexture);
	SDL_DestroyTexture(m_pGdTexture);
	SDL_DestroyTexture(m_pAxTexture);
	SDL_DestroyTexture(m_pKnTexture);

	SDL_Quit();
}