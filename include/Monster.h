#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
	void update();

private:
	void suttleRun();
	int m_objRightW;								// ��������Ʈ ������ ���� ��ǥ (x��ǥ + ��������Ʈ ����)

	int obj_Speed = 2;								// ���� ��ü�� ���ǵ�
	bool isRight = true;
};

