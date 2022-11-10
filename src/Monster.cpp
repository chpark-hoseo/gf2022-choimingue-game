#pragma
#include "Monster.h"

void Monster::draw(SDL_Renderer* pRenderer) 
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