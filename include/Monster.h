#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
	void update();

private:
	void suttleRun();
	int m_objRightW;								// 스프라이트 오른쪽 끝에 좌표 (x좌표 + 스프라이트 길이)

	int obj_Speed = 2;								// 몬스터 객체의 스피드
	bool isRight = true;
};

