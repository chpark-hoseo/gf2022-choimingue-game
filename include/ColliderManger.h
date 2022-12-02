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

	void setPlayerData(Player* player);									// 플레이어 객체를 가져옴
	void setItemData(Item* item);										// 아이템 객체를 가져옴
	void setDefaultData();												// 충돌 좌표값의 데이터를 넣어줌

	bool AABBCheck();													// 충돌 검사
	int getCollTag();													// 충돌한 아이템의 태그를 가져옴

private:
	struct ObjPosition				// a값은 플레이어, b값은 아이템과 관련
	{
		int aMax_x;		int bMin_x;
		int aMin_y;		int bMax_y;
	}objPosition;

	enum ItemType{ Treasure_Box = 0};
	ColliderManger() = default;

	Player* player;
	Item* item;

	static ColliderManger* s_pInstance;

}typedef TheColiiderManger;

