#pragma once
#include "GameObject.h"

class GameCharacter : public GameObject
{
public:
	virtual void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();

	void setData(int FrameW, int FrameH);

protected:
	enum State
	{
		IDLE, WALK, ATTACK, HIT, DIE
	};

	// <몬스터가 현재 어떤 상태인지에 따라 달라짐>
	int m_State;												// 현재 상태
	int m_CurrFw;												// 현재 상태에 대한 프레임의 너비
	int m_CurrFh;												// 현재 상태에 대한 프레임의 높이
	int m_FrameIntv;											// 프레임 마다의 간격
	int m_CurrF;												// 현재 몇번째 프레임인지

	// <기본 상태 관련 변수>
	const int m_IDLEW;											// 기본 상태 프레임 길이
	const int m_IDLEH;											// 기본 상태 프레임 높이

	// <이동 관련 변수>
	int m_Currxpos;												// 현재 x좌표
	const int m_WALKW;											// 이동 프레임 길이
	const int m_WALKH;											// 이동 프레임 높이

	// <공격 관련 변수>
	const int m_ATTW;											// 공격 프레임 길이
	const int m_ATTH;											// 공격 프레임 높이

	// <피격 관련 변수>
	const int m_HITW;											// 공격 프레임 길이
	const int m_HITH;											// 공격 프레임 높이

	// <사망 관련 변수>
	const int m_DIEW;											// 공격 프레임 길이
	const int m_DIEH;											// 공격 프레임 높이

	// <스탯>
	int m_hp;													// 체력
	int m_damage;												// 데미지 
	int m_WSpeed;												// 움직이는 속도
};