#pragma once
#include "string"

#include "LoaderParams.h"
#include"GameObject.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(LoaderParams* pParams);
	virtual void draw();
	virtual void update() {}
	virtual void clean() {}
	virtual ~SDLGameObject() {}

	void setData(int framew, int frameh);

protected:
	enum State
	{
		IDLE, WALK, ATTACK, HIT, DIE
	};

	std::string m_textureID;

	int m_x;
	int m_y;
	int m_width;
	int m_height;

	int m_currentFrame;
	int m_currentRow;

	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 480;
};

