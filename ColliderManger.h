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

	void setObjData(Player* player, Item* item);							// �÷��̾� ��ü�� ������ ��ü�� ������
	void AABBCheck();													// �浹 �˻�
	bool GameEnding(bool IsGameEnding);									// �浹�� ���� ������ ����

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

