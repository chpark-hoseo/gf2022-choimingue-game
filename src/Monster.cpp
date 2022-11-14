#pragma
#include "Monster.h"

Monster::Monster(LoaderParams* pParams) :
	GameCharacter(pParams)
{
	m_State = 0;
	m_CurrFw = 48;
	m_CurrFh = 49;
	m_FrameIntv = 50;
	m_CurrF = 0;

	// 애니메이션 관련 변수
	m_aniWF = 0;
	m_aniAF = 0;

	// <기본 상태 관련 변수>
	m_IDLEW = 48;
	m_IDLEH = 49;

	// <이동 관련 변수>
	m_Currxpos = 0;
	m_WALKW = 46;
	m_WALKH = 46;

	// <공격 관련 변수>
	m_ATTW = 42;
	m_ATTH = 50;

	// <피격 관련 변수>
	m_HITW = 47;
	m_HITH = 46;

	// <사망 관련 변수>
	m_DIEW = 80;
	m_DIEH = 55;

	// <스탯>
	m_hp = 100;
	m_damage = 20;
	m_WSpeed = 0;
}


void Monster::draw() 
{

}

void Monster::update()
{
	
	switch (m_State)
	{
	case IDLE:
		setData(m_IDLEW, m_IDLEH);
		m_aniWF = 0;
		m_aniAF = 0;
		break;

	case WALK:
		setData(m_WALKW, m_WALKH);
		m_aniWF += m_ANISpeed;
		m_Currxpos += m_WSpeed;
		m_CurrF = (m_aniWF / 105) % m_AllFullCnt;
		break;

	case ATTACK:
		setData(m_ATTW, m_ATTH);
		m_aniWF += m_ANISpeed;
		m_CurrF = (m_aniWF / 90) % m_AllFullCnt;
		break;

	case HIT:
		setData(m_HITW, m_HITH);
		m_aniWF += m_ANISpeed;
		m_CurrF = (m_aniWF / 90) % m_AllFullCnt;
		break;

	case DIE:
		setData(m_DIEW, m_DIEH);
		m_aniWF += m_ANISpeed;
		m_CurrF = (m_aniWF / 90) % m_AllFullCnt;
		break;

	default:
		break;
	}
}