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

	if (m_pTexture == nullptr)
		std::cout << "1";

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

	SDL_QueryTexture(texture, NULL, NULL, &scr->w, &scr->h);				// ���� �׸��� ũ�⸦ ��������

	/* 3��° ���� */

	dis->w = SCREEN_WIDTH;
	dis->h = SCREEN_HEIGHT;

	dis->x = scr->x = 0;
	dis->y = scr->y = 0;

	/* 4��° ���� */
	/*
	dis->w = scr->w;		// 123
	dis->h = scr->h;		// 87

	dis->x = scr->x = 0;
	dis->y = scr->y = 0;
	*/

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

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);

	// 1��°�� 3��° ������, ���
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_disRect);

	/* 2��° �ǽ� <�ӽ�> */
	/*
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_disRect);
	SDL_RenderCopy(m_pRenderer, m_pCutTexture, &m_srcCut, &m_disCut);
	SDL_SetTextureColorMod(m_pCutTexture,0,0,0);
	*/
	
	/* 4��° ���� = SDL_RenderCopyEx �� �̿��� �پ��� ���� ����� */
	/*
	// ���������� �̵���
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
	
	// �����غ���
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