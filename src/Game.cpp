#include "main.h"
#include "Game.h"

#include "InputHandler.h"
#include "TextManger.h"
#include "BackGround.h"
#include "Player.h"

#include <algorithm>

SDL_Renderer* Game::getRenderer() const
{
	return m_pRenderer;
}

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

	Player* m_player = new Player(); 
	BackGround* m_GmBg = new BackGround(m_player);

	// 플레이어
	if (!The_TextMananger::Instance()->load(adr_Char, "Player", m_pRenderer))
		return false;

	m_player->load(0, 0, Pwalk_FrameW, Pwalk_FrameH, "Player");

	// 칼든 병사
	if (!The_TextMananger::Instance()->load(adr_Kskull, "Kskull", m_pRenderer))
		return false;

	//도끼 병사
	if (!The_TextMananger::Instance()->load(adr_Askull, "Askull", m_pRenderer))
		return false;

	if (!The_TextMananger::Instance()->load(adr_Bg, "BackGround", m_pRenderer))
		return false;

	m_GmBg->load(0, 50, SCREEN_WIDTH, SCREEN_HEIGHT,"BackGround");

	m_gameObjects.push_back(m_GmBg);
	m_gameObjects.push_back(m_player);

	return m_bRunning;
}

void Game::update()
{

	SDL_Delay(10);

	for_each(m_gameObjects.begin(), m_gameObjects.end(), [&](auto game)
		{
			game->update();
		});
}

void Game::renderer()
{

	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

	for_each(m_gameObjects.begin(), m_gameObjects.end(), [&](auto game)
		{
			game->draw(m_pRenderer);
		});
	
	//The_TextMananger::Instance()->drawFrame("Kskull", 300, Ground_yPos - 48, 48, 48, 0, 0, m_pRenderer, SDL_FLIP_NONE);
	The_TextMananger::Instance()->drawFrame("Askull", m_AxSk_xPos, Ground_yPos, m_AxSkCurrFh, 48, m_AxSk_State * 50, m_AxSkCurrF, m_pRenderer, SDL_FLIP_NONE);

	SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
	return m_bRunning;
}

void Game::quit()
{
	m_bRunning = false;
}

void Game::handleEvent()
{
	TheInputHandler::Instance()->update();
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);

	for_each(m_gameObjects.begin(), m_gameObjects.end(), [&](auto game)
		{
			game->clean();
		});

	SDL_Quit();

	TheInputHandler::Instance()->clean();
}

Game* Game::s_pInstatance = 0;