#include "BattleManger.h"
#include "iostream"

void BattleManger::setGamePlayer(Player* player)
{
	this->player = player;
}

void BattleManger::setMonsterObj(Monster* monster)
{
	this->monster = monster;
}

void BattleManger::update()
{
	if (monster == NULL)
		return;
	
	else {
		monster->setPlayerXPos(player->getXPos());

		int Dist = monster->getXPos() - player->getXPos();					// 몬스터와 플레이어 사이의 거리

		// 플레이어의 사정거리 안에 몬스터가 있고, 오른쪽 공격 상태라면, 피해를 입힘
		if (player->getATTWidth() >= Dist
			&& player->getIsRight() == true

			// 공격 프레임은 2,3,4,5 프레임
			) {
			if (player->getCurrATTF() == 90 * 2
				|| player->getCurrATTF() == 90 * 3
				|| player->getCurrATTF() == 90 * 4
				|| player->getCurrATTF() == 90 * 5) {

				monster->setState(HIT);
				monster->setHp(-player->getDamage());

				if (monster->getHp() <= 0)
					monster->setState(DIE);

				std::cout << "Monster Hp : ";
				std::cout << monster->getHp() << std::endl;;
			}
		}

		if (monster->getATTWidth() >= Dist) {

			// 공격 프레임은 4,5,6 프레임
			if (monster->getCurrATTF() == 150 * 4
				|| monster->getCurrATTF() == 150 * 5
				|| monster->getCurrATTF() == 150 * 6) {

				player->setState(HIT);
				player->setHp(-monster->getDamage());

				if (player->getHp() <= 0)
					player->setState(DIE);

				std::cout << "Player Hp : ";
				std::cout << player->getHp() << std::endl;;
			}
		}
	}
}

BattleManger* BattleManger::s_pInstance = NULL;