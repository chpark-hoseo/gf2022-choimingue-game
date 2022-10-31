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

	if (!TheTextureManager::get_Instance()->load(adr_Dog, "Dog", m_pRenderer)) {
		return false;
	}

	if (!TheTextureManager::get_Instance()->load(adr_monster, "Monster", m_pRenderer)) {
		return false;
	}

	m_GmObj.load(100, 100, m_DogW, m_DogH, "Dog");
	m_GmPl.load(300, 300, m_DogW, m_DogH, "Dog");

	m_GmMonster_slow.load(200, 150, m_MonstW, m_MonstH, "Monster");
	m_GmMonster_fast.load(300, 200, m_MonstW, m_MonstH, "Monster");

	return m_bRunning;
}

void Game::update()
{
	// ���� ���� ����
	m_GmObj.update();
	m_GmPl.update();

	m_GmMonster_slow.update(SCREEN_WIDTH, m_slowSpeed);
	m_GmMonster_fast.update(SCREEN_WIDTH, m_fastSpeed);
}

void Game::renderer()
{
	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 0);

	m_GmObj.draw(m_pRenderer);
	m_GmPl.draw(m_pRenderer);

	m_GmMonster_slow.draw(m_pRenderer);
	m_GmMonster_fast.draw(m_pRenderer);

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

	SDL_Quit();
}