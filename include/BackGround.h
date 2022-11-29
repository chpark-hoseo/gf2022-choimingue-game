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

	int getBgSpeed();

	// <지형 충돌과 관련된 함수>
	void BlockCheck();
	void BlockInstall();
	bool AABBCheck();

private:
	Player* player = NULL;

	const int mP_WalkW = 38;										// 플레이어 걷기 프레임의 길이
	const int mP_WALKH = 58;
	const int mP_WalkSpeed = 3;
	
	int mBg_MoveSpeed = 0;											// 배경이 움직이는 속도
	int mBg_CurrXpos = 0;											// 배경의 현재 x 좌표
	int mGround_yPos = 330;											// 초기 벽의 y 좌표

	const int mBg_END = 5000 - SCREEN_WIDTH;						// 배경이 움직임이 끝나는 좌표
	const int mBg_START = SCREEN_WIDTH / 3.0;						// 배경이 움직이기 시작하는 좌표
	const int mP_MAX_XPOS = SCREEN_WIDTH - mP_WalkW;				// 플레이어가 움직일 수 있는 최대 좌표

	const int m_1stFloor_w = 1111;									// 첫번째 블록의 길이
	const int m_2stFloor_w = 1711;									// 두번째 블록의 길이
	const int m_3stFloor_w = 1216;									// 세번째 블록의 길이

	int m_1stCheckP;												// 첫번째 충돌 지점
	int m_2stCheckP;												// 두번째 충돌 지점
	int m_3stCheckP;												// 세번째 충돌 지점

	const int m_Floor_h = 26;										// 블록마다의 길이

	int m_CurrBlock_MaxX;											// 현재 충돌의 최대 x값
	int m_CurrBlock_MinX;											// 현재 충돌의 최소 x값

	int DistToDest = 0;
	bool IsDown = false;

	int CheckYPos = mGround_yPos - m_Floor_h;
};