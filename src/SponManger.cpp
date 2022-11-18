#include "SponManger.h"
#include "Monster.h"

void SponManger::setBgData(BackGround* GmBg_Data)
{
	this->GmBg = GmBg_Data;
}
SDLGameObject* SponManger::addGameobj()
{
	sponByGameBg();

	return GameObj;
}

void SponManger::sponByGameBg()
{
	GmBg_XPos = GmBg->getBgXpos();

	if (GmBg_XPos == kSkull_SponXpos) {
		GameObj = new Monster(new LoaderParams(400, GmBg->getGroundyPos(), 48, 50, "Kskull"));
	}
}