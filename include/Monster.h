#pragma once
#include"SDLGameObject.h"

class Monster : public SDLGameObject
{
public:
	Monster(LoaderParams* pParam);

	void update();
	void clean();

private:

	int obj_Speed = 2;								// 몬스터 객체의 스피드
	bool isRight = true;
};

