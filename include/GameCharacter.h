#pragma once
#include"SDLGameObject.h"
#include "LoaderParams.h"

class GameCharacter : public SDLGameObject
{
public:
	GameCharacter(LoaderParams* pParams);

	virtual void draw() {}
	virtual void update(){}
	virtual void clean();

	void setData(int FrameW, int FrameH);						// 현재 상태에 따른 값을 대입해준다.
	void setHp(int damage);										// 체력이 얼만지 갱신해준다.
	void setState(int State);									// 현재 상태를 변환시켜 줍니다.

	int getState();												// 현재 상태를 가져온다.
	int getHp();												// 현재 체력을 가져온다.

	int getXPos();												// x좌표를 가져옴
	int getATTWidth();											// 공격 프레임의 길이를 가져온다.
	int getCurrATTF();											// 몇번째 공격 프레임인지 확인
	int getDamage();											// 데미지가 얼마인지 가져옴


	// <기본 상태 관련 변수>
	int m_IDLEW;												// 기본 상태 프레임 길이
	int m_IDLEH;												// 기본 상태 프레임 높이

	enum State
	{
		IDLE, WALK, ATTACK, HIT, DIE
	};

protected:

	// <몬스터가 현재 어떤 상태인지에 따라 달라짐>
	int m_State;												// 현재 상태
	int m_CurrFw;												// 현재 상태에 대한 프레임의 너비
	int m_CurrFh;												// 현재 상태에 대한 프레임의 높이
	int m_FrameIntv;											// 프레임 마다의 간격
	int m_CurrF;												// 현재 몇번째 프레임인지

	// 애니메이션 관련 변수
	int m_aniWF = 0;											// 걷기관련 프레임이 바뀌도록 값을 더해줌
	int m_aniAF = 0;											// 공격관련 프레임이 바뀌도록 값을 더해줌
	int m_aniHF = 0;											// 피격관련 프레임이 바뀌도록 값을 더해줌
	int m_aniDF = 0;											// 죽음관련 프레임이 바뀌도록 값을 더해줌
	const int m_ANISpeed = 15;									// 프레임이 바뀌도록 하는 값

	// <이동 관련 변수>
	const int mBG_YPOS = 330;									// 지면의 y좌표 (const값, 330)
	int m_WALK_FullCnt;											// 이동에 총 프레임 수
	int m_WALKW;												// 이동 프레임 길이
	int m_WALKH;												// 이동 프레임 높이

	// <공격 관련 변수>
	int m_ATT_FullCnt;											// 공격에 총 프레임 수
	int m_ATTW;													// 공격 프레임 길이
	int m_ATTH;													// 공격 프레임 높이

	// <피격 관련 변수>
	int m_HIT_FullCnt;											// 피격에 총 프레임 수
	int m_HITW;													// 피격 프레임 길이
	int m_HITH;													// 피격 프레임 높이

	// <사망 관련 변수>
	int m_DIE_FullCnt;											// 죽음에 총 프레임 수
	int m_DIEW;													// 죽음 프레임 길이
	int m_DIEH;													// 죽음 프레임 높이

	// <무덤 관련 변수>
	int m_TOMBW;												// 무덤 프레임 길이
	int m_TOMBH;												// 무덤 프레임 길이

	// <스탯>
	int m_hp;													// 체력
	int m_damage;												// 데미지 
	int m_WSpeed;												// 움직이는 속도
};