#pragma once

#include "Player.h"
#include "Monster.h"

class BattleManger
{
public:
	static BattleManger* Instance()
	{
		if (s_pInstance == NULL)
			s_pInstance = new BattleManger();

		return s_pInstance;
	}

	void setGamePlayer(Player* player);				// �ʹ��� �÷��̾�� ������ �����͸� ������
	void setMonsterObj(Monster* monster);							// ���Ͱ� �����ɶ�, �� ��ü�� ������
	void update();

private:
	enum State
	{
		IDLE, WALK, ATTACK, HIT, DIE
	};

	BattleManger() = default;
	static BattleManger* s_pInstance;

	Player* player;
	Monster* monster;

}typedef TheBattleManger;