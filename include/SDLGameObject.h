#pragma once
#include "string"
#include "Vector2D.h"

#include "LoaderParams.h"
#include"GameObject.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {}
	virtual ~SDLGameObject() {}

protected:
	enum State
	{
		IDLE, WALK, ATTACK, HIT, DIE
	};

	std::string m_textureID;

	int m_width;
	int m_height;

	int m_currentFrame;
	int m_currentRow;

	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 480;

	Vector2D m_position;
	Vector2D m_velocity;
};

