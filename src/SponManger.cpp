#include "SponManger.h"
#include "BattleManger.h"
#include "TextManger.h"
#include "Game.h"

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

	//std::cout << GmBg_XPos << std::endl;

	switch (GmBg_XPos)
	{
	case aSkull_SponXpos:

		//std::cout << GmBg_XPos;
		m_ASkull = new ASkull(new LoaderParams(TheGame::Instance()->SCREEN_WIDTH,  GmBg->getGroundyPos(),
											Askull_IdleW, Askull_IdleH,
											"Askull"));
		
		if (!The_TextMananger::Instance()->load(TheGame::Instance()->adr_Askull
			, "Askull", TheGame::Instance()->getRenderer()))
		{
			std::cout << "Askull_Error";
			break;
		}

		TheBattleManger::Instance()->setMonsterObj(m_ASkull);
		SponObj = m_ASkull;
		break;

	case kSkull_SponXpos:
		m_KSkull = new KSkull(new LoaderParams(TheGame::Instance()->SCREEN_WIDTH, GmBg->getGroundyPos(), 
											Kskull_IdleW, Kskull_IdleH,
											"Kskull"));

		if (!The_TextMananger::Instance()->load(TheGame::Instance()->adr_Kskull
			, "Kskull", TheGame::Instance()->getRenderer()))
		{
			std::cout << "Kskull_Error";
			break;
		}

		TheBattleManger::Instance()->setMonsterObj(m_KSkull);
		SponObj = m_KSkull;
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
		break;
	}

	return SponObj;
}

SponManger* SponManger::s_pInstance = NULL;