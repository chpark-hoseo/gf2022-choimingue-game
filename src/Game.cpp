#include "main.h"
#include "Game.h"

#include "InputHandler.h"
#include "TextManger.h"
#include "LoaderParams.h"
#include "BattleManger.h"
#include "InterfaceManger.h"
#include "SponManger.h"
#include "ColliderManger.h"

#include "BackGround.h"
#include "Player.h"
#include "ASkull.h"

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

	BackGround* m_GmBg = new BackGround(new LoaderParams(0, 45, SCREEN_WIDTH, SCREEN_HEIGHT, "BackGround"));
	Player* m_player = new Player(new LoaderParams(0, m_GmBg->getGroundyPos(), Pwalk_FrameW, Pwalk_FrameH, "Player"));

	// 플레이어
	if (!The_TextMananger::Instance()->load(adr_Char, "Player", m_pRenderer))
		return false;

	// 배경
	if (!The_TextMananger::Instance()->load(adr_Bg, "BackGround", m_pRenderer))
		return false;

	//Kskull
	if (!The_TextMananger::Instance()->load(adr_Kskull, "Kskull", m_pRenderer))
		return false;

	//ASkull
	if (!The_TextMananger::Instance()->load(adr_Askull, "Askull", m_pRenderer))
		return false;

	// 보물상자 로딩
	if (!The_TextMananger::Instance()->load(adr_TBox, "TBox", m_pRenderer))
		return false;

	// 게임 오버
	if (!The_TextMananger::Instance()->load(adr_GameOver, "GameOver", m_pRenderer))
		return false;

	// 게임 엔딩
	if (!The_TextMananger::Instance()->load(adr_GameEnding, "GameEnding", m_pRenderer))
		return false;

	m_GmBg->setPlayerData(m_player);

	TheBattleManger::Instance()->setGamePlayer(m_player);
	TheInterfaceManger::Instance()->setDefaltData(m_player);
	TheSponManger::Instance()->setBgData(m_GmBg);
	TheColiiderManger::Instance()->setPlayerData(m_player);

	m_gameObjects.push_back(m_GmBg);
	m_gameObjects.push_back(m_player);

	return m_bRunning;
}

void Game::update()
{
	if (TheSponManger::Instance()->addGameobj() != NULL)
		m_gameObjects.push_back(TheSponManger::Instance()->addGameobj());

	TheBattleManger::Instance()->update();

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
			game->draw();
		});
	
	TheInterfaceManger::Instance()->gameOverdraw();
	TheInterfaceManger::Instance()->gameEndingdraw();

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
			game = NULL;
		});

	SDL_Quit();

	TheInputHandler::Instance()->clean();
}

Game* Game::s_pInstatance = 0;