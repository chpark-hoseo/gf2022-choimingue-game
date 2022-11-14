#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "LoaderParams.h"

class GameObject {

public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	virtual ~GameObject() {}

protected:
	GameObject(LoaderParams* pParams) {}
};