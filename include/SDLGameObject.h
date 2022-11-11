#pragma once
#include "GameObject.h"
#include "LoaderParams.h"

class SDLGameObject : public GameObject
{
public :
	SDLGameObject(LoaderParams* pParam);

	virtual void draw();									// �׸��� �׷��ִ� �Լ�
	virtual void update() {}								// ��������� ��������, ������ �̵�
	virtual void clean() {}									// �׸� �����͸� �����ϴ� �Լ�

	virtual ~SDLGameObject() {}

protected:
	int m_x, m_y;
	int m_width, m_height;
	int m_currRow, m_currFrame;
	std::string m_textureID;
};

