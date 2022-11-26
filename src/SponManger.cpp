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

	return monster;
}

SDLGameObject* SponManger::sponByGameBg()
{
	GmBg_XPos = GmBg->getBgXpos();

	switch (GmBg_XPos)
	{
	case kSkull_SponXpos:
		monster = new Monster(new LoaderParams(400, GmBg->getGroundyPos(), 48, 50, "Kskull"));

		if (!The_TextMananger::Instance()->load(TheGame::Instance()->adr_Kskull
			, "Kskull", TheGame::Instance()->getRenderer()))
		{
			std::cout << "Error";
			break;
		}

		TheBattleManger::Instance()->setMonsterObj(monster);
		SponObj = monster;
		break;

	default:
		SponObj = NULL;
		monster = NULL;
		break;
	}

	return SponObj;
}

SponManger* SponManger::s_pInstance = NULL;