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

	// <�� �κ��� �ٲ���ϴ�.>
	m_pTexture = Text_Maker(adr_Cat, &m_srcCat, &m_disCat, 1);

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
	SDL_FreeSurface(ptSurface);

	SDL_QueryTexture(texture, NULL, NULL, &scr->w, &scr->h);				// ���� �׸��� ũ�⸦ ��������

	// <�� �κ��� �ٲ���ϴ�.>
	// �ִϸ��̼� ����� ��� : ������ ����� ũ�⿡ ���� �߶��� + ���� ������ x ��ǥ�� �̵��ϸ鼭 �ִϸ��̼��� ����
	dis->w = scr->w = 128;
	dis->h = scr->h;

	dis->x = scr->x = 0;
	dis->y = scr->y = 0;

	return texture;
}

// ���� �ڷ� : https://gamdekong.tistory.com/173

void Game::update()
{
	// <�� �κ��� �ٲ���ϴ�.>

	m_srcCat.x = 128 * ((SDL_GetTicks() / 100) % 6);

	// ���� ���� ����
}

void Game::renderer()
{
	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);

	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcCat, &m_disCat);

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

	SDL_DestroyTexture(m_pTexture);

	SDL_Quit();
}