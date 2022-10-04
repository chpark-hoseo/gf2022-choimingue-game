#pragma once
#include "main.h"

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
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	SDL_Texture* m_pTexture;
	SDL_Rect m_srcCat;			// 원본 사각형
	SDL_Rect m_disCat;			// 대상 사각형

	// 이미지를 받아오는 함수 + bmp는 0, png는 1이다.
	SDL_Texture* Text_Maker(const char* Par_Objname, SDL_Rect *scr, SDL_Rect *dis, int extDif);

	int ext_bmp = 0;
	int ext_png = 1;

	int obj_Speed = 1;										// 물체가 움직이는 속도 = 1
	int nChgWay_Cnt = 0;									// 현재 방향이 바뀐 횟수

	const char* adr_Cat = "assets/animate.png";				// 캐릭터의 그림 주소
};