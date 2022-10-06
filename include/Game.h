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

	SDL_Texture* m_pCTexture;	// 고양이같은 개
	SDL_Rect m_srcCat;			
	SDL_Rect m_disCat;			

	SDL_Texture* m_pDTexture;	// 떨어지는 강아지
	SDL_Rect m_srcDog;			
	SDL_Rect m_disDog;			

	SDL_Texture* m_pBgTexture;	// 배경
	SDL_Rect m_srcBg;
	SDL_Rect m_disBg;

	// 이미지를 받아오는 함수 + bmp는 0, png는 1이다.
	SDL_Texture* Text_Maker(const char* Par_Objname, SDL_Rect *scr, SDL_Rect *dis, int extDif);

	int ext_bmp = 0;
	int ext_png = 1;

	int obj_Speed = 1;										// 물체가 움직이는 속도 = 1
	int nChgWay_Cnt = 0;									// 현재 방향이 바뀐 횟수

	const int yPower = 30;

	// 실습 1번
	//const char* adr_Cat = "assets/animate.png";
	
	// 실습 2번
	const char* adr_Cat = "assets/animate-alpha.png";				// 캐릭터의 그림 주소
	const char* adr_Bg = "assets/Back_Ground.png";
	const char* adr_Dog = "assets/Dogge.png";

	int m_angle = 0;
};