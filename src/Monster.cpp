#pragma
#include "Monster.h"
#include"Game.h"

#include "TextManger.h"
#include <iostream>

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
	m_DIEH = 55;

	// <스탯>
	m_hp = 1000;
	m_damage = 80;
	m_WSpeed = 1;
}

void Monster::draw() 
{
	The_TextMananger::Instance()->drawFrame("Askull",
		m_position.getX(), mBG_YPOS + m_position.getY(),
		m_CurrFw, m_CurrFh,
		m_State * m_FrameIntv, m_CurrF,
		TheGame::Instance()->getRenderer(),
		SDL_FLIP_HORIZONTAL);
}

void Monster::setPlayerXPos(int xPos)
{
	m_PlayerXPos = xPos;
}

void Monster::stateMachine()
{
	int Dist = m_position.getX() - m_PlayerXPos;

	if(m_hp >= 0) {
		if (Dist > m_ChaseDist) {
			m_State = IDLE;
		}

		else if (Dist <= m_ChaseDist && Dist > m_AttDist) {
			m_State = WALK;
		}

		else if (Dist < m_AttDist) {
			m_State = ATTACK;
		}
	}
}

void Monster::update()
{
	stateMachine();
	
	switch (m_State)
	{
	case IDLE:
		setData(m_IDLEW, m_IDLEH);
		m_aniWF = 0;
		m_aniAF = 0;
		break;

	case WALK:
		setData(m_WALKW, m_WALKH);
		m_velocity.setX(-m_WSpeed);

		m_aniWF += m_ANISpeed;
		m_CurrF = (m_aniWF / 105) % m_AllFullCnt;
		break;

	case ATTACK:
		setData(m_ATTW, m_ATTH);
		m_aniAF += m_ANISpeed;
		m_CurrF = (m_aniAF / 150) % m_AllFullCnt;
		break;

	case HIT:
		setData(m_HITW, m_HITH);
		m_aniHF += m_ANISpeed;
		m_CurrF = (m_aniHF / 105) % m_AllFullCnt;
		break;

	case DIE:
		setData(m_DIEW, m_DIEH);
		m_position.setY(-10);
		m_aniDF += m_ANISpeed;
		m_CurrF = (m_aniDF / 330) % m_AllFullCnt;

		deathCount++;
		if (deathCount >= deathMaxCnt) {
			clean();
		}
		break;

	default:
		break;
	}

	SDLGameObject::update();
}