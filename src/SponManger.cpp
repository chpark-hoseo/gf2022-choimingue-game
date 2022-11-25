#include "SponManger.h"
#include "BattleManger.h"

#include "Monster.h"

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
		TheBattleManger::Instance()->setMonsterObj(monster);
		SponObj = monster;
		break;

	default:
		SponObj = NULL;
		monster = NULL;
		TheBattleManger::Instance()->setMonsterObj(monster);
		break;
	}

	return SponObj;
}

SponManger* SponManger::s_pInstance = NULL;