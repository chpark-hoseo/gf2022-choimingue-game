#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Item : public SDLGameObject
{
public:
	enum ItemType
	{
		TBox = 0
	};

	Item(LoaderParams* pParams);
	void draw();
	void update();

	void setBgSpeed(int MoveSpeed);				// 배경의 속도를 가져오는 함수

	int getXpos();								// 자신의 x좌표를 반환함
	int getYpos();								// 자신의 y좌표를 반환함
	void setGroundYPos(int GroundYpos);			// 배경객체에서 땅의 높이를 가져옴

	int getFrameH();							// 자신의 높이를 반환

	int getItemType();
	void setItemType(int ItemType);

private:
	int MoveSpeed = 0;							// 배경의 속도에 따라 위치가 변경되는값
	int m_CurrXpos = 0;

	const int m_TBox_FrameH = 70;
	const int m_TBox_FrameW = 70;

	int m_GroundYpos;							// 땅의 y좌표

	int m_CurrItem_Type;						// 현재 아이템의 종류를 가져온다.
};

