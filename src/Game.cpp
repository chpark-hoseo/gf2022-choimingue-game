#include "Game.h"
#include "main.h"

bool Game::init(const char* Stitle, int xpos, int ypos, int Swidth, int Sheight, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		// �����츦 ����
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
	return m_bRunning;
}

void Game::update()
{
	// ���� ���� ����
}

void Game::renderer()
{
	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);				// ���������� ǥ��
	SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
	return m_bRunning;
}

void Game::handleEvent()
{
	SDL_Event gm_event;

	if (SDL_PollEvent(&gm_event))			// �̺�Ʈ �����
	{
		switch (gm_event.type)
		{
		case SDL_QUIT:						// ����ڰ� ���Ḧ ���ҽ� ����
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