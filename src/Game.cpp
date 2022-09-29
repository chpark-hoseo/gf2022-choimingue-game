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

	m_pTexture = Text_Maker(adr_Rider, &m_srcRect, &m_disRect,0);

	return m_bRunning;
}

SDL_Texture* Game::Text_Maker(const char* Par_Objname, SDL_Rect* scr, SDL_Rect* dis, int extDif)
{
	SDL_Surface* ptSurface = NULL;
	SDL_Texture* texture = NULL;

	if(extDif == ext_bmp)
		ptSurface = SDL_LoadBMP(Par_Objname);							// �׸� �����͸� ������
	else
		ptSurface = IMG_Load(Par_Objname);

	texture = SDL_CreateTextureFromSurface(m_pRenderer, ptSurface);			// ������ �׸� �����͸� ������
	SDL_FreeSurface(ptSurface);

	SDL_QueryTexture(texture, NULL, NULL, &scr->w, &scr->h);					// ���� �׸��� ũ�⸦ ��������

	int wCut = 75;
	int hCut = 40;

	dis->w = scr->w - wCut;		// 123
	dis->h = scr->h - hCut;		// 87

	dis->x = scr->x = 0;
	dis->y = scr->y = 0;

	scr->x = - wCut;
	scr->y = - hCut;

	return texture;
}

// ���� �ڷ� : https://gamdekong.tistory.com/173

void Game::update()
{
	SDL_Delay(10);
	// ���� ���� ����
}

void Game::renderer()
{
	const int chgWay_Max = 640 - m_srcRect.w;			// ��ü�� ������ �ٲ�� Ƚ��

	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 0);

	// �ؽ�ó�� �Ϻθ� ���� ������ ��� �����մϴ�.
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_disRect);
	
	SDL_RenderPresent(m_pRenderer);
	
	/*
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_pRenderer);

	// ������ ū �簢��, �������� ��ġ(x,y) + �ʺ�� ���� (w,y)�� �̿��� �׸�
	SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_RenderFillRect(m_pRenderer, &fillRect);

	// �ʷϻ� �簢���� �׵θ�, ����� ���� ����
	SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
	SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);
	SDL_RenderDrawRect(m_pRenderer, &outlineRect);

	// �Ķ� �Ǽ�, ���� ��(x,y) + ����(x,y)
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
	SDL_RenderDrawLine(m_pRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

	// ��� ����, ��ũ���� ���� �� ������ ��������, 4�������� ���� ���� (��ũ�� �� �Ʒ�����)
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 0, 255);
	for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	{
		SDL_RenderDrawPoint(m_pRenderer, SCREEN_WIDTH / 2, i);
	}

	SDL_RenderPresent(m_pRenderer);
	*/
}

bool Game::running()
{
	return m_bRunning;
}

void Game::handleEvent()
{
	SDL_Event gm_event;

	if (SDL_PollEvent(&gm_event)) {			// �̺�Ʈ �����
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