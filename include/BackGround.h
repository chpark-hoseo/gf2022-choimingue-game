#pragma once

#include "SDLGameObject.h"
#include "Player.h"

#include "LoaderParams.h"

class BackGround : public SDLGameObject
{

public:
	BackGround(LoaderParams* pParams);								// 배경 객체를 로딩함

	void draw();													// drawMove함수를 사용
	void update();													// 배경이 이동하는것을 update해줌
	
	// <배경 이동과 관련된 함수>
	void setPlayerData(Player* player);								// 플레이어 객체를 받아옴
	void move_byPlayer();											// 플레이어의 위치에 따라 배경이 이동

	// <몬스터 스폰과 관련된 함수>
	int getBgXpos();												// 배경의 x좌표를 가져옴
	int getGroundyPos();											// 배경의 땅 좌표를 가져옴

private:
	Player* player = NULL;

	const int mP_WalkW = 38;										// 플레이어 걷기 프레임의 길이
	const int mP_WalkSpeed = 3;

	int mBg_MoveSpeed = 0;											// 배경이 움직이는 속도
	int mBg_CurrXpos = 0;											// 배경의 현재 x 좌표
	const int mGround_yPos = 330;

	const int mBg_END = 5000 - SCREEN_WIDTH;						// 배경이 움직임이 끝나는 좌표
	const int mBg_START = SCREEN_WIDTH / 3.0;						// 배경이 움직이기 시작하는 좌표
	const int mP_MAX_XPOS = SCREEN_WIDTH - mP_WalkW;				// 플레이어가 움직일 수 있는 최대 좌표
};

