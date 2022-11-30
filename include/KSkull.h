#pragma once
#include "Monster.h"

class KSkull : public Monster
{
public:
	KSkull(LoaderParams* pParams);

	void update();
	void draw();
};

