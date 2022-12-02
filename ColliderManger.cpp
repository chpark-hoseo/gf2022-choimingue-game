#include "ColliderManger.h"

void ColliderManger::setObjData(Player* player, Item* item)
{
	this->player = player;
	this->item = item;

}

void ColliderManger::AABBCheck()
{
}

bool ColliderManger::GameEnding(bool IsGameEnding)
{
	IsGameEnding = true;
	return IsGameEnding;
}
ColliderManger* ColliderManger::s_pInstance = 0;