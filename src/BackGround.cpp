#include "BackGround.h"
#include"TextManger.h"
#include <iostream>

void BackGround::load(int y, std::string textureID)
{
	m_y = y;
	m_textureID = textureID;
}

void BackGround::setSpeed(int MoveSpeed)
{
	mBg_MoveSpeed = MoveSpeed;
	//std::cout << mBg_MoveSpeed << std::endl;
}

int BackGround::getXpos()
{
	return mBg_CurrXpos;
}

void BackGround::drawMove(SDL_Renderer* pRenderer)
{
	The_TextMananger::Instance()->drawMove(m_textureID, mBg_CurrXpos, m_y, pRenderer);
}

void BackGround::update()
{
	mBg_CurrXpos += mBg_MoveSpeed;
	std::cout << mBg_MoveSpeed << std::endl;
}