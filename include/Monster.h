#pragma
#include "GameCharacter.h"

class Monster : public GameCharacter
{
public:
	void draw(SDL_Renderer* pRenderer);
	void update();

private:
	// <몬스터가 현재 어떤 상태인지에 따라 달라짐>
	int m_State;													// 현재 상태
	int m_CurrFw = 48;												// 현재 상태에 대한 프레임의 너비 (기본 값 Idle)
	int m_CurrFh = 49;												// 현재 상태에 대한 프레임의 높이 (기본 값 Idle)
	int m_FrameIntv = 50;											// 프레임 마다의 간격
	int m_CurrF = 0;												// 현재 몇번째 프레임인지

	// 몬스터의 애니메이션 관련 변수
	int m_aniWF = 0;												// 걷기 프레임이 바뀌도록 값을 더해줌
	int m_aniAF = 0;												// 공격 프레임이 바뀌도록 값을 더해줌
	const int m_ANISpeed = 15;										// 프레임이 바뀌도록 하는 값 (const값, 15)
	const int m_AllFullCnt = 7;										// 모든 행동의 프레임은 7

	// <기본 상태 관련 변수>
	const int m_IDLEW = 48;											// 기본 상태 프레임 길이(const값, 48)
	const int m_IDLEH = 49;											// 기본 상태 프레임 높이(const값, 49)

	// <이동 관련 변수>
	int m_Currxpos = 0;												// 현재 x좌표
	const int m_WALKW = 46;											// 이동 프레임 길이(const값, 46)
	const int m_WALKH = 46;											// 이동 프레임 높이(const값, 46)

	// <공격 관련 변수>
	const int m_ATTW = 42;											// 공격 프레임 길이(const값, 42)
	const int m_ATTH = 50;											// 공격 프레임 높이(const값, 50)

	// <피격 관련 변수>
	const int m_HITW = 47;											// 공격 프레임 길이(const값, 47)
	const int m_HITH = 46;											// 공격 프레임 높이(const값, 46)

	// <사망 관련 변수>
	const int m_DIEW = 80;											// 공격 프레임 길이(const값, 47)
	const int m_DIEH = 55;											// 공격 프레임 높이(const값, 46)

	// <몬스터의 스탯>
	int m_hp = 100;													// 몬스터의 체력 100
	int m_damage = 20;												// 몬스터의 데미지 20
	int m_WSpeed = 0;												// 움직이는 속도
};