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

	// 1.�� bmpȮ�����ΰ�?
	SDL_Surface* ptSurface = SDL_LoadBMP("assets/rider.bmp");			// �׸� �����͸� ������
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, ptSurface);	// ������ �׸� �����͸� ������

	if (m_pTexture == NULL)
		std::cout << "2";
	SDL_FreeSurface(ptSurface);

	// 2. ��? ������ ����� ���� �и��� �ʿ䰡 �ִ°�? -> ������ �����͸� 
	//			�Ȱ��� �����Ÿ�, �ٸ� �ʿ䰡 ����.
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_srcRect.w, &m_srcRect.h);	// ���� �׸��� ũ�⸦ ��������

	m_disRect.w = m_srcRect.w;
	m_disRect.h = m_srcRect.h;

	m_disRect.x = m_srcRect.x = 0;
	m_disRect.y = m_srcRect.y = 0;

	return m_bRunning;
}

// ���� �ڷ� : https://gamdekong.tistory.com/173

void Game::update()
{
	// ���� ���� ����
}

void Game::renderer()
{
	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);				// ���������� ǥ��
	// �ؽ�ó�� �Ϻθ� ���� ������ ��� �����մϴ�.
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
	SDL_Quit();
}