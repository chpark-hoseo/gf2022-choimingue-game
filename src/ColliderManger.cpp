#include "ColliderManger.h"
#include "Game.h"

#include "iostream"

void ColliderManger::setPlayerData(Player* player)
{
	this->player = player;
}

void ColliderManger::setItemData(Item* item)
{
	this->item = item;
}

void ColliderManger::setDefaultData()
{
	// �÷��̾��� �����Ϳ� ���� �� �ִٸ�, ���� ����
	if (player != NULL) {
		objPosition.aMax_x = player->getXPos() + player->getWalkW();
		objPosition.aMin_y = player->getYPos();
	}

	// ������ �����Ϳ� ���� �� �ִٸ�, ���� ����
	if (item != NULL) {
		objPosition.bMin_x = item->getXpos();
		objPosition.bMax_y = item->getYpos() + item->getFrameH();
	}
}

bool ColliderManger::AABBCheck()
{
	setDefaultData();

	if (item != NULL) {
		//std::cout << objPosition.aMax_x << ", " << objPosition.bMin_x << std::endl;
		//std::cout << objPosition.aMin_y << ", " << objPosition.bMax_y << std::endl;

		if (objPosition.aMax_x <= objPosition.bMin_x) {
			//std::cout << "1. �浹x" << std::endl;
			return false;
		}
		if (objPosition.aMin_y >= objPosition.bMax_y) {
			//std::cout << "2. �浹x" << std::endl;
			return false;
		}
		else {
			//std::cout << "�浹!!!!" << std::endl;
			return true;
		}
	}
}

int ColliderManger::getCollTag()
{
	if (item != NULL)
	{
		return item->getItemType();
	}
}

ColliderManger* ColliderManger::s_pInstance = 0;