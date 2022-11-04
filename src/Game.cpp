#include "main.h"
#include<algorithm>

#include "Game.h"
#include "Player.h"
#include "Monster.h"

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

	if (!TheTextureManager::get_Instance()->load(adr_Dog, "Dog", m_pRenderer)) {
		return false;
	}

	if (!TheTextureManager::get_Instance()->load(adr_monster, "Monster", m_pRenderer)) {
		return false;
	}

	GameObject* m_GmObj = new GameObject;
	GameObject* m_player = new Player;
	GameObject* m_monster = new Monster;

	m_GmObj->load(100, 100, m_DogW, m_DogH, "Dog");
	m_player->load(300, 300, m_DogW, m_DogH, "Dog");
	//m_monster->load(200, 150, m_MonstW, m_MonstH, "Monster");

	m_gameObjects.push_back(m_GmObj);
	m_gameObjects.push_back(m_player);
	//m_gameObjects.push_back(m_monster);

	return m_bRunning;
}

void Game::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
		m_gameObjects[i]->update();

	// 게임 진행 내용
	//for_each(m_gameObjects.begin(), m_gameObjects.end(), [&](auto& game){
	//	game->update();
	//	});
}

void Game::renderer()
{
	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 0);

	for (int i = 0; i < m_gameObjects.size(); i++)
		m_gameObjects[i]->draw(m_pRenderer);

	//for_each(m_gameObjects.begin(), m_gameObjects.end(), [&](auto& game) {
	//	game->draw(m_pRenderer);
	//	});

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

	SDL_Quit();
}