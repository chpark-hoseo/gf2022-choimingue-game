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

	void setPlayerData(Player* player);									// �÷��̾� ��ü�� ������
	void setItemData(Item* item);										// ������ ��ü�� ������
	void setDefaultData();												// �浹 ��ǥ���� �����͸� �־���

	bool AABBCheck();													// �浹 �˻�
	int getCollTag();													// �浹�� �������� �±׸� ������

private:
	struct ObjPosition				// a���� �÷��̾�, b���� �����۰� ����
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

