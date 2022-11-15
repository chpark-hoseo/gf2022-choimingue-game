#include "BattleManger.h"

void BattleManger::setGameObj(Player* player, Monster* monster)
{
	this->player = player;
	this->monster = monster;
}

void BattleManger::update()
{
	monster->setPlayerXPos(player->getXPos());

	int Dist = monster->getXPos() - player->getXPos();					// ���Ϳ� �÷��̾� ������ �Ÿ�
	

	// �÷��̾��� �����Ÿ� �ȿ� ���Ͱ� �ְ�, ������ ���� ���¶��, ���ظ� ����
	if (player->getATTWidth() >= Dist
		&& player->getIsRight() == true
		){
		if (player->getState() == ATTACK 
			&& player->getCurrATTF() >= 2 
			&& player->getCurrATTF() <= 5) {

			monster->setState(HIT);
			monster->setHp(-player->getDamage());

			if(monster->getHp() <= 0)
				monster->setState(DIE);
		}
	}

	if(monster->getATTWidth() > Dist){
		if (monster->getState() == ATTACK
			&& monster->getCurrATTF() >= 4
			&& monster->getCurrATTF() <= 6) {

			player->setState(HIT);
			player->setHp(-monster->getDamage());

			if (player->getHp() <= 0)
				player->setState(DIE);
		}
	}
}

BattleManger* BattleManger::s_pInstance = NULL;