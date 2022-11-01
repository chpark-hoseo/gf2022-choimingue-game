#pragma once
#include<SDL2/SDL.h>
#include"GameObject.h"

class BackGround : public GameObject
{
public:
	void load(int y, std::string textureID);

	void drawMove(SDL_Renderer* pRenderer);

	void setSpeed(int MoveSpeed);
	int getXpos();

	void update();

private:
	int mBg_MoveSpeed = 0;
	int mBg_CurrXpos = 0;
};

