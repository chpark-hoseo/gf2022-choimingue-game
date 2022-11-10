#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public :
	void update();
	void handleInput();
	void draw(SDL_Renderer* m_pRenderer);

	void setSpeed(int P_WSpeed);									// 플레이어의 스피드값을 변경시킴 (Bg객체애서 사용)
	void setData(int FrameW, int FrameH);
	
	int getXpos();													// 플레이어의 x 좌표를 가져옴
	bool getIsRight();												// 플레이어의 방향을 확인
	bool getIsMove();												// 플레이어가 움직이는지를 확인

	void attack();													// 공격 함수
	void jump();													// 점프 함수

protected:

	// <플레이어가 현재 어떤 상태인지에 따라 달라짐>
	int m_State = IDLE;												// 현재 상태
	int m_CurrFw = 38;												// 현재 상태에 대한 프레임의 너비
	int m_CurrFh = 58;												// 현재 상태에 대한 프레임의 높이
	int m_FrameIntv = 75;											// 프레임 마다의 간격
	int m_CurrF = 0;												// 현재 몇번째 프레임인지

	// 플레이어의 애니메이션 관련 변수
	int m_aniWF = 0;												// 걷기 프레임이 바뀌도록 값을 더해줌
	int m_aniAF = 0;												// 공격 프레임이 바뀌도록 값을 더해줌
	const int m_ANISpeed = 15;										// 프레임이 바뀌도록 하는 값 (const값, 15)

	// <현재 어떤 상황인지 확인함>
	bool isRight = true;											// 오른쪽 방향인지 확인
	bool isAttack = false;											// 공격하는지 확인
	bool isJump = false;											// 점프하는지 확인

	// <기본 상태 관련 변수>
	const int m_IDLEW = 38;											// 기본 상태 프레임 길이(const값, 38)
	const int m_IDLEH = 58;											// 기본 상태 프레임 높이(const값, 58)

	// <이동 관련 변수>
	int m_WSpeed = 0;												// 움직이는 속도
	int m_Currxpos = 0;												// 현재 x좌표
	const int m_WALKW = 38;											// 이동 프레임 길이(const값, 38)
	const int m_WALKH = 58;											// 이동 프레임 높이(const값, 58)
	const int m_WALK_FullCnt = 8;									// 걷기 총 프레임 수(const값, 8)

	// <공격 관련 변수>
	int m_CurrAttF = 0;												// 현재 공격 프레임
	const int m_ATTW = 75;											// 공격 프레임 길이(const값, 75)
	const int m_ATTH = 75;											// 공격 프레임 높이(const값, 75)
	const int m_ATT_FullCnt = 6;									// 공격의 총 프레임수, 8 (const값, 6)

	// <점프 관련 변수>
	const int mBG_YPOS = 330;										// 지면의 y좌표 (const값, 330)
	const int m_JUMP_MaxH = mBG_YPOS - 60;							// 최대 점프 높이 (const값, 지면의 높이 : 310 - 최대 점프 높이 : 60 )
	int m_yPos = mBG_YPOS;											// 플레이어의 y좌표, 초기값 = 지면의 y좌표
	int m_JSpeed = 2;												// 점프 속도

	int m_AxSk_xPos = 1;
	int m_AxSk_State = 1;
	int m_AxSkCurrF = 1;
	int m_AxSkHp = 1;
};