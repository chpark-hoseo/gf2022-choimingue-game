#pragma once
#include "main.h"
#include "TextManger.h"

class Game
{
public:
	// 윈도우 크기
	const int SCREEN_WIDTH = 640;
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
	TextManger m_textManger;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int obj_Speed = 1;										// 물체가 움직이는 속도 = 1
	int nChgWay_Cnt = 0;									// 현재 방향이 바뀐 횟수

	const char* adr_Dog = "assets/animate-alpha.png";				// 캐릭터의 그림 주소
	const int m_DogW = 128;
	const int m_DogH = 98;
	int m_DogCurrFrame = 0;
};