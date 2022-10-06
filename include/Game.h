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
	bool m_bRunning;

	SDL_Texture* m_pZdTexture;		// 플레이어(젤다)
	SDL_Rect m_srcZd;
	SDL_Rect m_disZd;

	SDL_Texture* m_pBgTexture;		// 배경
	SDL_Rect m_srcBg;
	SDL_Rect m_disBg;

	SDL_Texture* m_pKnTexture;		// 칼병 병사
	SDL_Rect m_srcKn;
	SDL_Rect m_disKn;

	SDL_Texture* m_pAxTexture;		// 도끼 병사
	SDL_Rect m_srcAx;
	SDL_Rect m_disAx;

	// 이미지를 받아오는 함수 + bmp는 0, png는 1이다.
	SDL_Texture* Text_Maker(const char* Par_Objname, SDL_Rect* scr, SDL_Rect* dis, int extDif);
	void Text_Ctrl(const char* Par_Objname, SDL_Rect* scr, SDL_Rect* dis);

	int ext_bmp = 0;
	int ext_png = 1;

	const int obj_pWSpeed = 3;										// 플레이어 속도
	float obj_pJSpeed = 1;											// 플레이어의 점프 속도
	int obj_AniFrame = 0;											// 가만히 멈춰 있을땐, 정지

	bool isRight = false;											// 오른쪽 방향인지 확인
	bool isAttack = false;											// 플레이어가 공격하는지 확인
	bool isJump = false;											// 플레이어가 점프하는지 확인

	const int Pwalk_FrameW = 38;									// 플레이어의 이동 프레임 길이, 38
	const int PAttack_FrameW = 75;									// 플레이어의 공격 프레임 길이, 75

	const int Ground_yPos = 310;									// 지면의 y좌표
	const int Max_JumpH = Ground_yPos - 45;							// 최대 점프 높이 (지면의 높이 : 310 - 최대 점프 높이 : 45 )

	const char* adr_Char = "assets/Zelda_Walk_ver2+Attack.png";		// 젤다의 그림 주소
	const char* adr_Bg = "assets/Back_Ground.png";					// 배경 그림의 주소
	const char* adr_Kskull = "assets/KnifeSkull_Idle.png";			// 칼병 병사의 주소
	const char* adr_Askull = "assets/AxeSkull_Idle.png";			// 도끼 병사의 주소
};