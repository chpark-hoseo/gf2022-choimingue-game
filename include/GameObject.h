#pragma once
#include "LoaderParams.h"

class GameObject {

public:
	// ��������Ʈ�� �����͸� �������� �Լ�

	virtual void draw() = 0;									// �׸��� �׷��ִ� �Լ�
	virtual void update() = 0;									// ��������� ��������, ������ �̵�
	virtual void clean() = 0;									// �׸� �����͸� �����ϴ� �Լ�

protected:
	GameObject(const LoaderParams* pParms){}
};