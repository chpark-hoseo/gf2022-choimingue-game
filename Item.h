#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Item : public SDLGameObject
{
public:
	Item(LoaderParams* pParams);
	void draw();
	void update();

	void getBgSpeed(int MoveSpeed);				// ����� �ӵ��� �������� �Լ�

private:
	int MoveSpeed = 0;							// ����� �ӵ��� ���� ��ġ�� ����Ǵ°�
	int m_CurrXpos = 0;
};

