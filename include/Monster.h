#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
	void update(const int Screen_RW, int objSpeed);

private:
	void suttleRun(const int Screen_RW, int objSpeed);
	int m_objRightW;								// ��������Ʈ ������ ���� ��ǥ (x��ǥ + ��������Ʈ ����)

	bool isRight = true;
	const int m_cScreen_LW = 0;						// ȭ���� ���� ��
};

