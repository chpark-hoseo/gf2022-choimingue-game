#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
	Player(LoaderParams* pParams);

	void update();
	void clean();
};

