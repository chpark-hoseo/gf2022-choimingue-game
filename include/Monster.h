#pragma once
#include"SDLGameObject.h"

class Monster : public SDLGameObject
{
public:
	Monster(LoaderParams* pParam);

	void update();
	void clean();

private:

	int obj_Speed = 2;								// ���� ��ü�� ���ǵ�
	bool isRight = true;
};

