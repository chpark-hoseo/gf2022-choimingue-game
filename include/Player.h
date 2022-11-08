#include "GameObject.h"
#include "BackGround.h"

#pragma once
class Player : public GameObject
{
public :
	Player(BackGround* GameBg) {
		this->GameBg = GameBg;
	}

	void update();
	void handleInput();

	void setData(int FrameW, int FrameH);
	void setBgData(BackGround* GameBg);

	void move();
	void attack();
	void jump();

	void draw(SDL_Renderer* m_pRenderer);

private:
	enum State
	{
		IDLE, WALK, ATTACK, HIT, DEAD
	};

	BackGround* GameBg;

	// <플레이어가 현재 어떤 상태인지에 따라 달라짐>
	int mP_State = IDLE;											// 플레이어의 현재 상태
	int mP_CurrFw = 38;												// 플레이어가 현재 상태에 대한 프레임의 너비
	int mP_CurrFh = 58;												// 플레이어가 현재 상태에 대한 프레임의 높이
	int mP_FrameIntv = 75;											// 프레임 마다의 간격
	int mP_CurrF = 0;												// 플레이어는 현재 몇번째 프레임인지

	// 플레이어의 애니메이션 관련 변수
	int mP_aniWF = 0;												// 걷기 프레임이 바뀌도록 값을 더해줌
	int mP_aniAF = 0;												// 공격 프레임이 바뀌도록 값을 더해줌
	const int mCP_anifSpeed = 15;									// 프레임이 바뀌도록 하는 값

	// <현재 어떤 상황인지 확인함>
	bool isRight = true;											// 오른쪽 방향인지 확인
	bool isAttack = false;											// 플레이어가 공격하는지 확인
	bool isJump = false;											// 플레이어가 점프하는지 확인

	// <이동 관련 변수>
	int mP_WSpeed = 0;												// 플레이어 속도
	int mP_Currxpos = 0;											// 현재 플레이어의 x좌표
	const int mCP_WALKW = 38;										// 플레이어의 이동 프레임 길이, 38
	const int mCP_WALKH = 58;										//						  높이, 58
	const int mCP_WALK_FULLCNT = 8;									// 걷기에 총 프레임 수

	// <배경 이동 관련 변수>
	int mBg_End = 5000 - SCREEN_WIDTH;								// 배경의 이동이 끝나는 좌표
	int mBg_Start = SCREEN_WIDTH / 3.0;								// 배경이 이동이 시작되는 좌표
	const int mP_MAX_XPOS = SCREEN_WIDTH - mCP_WALKW;				// 플레이어가 움직일 수 있는 최대 좌표

	// <공격 관련 변수>
	int mP_CurrAttF = 0;											// 플레이어의 현재 공격 프레임
	const int mCP_AttackW = 75;										// 플레이어의 공격 프레임 길이, 75
	const int mCP_AttackH = 75;										//						  높이, 75
	const int mCP_ATT_FULLCNT = 6;								// 걷기에 총 프레임 수

	// <점프 관련 변수>
	float mP_JSpeed = 2;											// 플레이어의 점프 속도
	int mP_yPos = 310;												// 플레이어의 y좌표, 초기값 = 지면의 y좌표
	const int mCB_GYPOS = 310;										// 지면의 y좌표
	const int mCP_JUMPMAXH = mCB_GYPOS - 60;						// 최대 점프 높이 (지면의 높이 : 310 - 최대 점프 높이 : 45 )

	int m_AxSk_xPos = 1;
	int m_AxSk_State = 1;
	int m_AxSkCurrF = 1;
	int m_AxSkHp = 1;
};