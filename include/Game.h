#pragma once
#include"game.h"
#include "main.h"
#include "Player.h"

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

	Player player;
	BackGround Game_Bg;

	bool m_bRunning;

	enum State
	{
		IDLE, WALK, ATTACK, HIT, DEAD
	};

	// <플레이어의 이동 관련 변수>
	const int Pwalk_FrameW = 38;									// 플레이어의 이동 프레임 길이, 38
	const int Pwalk_FrameH = 58;									//						  높이, 58

	// <플레이어의 공격 관련 변수>
	const int PAtt_FrameW = 75;										// 플레이어의 공격 프레임 길이, 75
	const int PAtt_FrameH = 75;										//						  높이, 75

	// <플레이어의 점프 관련 변수>
	const int Ground_yPos = 310;									// 지면의 y좌표

	// <배경 이동>
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