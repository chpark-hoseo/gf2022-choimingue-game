#pragma once
#include "Monster.h"

class ASkull : public Monster
{
public:
	ASkull(LoaderParams* pParams);

	void update();
	void draw();
};

