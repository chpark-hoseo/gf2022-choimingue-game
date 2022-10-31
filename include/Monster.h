#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
	void update(const int Screen_RW, int objSpeed);

private:
	void suttleRun(const int Screen_RW, int objSpeed);
	int m_objRightW;								// 스프라이트 오른쪽 끝에 좌표 (x좌표 + 스프라이트 길이)

	bool isRight = true;
	const int m_cScreen_LW = 0;						// 화면의 왼쪽 끝
};

