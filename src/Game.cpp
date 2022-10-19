#include "Game.h"
#include "main.h"

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

	textManger.load(adr_Char, "Player", m_pRenderer);
	textManger.load(adr_Bg, "BackGround", m_pRenderer);
	textManger.load(adr_Kskull, "Kskull", m_pRenderer);
	textManger.load(adr_Askull, "Askull", m_pRenderer);

	return m_bRunning;
}

// 참고 자료 : https://gamdekong.tistory.com/173

void Game::update()
{
	SDL_Delay(10);
	// 움직이기
	if (m_objState == WALK) {
		// 오른쪽 이동일때
		if (isRight) {
			// 오른쪽 시작점에 도착했고, 끝이 아니라면
			if (m_CurrPxpos + obj_pWSpeed >= m_BgStartP && m_BgMoveSpeed < m_BgEndP - SCREEN_WIDTH) {
				m_BgMoveSpeed += 3;
				obj_pWSpeed = 0;
				std::cout << m_BgMoveSpeed << std::endl;
			}

			// 배경 화면의 끝에 도닥했으나, 플레이어가 배경의 끝에 도달하지 않았을때
			else if (m_BgMoveSpeed >= m_BgEndP - SCREEN_WIDTH && m_CurrPxpos < SCREEN_WIDTH - Pwalk_FrameW) {
				m_BgMoveSpeed += 0;
				obj_pWSpeed = 3;
				std::cout << m_CurrPxpos << std::endl;
			}

			// 플레이어가 배경의 끝에 도달했을때
			else if (m_CurrPxpos >= SCREEN_WIDTH - Pwalk_FrameW) {
				obj_pWSpeed = 0;
			}

			// 그게 아니라, 처음 장소 ~ 출발 장소
			else {
				obj_pWSpeed = 3;
			}
		m_CurrPxpos += obj_pWSpeed;
		m_objCurrF = (SDL_GetTicks() / 100) % 8;

		}

		// 왼쪽 이동이라면
		else {

			// 배경 맨 왼쪽이면 움직임을 막는다.
			if (m_CurrPxpos + obj_pWSpeed <= 0)
				obj_pWSpeed = 0;

			// 배경 맨 왼쪽 ~ 시작점에 가기전
			else if (m_CurrPxpos > 0 && m_CurrPxpos <= m_BgStartP)
				obj_pWSpeed = -3;

			// 시작점을 넘어선다면, 배경이 움직이지 않도록
			else {
				obj_pWSpeed = -3;
				m_BgMoveSpeed += 0;
			}

			m_CurrPxpos += obj_pWSpeed;
			m_objCurrF = (SDL_GetTicks() / 100) % 8;
		}
	}

	// 공격하기
	else if (m_objState == ATTACK) {
		m_objCurrF = (SDL_GetTicks() / 100) % 6;
	}

	// 점프하기
	if (isJump) {
		// 최대 높이까지 도착하지 않았다면, 올라가기
		if(Player_yPos > Max_JumpH)
			Player_yPos -= obj_pJSpeed;

		// 최대 높이의 도달했다면, 떨어지기
		else {
			obj_pJSpeed = -obj_pJSpeed;
			Player_yPos -= obj_pJSpeed;
		}

		// 땅에 도착했다면, 점프 상태가 아님
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

	textManger.drawMove("BackGround", m_BgMoveSpeed, 30, m_pRenderer);

	if (isRight)
		textManger.drawFrame("Player", m_CurrPxpos, Player_yPos, m_objCurrFw, m_objCurrFh, m_objState * m_Intv_pFrame, m_objCurrF, m_pRenderer, SDL_FLIP_HORIZONTAL);

	else 
		textManger.drawFrame("Player", m_CurrPxpos, Player_yPos, m_objCurrFw, m_objCurrFh, m_objState * m_Intv_pFrame , m_objCurrF, m_pRenderer, SDL_FLIP_NONE);
	
	textManger.draw("Kskull", 500, Ground_yPos, 100, 100, m_pRenderer);
	textManger.draw("Askull", 300, Ground_yPos, 100, 100, m_pRenderer);
	
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

		case SDL_KEYDOWN:
			switch (gm_event.key.keysym.sym)
			{
			case SDLK_LEFT: // 왼쪽키, 이동
				m_objState = WALK;

				obj_pWSpeed = -2;
				isRight = false;

				m_objCurrFw = Pwalk_FrameW;
				m_objCurrFh = Pwalk_FrameH;
				m_objCurrF = 0;
				break;

			case SDLK_RIGHT: // 오른쪽키, 이동
				m_objState = WALK;
				
				obj_pWSpeed = 2;
				isRight = true;

				m_objCurrFw = Pwalk_FrameW;
				m_objCurrFh = Pwalk_FrameH;
				m_objCurrF = 0;
				break;

			case SDLK_a:	// a키, 공격
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
			//m_objState = IDLE;

			m_objCurrFw = Pwalk_FrameW;
			m_objCurrFh = Pwalk_FrameH;
			m_objCurrF = 0;
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

	textManger.Delet_Texture("Player");
	textManger.Delet_Texture("Kskull");
	textManger.Delet_Texture("Askull");
	textManger.Delet_Texture("BackGround");

	SDL_Quit();
}