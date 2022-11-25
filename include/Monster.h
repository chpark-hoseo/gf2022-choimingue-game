#pragma once
#include"SDLGameObject.h"

class Monster : public SDLGameObject
{
public:
	Monster(LoaderParams* pParam);

	void update();
	void clean();

	void HandleInput();

private:

	int obj_Speed = 2;								// ���� ��ü�� ���ǵ�
	bool isRight = true;
};

