#pragma once
#include"game.h"
#include "GameObject.h"
#include "vector"

class Game
{
private:
	Game() {}
	static Game* s_pInstatance;

public:
	// 싱글턴 패턴
	static Game* Instance()
	{
		if (s_pInstatance == NULL) {
			s_pInstatance = new Game();
		}
		return s_pInstatance;
	}

	SDL_Renderer* getRenderer() const;

	// 윈도우 크기
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 480;

	// 윈도우 생성
	bool init(const char* Stitle, int xpos, int ypos, int Swidth, int Sheight, int flags);

	// 게임 내용 수정
	void update();

	// 화면 띄우기
	void renderer();

	SDL_Renderer* getRenderer() { return m_pRenderer; }

	// 정상작동중인지 확인
	bool running();

	// 종료 설정
	void handleEvent();

	// 화면 지우기
	void clean();

	void quit();

	const char* adr_Kskull = "assets/KnifeSkull_Idle.png";			// 칼병 병사의 주소
	const char* adr_Askull = "assets/AxeSkull_Full.png";			// 도끼 병사의 주소

private:
	SDL_Window* m_pWindow = NULL;
	SDL_Renderer* m_pRenderer = NULL;

	bool m_bRunning = false;

	// <플레이어의 대한 기본 정보>
	const int Pwalk_FrameW = 38;									// 플레이어 기본 상태 Idle의 길이, 38
	const int Pwalk_FrameH = 58;									//								 , 58

	// <초기 땅의 좌표>
	const int Ground_yPos = 330;									// 지면의 y좌표

	// <도끼병 관련 변수>
	int m_AxSk_Speed = 0;											// 도끼병의 다가오는 속도
	int m_AxSk_xPos = 500;											// 도끼병의 x 좌표
	int m_AxSk_State = 0;											// 현재 도끼병의 상태

	int m_AxSkHp = 50;
	int m_AxSkCurrFh = 47;											// 현재 프레임 간격
	int m_AxSkCurrF = 0;											// 현재 몇번째 프레임

	const char* adr_Char = "assets/Zelda_Walk+Attack.png";			// 젤다의 그림 주소
	const char* adr_Bg = "assets/Back_Ground2.png";					// 배경 그림의 주소

	const char* adr_GameOver = "assets/Big_GameOver.png";				// 게임 오버의 주소

	std::vector<GameObject*> m_gameObjects;
}typedef TheGame;