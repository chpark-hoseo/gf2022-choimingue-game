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

	// �ִϸ��̼� ���� ����
	m_aniWF = 0;
	m_aniAF = 0;
	m_aniHF = 0;
	m_aniDF = 0;

	// <�⺻ ���� ���� ����>
	m_IDLEW = 48;
	m_IDLEH = 49;

	// <�̵� ���� ����>
	m_WALKW = 50;
	m_WALKH = 46;

	// <���� ���� ����>
	m_ATTW = 42;
	m_ATTH = 50;

	// <�ǰ� ���� ����>
	m_HITW = 47;
	m_HITH = 46;

	// <��� ���� ����>
	m_DIEW = 80;
	m_DIEH = 50;

	// <���� ���� ����>
	m_TOMBW = 32;
	m_TOMBH = 41;

	// <����>
	m_hp = 100;
	m_damage = 10;
	m_WSpeed = 1;
}

void Monster::draw() 
{
	The_TextMananger::Instance()->drawFrame("Askull",
		m_position.getX(), m_position.getY(),
		m_CurrFw, m_CurrFh,
		m_State * m_FrameIntv, m_CurrF,
		TheGame::Instance()->getRenderer(),
		SDL_FLIP_HORIZONTAL);
}

void Monster::setPlayerXPos(int xPos)
{
	m_PlayerXPos = xPos;
}

void Monster::setBgData(BackGround* backGround)
{
	this->backGround = backGround;
}

void Monster::stateMachine()
{
	int Dist = m_position.getX() - m_PlayerXPos;

	if (m_hp > 0) {
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
		m_velocity.setX(-backGround->getBgSpeed());
		m_aniWF = 0;
		m_aniAF = 0;
		m_aniHF = 0;
		break;

	case WALK:
		setData(m_WALKW, m_WALKH);
		m_velocity.setX(-m_WSpeed);

		m_aniWF += m_ANISpeed;
		m_CurrF = (m_aniWF / 105) % m_AllFullCnt;
		break;

	case ATTACK:
		setData(m_ATTW, m_ATTH);
		m_velocity.setX(0);

		m_aniAF += m_ANISpeed;
		m_CurrF = (m_aniAF / 150) % m_AllFullCnt;

		if (m_CurrF >= m_AllFullCnt - 1) {
			m_aniAF = 0;
		}
		break;

	case HIT:
		setData(m_HITW, m_HITH);
		m_aniHF += m_ANISpeed;
		m_CurrF = (m_aniHF / 105) % m_AllFullCnt;
		break;

	case DIE:
		setData(m_DIEW, m_DIEH);
		m_velocity.setX(-backGround->getBgSpeed());

		m_aniDF += m_ANISpeed;
		m_CurrF = (m_aniDF / 330) % m_AllFullCnt;

		deathCount++;
		if (deathCount >= deathMaxCnt) {
			m_State = TOMB;
		}
		break;

	case TOMB:
		m_velocity.setX(-backGround->getBgSpeed());
		setData(m_TOMBW, m_TOMBH);
		break;

	default:
		break;
	}

	SDLGameObject::update();
}