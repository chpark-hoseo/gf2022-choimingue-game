#pragma once
#include"Player.h"
#include"Item.h"

class ColliderManger
{
public :
	static ColliderManger* Instance()
	{
		if (s_pInstance == nullptr)
			s_pInstance = new ColliderManger();

		return s_pInstance;
	}

	void setObjData(Player* player, Item* item);							// 플레이어 객체와 아이템 객체를 가져옴
	void AABBCheck();													// 충돌 검사
	bool GameEnding(bool IsGameEnding);									// 충돌시 게임 엔딩을 진행

private:
	struct ObjPosition_A
	{
		int amax_x;		int amin_x;
		int amax_y;		int amin_y;
	}APosition;

	struct ObjPosition_B
	{
		int bmax_x;		int bmin_x;
		int bmax_y;		int bmin_y;
	}BPosition;

	enum ItemType{ Treasure_Box = 0};
	ColliderManger() = default;

	Player* player;
	Item* item;

	static ColliderManger* s_pInstance;
}typedef TheColiiderManger;

