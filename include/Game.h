#pragma once
#include"game.h"
#include "main.h"

class Game
{
public:
	// 윈도우 크기
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 480;

	// 윈도우 생성
	bool init(const char* Stitle, int xpos, int ypos, int Swidth, int Sheight, int flags);

	// 게임 내용 수정
	void update();

	// 화면 띄우기
	void renderer();

	// 정상작동중인지 확인
	bool running();

	// 종료 설정
	void handleEvent();

	// 화면 지우기
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;

	bool m_bRunning;

	enum State
	{
		IDLE, WALK, ATTACK, HIT, DEAD
	};

	int m_anit_Pw = 0;
	int m_anit_Pa = 0;
	int m_anifSpeed = 15;

	// <플레이어가 현재 어떤 상태인지에 따라 달라짐>
	int m_objState = IDLE;											// 플레이어의 현재 상태
	int m_objCurrFw = 38;											// 플레이어가 현재 어떤 프레임이고, 너비가 얼만지
	int m_objCurrFh = 58;											//									길이가 얼만지
	int m_Intv_pFrame = 75;											// 프레임 마다의 간격
	int m_objCurrF = 0;												// 플레이어는 현재 몇번째 프레임인지

	// <플레이어의 속도 관련 변수>
	int obj_pWSpeed = 0;											// 플레이어 속도
	float obj_pJSpeed = 1;											// 플레이어의 점프 속도

	bool isRight = false;											// 오른쪽 방향인지 확인
	bool isAttack = false;											// 플레이어가 공격하는지 확인
	bool isJump = false;											// 플레이어가 점프하는지 확인

	// <플레이어의 이동 관련 변수>
	const int Pwalk_FrameW = 38;									// 플레이어의 이동 프레임 길이, 38
	const int Pwalk_FrameH = 58;									//						  높이, 58
	int m_CurrPxpos = 0;											// 현재 플레이어의 x좌표

	// <플레이어의 공격 관련 변수>
	const int PAtt_FrameW = 75;										// 플레이어의 공격 프레임 길이, 75
	const int PAtt_FrameH = 75;										//						  높이, 75
	int m_CurrPAttF = 0;											// 플레이어의 현재 공격 프레임

	// <플레이어의 점프 관련 변수>
	int Player_yPos = 310;											// 플레이어의 y좌표, 초기값 = 지면의 y좌표
	const int Ground_yPos = 310;									// 지면의 y좌표
	const int Max_JumpH = Ground_yPos - 60;							// 최대 점프 높이 (지면의 높이 : 310 - 최대 점프 높이 : 45 )

	// <배경 이동>
	const int m_BgStartP = SCREEN_WIDTH / 3.0;						// 배경이 움직이기 시작하는 시점
	int m_BgMoveSpeed = 0;											// 배경이 움직이는 속도
	int m_BgEndP = 5000;											// 배경이 끝나는 시점
	int m_BgMoveEndP = m_BgEndP - SCREEN_WIDTH / 3.0;				// 끝나는 점

	// <도끼병 관련 변수>
	int m_AxSk_Speed = 0;											// 도끼병의 다가오는 속도
	int m_AxSk_xPos = 500;											// 도끼병의 x 좌표
	int m_AxSk_State = 0;											// 현재 도끼병의 상태

	int m_AxSkHp = 50;
	int m_AxSkCurrFh = 47;											// 현재 프레임 간격
	int m_AxSkCurrF = 0;											// 현재 몇번째 프레임


	const char* adr_Char = "assets/Zelda_Walk+Attack.png";			// 젤다의 그림 주소
	const char* adr_Bg = "assets/Back_Ground2.png";					// 배경 그림의 주소
	const char* adr_Kskull = "assets/KnifeSkull_Idle.png";			// 칼병 병사의 주소
	const char* adr_Askull = "assets/AxeSkull_Full.png";			// 도끼 병사의 주소
};