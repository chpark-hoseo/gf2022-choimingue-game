#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Item : public SDLGameObject
{
public:
	Item(LoaderParams* pParams);
	void draw();
	void update();

	void getBgSpeed(int MoveSpeed);				// 배경의 속도를 가져오는 함수

private:
	int MoveSpeed = 0;							// 배경의 속도에 따라 위치가 변경되는값
	int m_CurrXpos = 0;
};

