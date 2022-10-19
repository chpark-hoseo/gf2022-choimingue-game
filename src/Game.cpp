#include "Game.h"
#include "main.h"
#include "TextManger.h"

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

	// �÷��̾�
	if (!The_TextMananger::Instance()->load(adr_Char, "Player", m_pRenderer))
		return false;

	// �׸�
	if (!The_TextMananger::Instance()->load(adr_Bg, "BackGround", m_pRenderer))
		return false;

	// Į�� ����
	if (!The_TextMananger::Instance()->load(adr_Kskull, "Kskull", m_pRenderer))
		return false;

	//���� ����
	if (!The_TextMananger::Instance()->load(adr_Askull, "Askull", m_pRenderer))
		return false;

	return m_bRunning;
}

// ���� �ڷ� : https://gamdekong.tistory.com/173

void Game::update()
{

	SDL_Delay(8);
	// �����̱�
	if (m_objState == WALK) {

		m_anit_Pw += m_anifSpeed;

		// ������ �̵��϶�
		if (isRight) {
			// ������ �������� �����߰�, ���� �ƴ϶��
			if (m_CurrPxpos + obj_pWSpeed >= m_BgStartP && m_BgMoveSpeed < m_BgEndP - SCREEN_WIDTH) {
				m_BgMoveSpeed += 3;
				obj_pWSpeed = 0;
				std::cout << m_BgMoveSpeed << std::endl;
			}

			// ��� ȭ���� ���� ����������, �÷��̾ ����� ���� �������� �ʾ�����
			else if (m_BgMoveSpeed >= m_BgEndP - SCREEN_WIDTH && m_CurrPxpos < SCREEN_WIDTH - Pwalk_FrameW) {
				m_BgMoveSpeed += 0;
				obj_pWSpeed = 3;
				std::cout << m_CurrPxpos << std::endl;
			}

			// �÷��̾ ����� ���� ����������
			else if (m_CurrPxpos >= SCREEN_WIDTH - Pwalk_FrameW) {
				obj_pWSpeed = 0;
			}

			// �װ� �ƴ϶�, ó�� ��� ~ ��� ���
			else {
				obj_pWSpeed = 3;
			}
		m_CurrPxpos += obj_pWSpeed;
		m_objCurrF = (m_anit_Pw / 100) % 8;

		}

		// ���� �̵��̶��
		else {

			// ��� �� �����̸� �������� ���´�.
			if (m_CurrPxpos + obj_pWSpeed <= 0)
				obj_pWSpeed = 0;

			// ��� �� ���� ~ �������� ������
			else if (m_CurrPxpos > 0 && m_CurrPxpos <= m_BgStartP)
				obj_pWSpeed = -3;

			// �������� �Ѿ�ٸ�, ����� �������� �ʵ���
			else {
				obj_pWSpeed = -3;
				m_BgMoveSpeed += 0;
			}

			m_CurrPxpos += obj_pWSpeed;
			m_objCurrF = (m_anit_Pw / 100) % 8;
		}
	}

	// �����ϱ�
	else if (m_objState == ATTACK) {

		m_anit_Pa += m_anifSpeed;
		m_objCurrF = (m_anit_Pa / 100) % 6;
	}

	// IDLE
	else{
		m_objCurrFw = Pwalk_FrameW;
		m_objCurrFh = Pwalk_FrameH;
		m_objCurrF = 0;

		m_anit_Pw = 0;
		m_anit_Pa = 0;
	}

	// �����ϱ�
	if (isJump) {
		// �ִ� ���̱��� �������� �ʾҴٸ�, �ö󰡱�
		if(Player_yPos > Max_JumpH)
			Player_yPos -= obj_pJSpeed;

		// �ִ� ������ �����ߴٸ�, ��������
		else {
			obj_pJSpeed = -obj_pJSpeed;
			Player_yPos -= obj_pJSpeed;
		}

		// ���� �����ߴٸ�, ���� ���°� �ƴ�
		if (Player_yPos >= Ground_yPos) {
			isJump = false;
			obj_pJSpeed = -obj_pJSpeed;
		}
	}
}

void Game::renderer()
{

	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

	The_TextMananger::Instance()->drawMove("BackGround", m_BgMoveSpeed, 30, m_pRenderer);

	if (isRight)
		The_TextMananger::Instance()->drawFrame("Player", m_CurrPxpos, Player_yPos, m_objCurrFw, m_objCurrFh, m_objState * m_Intv_pFrame, m_objCurrF, m_pRenderer, SDL_FLIP_HORIZONTAL);

	else 
		The_TextMananger::Instance()->drawFrame("Player", m_CurrPxpos, Player_yPos, m_objCurrFw, m_objCurrFh, m_objState * m_Intv_pFrame , m_objCurrF, m_pRenderer, SDL_FLIP_NONE);
	
	The_TextMananger::Instance()->draw("Kskull", 500, Ground_yPos, 100, 100, m_pRenderer);
	The_TextMananger::Instance()->draw("Askull", 300, Ground_yPos, 100, 100, m_pRenderer);
	
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
				m_objState = WALK;

				obj_pWSpeed = -2;
				isRight = false;

				m_objCurrFw = Pwalk_FrameW;
				m_objCurrFh = Pwalk_FrameH;
				m_objCurrF = 0;
				break;

			case SDLK_RIGHT: // ������Ű, �̵�
				m_objState = WALK;
				
				obj_pWSpeed = 2;
				isRight = true;

				m_objCurrFw = Pwalk_FrameW;
				m_objCurrFh = Pwalk_FrameH;
				m_objCurrF = 0;
				break;

			case SDLK_a:	// aŰ, ����
				m_objState = ATTACK;

				m_objCurrFw = PAtt_FrameW;
				m_objCurrFh = PAtt_FrameH;
				m_objCurrF = 0;
				break;

			case SDLK_SPACE:
				isJump = true;
				break;

			default:
				break;
			}
			break;

		case SDL_KEYUP:
			m_objState = IDLE;

			//std::cout << "dd";
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

	The_TextMananger::Instance()->Delet_Texture("Player");
	The_TextMananger::Instance()->Delet_Texture("Kskull");
	The_TextMananger::Instance()->Delet_Texture("Askull");
	The_TextMananger::Instance()->Delet_Texture("BackGround");

	SDL_Quit();
}