#pragma once
#include<SDL2/SDL.h>
#include"GameObject.h"
#include"Player.h"

class BackGround : public GameObject
{
public:

	// 그림을 그림, drawMove
	void draw(SDL_Renderer* pRenderer);

	// 플레이어 객체에게서 배경의 속도를 가져옴
	void setSpeed(int MoveSpeed);

	void move_byPlayer();

	void update();

	void setPlayerData(Player* player);

private:
	Player* player;
	const int mP_WalkW = 38;				// 플레이어 걷기 프레임의 길이
	const int mP_WalkSpeed = 3;

	int mBg_MoveSpeed = 0;					// 배경이 움직이는 속도
	int mBg_CurrXpos = 0;					// 배경의 현재 x 좌표

	int mBg_END = 5000 - SCREEN_WIDTH;								// 배경이 움직임이 끝나는 좌표
	int mBg_START = SCREEN_WIDTH / 3.0;								// 배경이 움직이기 시작하는 좌표
	const int mP_MAX_XPOS = SCREEN_WIDTH - mP_WalkW;				// 플레이어가 움직일 수 있는 최대 좌표
};

