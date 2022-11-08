#include "Game.h"
#include "main.h"
#include "TextManger.h"
#include <algorithm>

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

	// ���

	GameObject* m_GmBg = new GameObject();
	GameObject* m_player = new GameObject();

	// �÷��̾�
	if (!The_TextMananger::Instance()->load(adr_Char, "Player", m_pRenderer))
		return false;

	m_player->load(0, Ground_yPos, Pwalk_FrameW, Pwalk_FrameH, "Player");
	//m_player(&Game_Bg);

	// Į�� ����
	if (!The_TextMananger::Instance()->load(adr_Kskull, "Kskull", m_pRenderer))
		return false;

	//���� ����
	if (!The_TextMananger::Instance()->load(adr_Askull, "Askull", m_pRenderer))
		return false;

	if (!The_TextMananger::Instance()->load(adr_Bg, "BackGround", m_pRenderer))
		return false;

	m_GmBg->load(0, 30, SCREEN_WIDTH, SCREEN_HEIGHT,"BackGround");

	m_gameObjects.push_back(m_GmBg);
	m_gameObjects.push_back(m_player);

	return m_bRunning;
}

// ���� �ڷ� : https://gamdekong.tistory.com/173

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

void Game::handleEvent()
{
	SDL_Event gm_event;

	while (SDL_PollEvent(&gm_event)) {			// �̺�Ʈ �����
		switch (gm_event.type)
		{
		case SDL_QUIT:							// ����ڰ� ���Ḧ ���ҽ� ����
			m_bRunning = false;
			break;

		case SDL_KEYDOWN:
			switch (gm_event.key.keysym.sym)
			{
			case SDLK_LEFT: // ����Ű, �̵�
				
				//player.setState(WALK);
				//player.setData(Pwalk_FrameW, Pwalk_FrameH);
				//player.setWalkData(-2, false);
				break;

			case SDLK_RIGHT: // ������Ű, �̵�

				//player.setState(WALK);
				//player.setData(Pwalk_FrameW, Pwalk_FrameH);
				//player.setWalkData(2, true);
				break;

			case SDLK_a:	// aŰ, ����

				//player.setState(ATTACK);
				//player.setData(PAtt_FrameW, PAtt_FrameH);
				break;

			case SDLK_SPACE:
				//player.setIsJump(true);
				break;

			default:
				break;
			}
			break;

		case SDL_KEYUP:

			//if (player.getState() == WALK && player.getIsJump() == true) {
			if(1){
				//player.setState(WALK);
				if (gm_event.key.keysym.sym == SDLK_RIGHT ||
					gm_event.key.keysym.sym == SDLK_LEFT)
				{
					//player.setState(IDLE);
				}
			}
			else
				//player.setState(IDLE);
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

	for_each(m_gameObjects.begin(), m_gameObjects.end(), [&](auto game)
		{
			game->clean();
		});

	SDL_Quit();
}