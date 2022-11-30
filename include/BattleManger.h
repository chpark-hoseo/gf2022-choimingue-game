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

	void setGamePlayer(Player* player);				// 초반의 플레이어와 몬스터의 데이터를 가져옴
	void setMonsterObj(Monster* monster);							// 몬스터가 스폰될때, 그 객체를 가져옴
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