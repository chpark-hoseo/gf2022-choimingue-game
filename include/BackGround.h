#pragma once
#include<SDL2/SDL.h>
#include"GameObject.h"

class BackGround : public GameObject
{
public:
	// 그려질 위치와, 태그를 받아옴
	void load(int y, std::string textureID);

	// 그림을 그림, drawMove
	void drawMove(SDL_Renderer* pRenderer);

	// 플레이어 객체에게서 배경의 속도를 가져옴
	void setSpeed(int MoveSpeed);

	// 배경의 x 좌표를 가져옴
	int getXpos();

	// 배경의 움직임이 멈추는 좌표를 가져옴 (이후, 배경이 움직이지 않음)
	int getBg_End();

	// 배경이 움직이는 시작점의 좌표를 가져옴 (이후, 배경이 움직임)
	int getBg_Start();

	void update();

private:
	int mBg_MoveSpeed = 0;					// 배경이 움직이는 속도
	int mBg_CurrXpos = 0;					// 배경의 현재 x 좌표

	int mBg_END = 5000 - SCREEN_WIDTH;								// 배경이 움직임이 끝나는 좌표
	int mBg_START = SCREEN_WIDTH / 3.0;								// 배경이 움직이기 시작하는 좌표
};

