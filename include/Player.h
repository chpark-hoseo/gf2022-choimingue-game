#pragma once
#include "GameCharacter.h"

class Player : public GameCharacter
{
public :
	Player(LoaderParams* pParams);

	void update();
	void handleInput();
	void draw();

	void setSpeed(int P_WSpeed);									// 플레이어의 스피드값을 변경시킴 (Bg객체애서 사용)
	
	// <배경 이동시 사용>
	bool getIsRight();												// 플레이어의 방향을 확인
	bool getIsMove();												// 플레이어가 움직이는지를 확인
	int getSpeed();

	int getYPos();													// 플레이어의 y 좌표를 가져옴

	void Add_GroundYpos(int GroundYpos);							// 배경의 지면 좌표를 가져옴

	void jump();													// 점프 함수

protected:

	const int m_HitTime = 10;										// 피격 받은 판정 시간
	int m_CurrHitTime = 0;											// 현재 피격 되는 시간
	int m_CurrAttF = 0;												// 현재 공격 프레임

	// <현재 어떤 상황인지 확인함>
	bool isRight = true;											// 오른쪽 방향인지 확인
	bool isAttack = false;											// 공격하는지 확인
	bool isJump = false;											// 점프하는지 확인

	int m_GroundYpos = 330;											// 지면의 y좌표 (초기값 330)
	int m_AddYPos = 0;

	// <점프 관련 변수>
	int m_JUMP_MaxH = m_GroundYpos - 60;							// 최대 점프 높이 (const값, 지면의 높이 : 310 - 최대 점프 높이 : 60 )
	int m_JSpeed = 2;												// 점프 속도
};