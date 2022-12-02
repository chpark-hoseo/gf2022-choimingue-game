#pragma once
#include "Player.h"

class InterfaceManger
{
public:
	enum ItemType
	{
		TBox = 0
	};

	static InterfaceManger* Instance()
	{
		if (s_pInstance == NULL)
			s_pInstance = new InterfaceManger();

		return s_pInstance;
	}

	void setDefaltData(Player* player);
	void gameOverdraw();
	void gameEndingdraw();

private:
	InterfaceManger() = default;
	static InterfaceManger* s_pInstance;
	
	Player* player = NULL;

}typedef TheInterfaceManger;