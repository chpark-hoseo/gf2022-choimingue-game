#include "SponManger.h"
#include "BattleManger.h"
#include "TextManger.h"
#include "Game.h"
#include "ColliderManger.h"

#include "Monster.h"

#include <iostream>

void SponManger::setBgData(BackGround* GmBg_Data)
{
	this->GmBg = GmBg_Data;
}
SDLGameObject* SponManger::addGameobj()
{
	SponObj = sponByGameBg();

	return SponObj;
}

SDLGameObject* SponManger::sponByGameBg()
{
	GmBg_XPos = GmBg->getBgXpos();

	switch (GmBg_XPos)
	{
	case aSkull_SponXpos:
		m_ASkull = new ASkull(new LoaderParams(TheGame::Instance()->SCREEN_WIDTH,  GmBg->getGroundyPos(),
											Askull_IdleW, Askull_IdleH,
											"Askull"));

		TheBattleManger::Instance()->setMonsterObj(m_ASkull);
		SponObj = m_ASkull;
		break;

	case kSkull_SponXpos:
		m_KSkull = new KSkull(new LoaderParams(TheGame::Instance()->SCREEN_WIDTH, GmBg->getGroundyPos(), 
											Kskull_IdleW, Kskull_IdleH,
											"Kskull"));

		TheBattleManger::Instance()->setMonsterObj(m_KSkull);
		SponObj = m_KSkull;
		break;

	case TBox_SponXpos:
		std::cout << GmBg->getGroundyPos();

		m_TBox = new Item(new LoaderParams(TheGame::Instance()->SCREEN_WIDTH, GmBg->getGroundyPos(),
											TBox_FrameW, TBox_FrameH,
											"TBox"));
		m_TBox->setItemType(m_TBox->TBox);
		m_TBox->setGroundYPos(GmBg->getGroundyPos());
		ColliderManger::Instance()->setItemData(m_TBox);
		SponObj = m_TBox;
		break;

	default:
		SponObj = NULL;

		if (m_ASkull != NULL) {
			m_ASkull->setBgSpeed(GmBg->getBgSpeed());
			
			if (m_ASkull->getXPos() < 0 )
				m_ASkull = NULL;
		}

		else if (m_KSkull != NULL) {
			m_KSkull->setBgSpeed(GmBg->getBgSpeed());

			if (m_KSkull->getXPos() < 0)
				m_KSkull = NULL;
		}

		else if (m_TBox != NULL){
			m_TBox->setBgSpeed(GmBg->getBgSpeed());
		}
		break;
	}

	return SponObj;
}

SponManger* SponManger::s_pInstance = NULL;