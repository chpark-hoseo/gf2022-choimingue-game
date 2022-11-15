#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"

#include "Player.h"
#include "Monster.h"

class BattleManger : public SDLGameObject
{
public:
	BattleManger(LoaderParams* pParams);

	void setGameObj(Player* player, Monster* monster);

private:
	Player* player;
	Monster* monster;
};

