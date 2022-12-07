#pragma
#include "KSkull.h"

KSkull::KSkull(LoaderParams* pParams)
	:Monster(pParams)
{
	monster_Name = "Kskull";

	m_State = 0;
	m_CurrFw = 51;
	m_CurrFh = 49;
	m_FrameIntv = 53;
	m_CurrF = 0;

	// �ִϸ��̼� ���� ����
	m_aniWF = 0;
	m_aniAF = 0;
	m_aniHF = 0;
	m_aniDF = 0;

	// <�⺻ ���� ���� ����>
	m_IDLEW = 51;
	m_IDLEH = 49;

	// <�̵� ���� ����>
	m_WALKW = 53;
	m_WALKH = 50;

	// <���� ���� ����>
	m_ATTW = 48;
	m_ATTH = 48;

	// <�ǰ� ���� ����>
	m_HITW = 61;
	m_HITH = 52;

	// <��� ���� ����>
	m_DIEW = 113;
	m_DIEH = 55;

	// <���� ���� ����>
	m_TOMBW = 31;
	m_TOMBH = 41;

	// <����>
	m_hp = 150;
	m_damage = 8;
	m_WSpeed = 2;
}

void KSkull::update()
{
	Monster::update();
}
void KSkull::draw()
{
	Monster::draw();
}