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

		int Dist = monster->getXPos() - player->getXPos();					// ���Ϳ� �÷��̾� ������ �Ÿ�

		// �÷��̾��� �����Ÿ� �ȿ� ���Ͱ� �ְ�, ������ ���� ���¶��, ���ظ� ����
		if (player->getATTWidth() >= Dist
			&& player->getIsRight() == true

			// ���� �������� 2,3,4,5 ������
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

			// ���� �������� 4,5,6 ������
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