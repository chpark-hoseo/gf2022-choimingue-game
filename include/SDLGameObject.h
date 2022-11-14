#pragma once
#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public :
	SDLGameObject(LoaderParams* pParam);

	virtual void draw();									// 그림을 그려주는 함수
	virtual void update();									// 변경사항을 적용해줌, 오른쪽 이동
	virtual void clean() {}									// 그림 데이터를 삭제하는 함수

	virtual ~SDLGameObject() {}

protected:
	int m_width, m_height;
	int m_currRow, m_currFrame;
	std::string m_textureID;

	Vector2D m_position;
};

