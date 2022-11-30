#pragma
#include "ASkull.h"

ASkull::ASkull(LoaderParams* pParams) :
	Monster(pParams)
{
	monster_Name = "Askull";
	m_State = 0;
	m_CurrFw = 48;
	m_CurrFh = 49;
	m_FrameIntv = 50;
	m_CurrF = 0;

	// 애니메이션 관련 변수
	m_aniWF = 0;
	m_aniAF = 0;
	m_aniHF = 0;
	m_aniDF = 0;

	// <기본 상태 관련 변수>
	m_IDLEW = 48;
	m_IDLEH = 49;

	// <이동 관련 변수>
	m_WALKW = 50;
	m_WALKH = 46;

	// <공격 관련 변수>
	m_ATTW = 42;
	m_ATTH = 50;

	// <피격 관련 변수>
	m_HITW = 47;
	m_HITH = 46;

	// <사망 관련 변수>
	m_DIEW = 80;
	m_DIEH = 50;

	// <무덤 관련 변수>
	m_TOMBW = 32;
	m_TOMBH = 41;

	// <스탯>
	m_hp = 100;
	m_damage = 10;
	m_WSpeed = 1;
}

void ASkull::update()
{
	Monster::update();
}
void ASkull::draw()
{
	Monster::draw();
}