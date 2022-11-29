#include "BackGround.h"

#include"TextManger.h"
#include"Game.h"

#include <iostream>

BackGround::BackGround(LoaderParams* pParams)
	:SDLGameObject(pParams) 
{
	m_1stCheckP = m_1stFloor_w - TheGame::Instance()->Pwalk_FrameW;
	m_2stCheckP = m_2stFloor_w;
	m_3stCheckP = m_3stFloor_w - mBg_START - TheGame::Instance()->Pwalk_FrameW;

	m_CurrBlock_MaxX = m_1stCheckP;
	m_CurrBlock_MinX = 0;
}

void BackGround::setPlayerData(Player* player)
{
	this->player = player;
}

int BackGround::getBgXpos()
{
	return mBg_CurrXpos;
}

int BackGround::getGroundyPos()
{
	return mGround_yPos;
}

int BackGround::getBgSpeed()
{
	return mBg_MoveSpeed;
}

void BackGround::move_byPlayer()
{
	if (player->getIsRight() && player->getIsMove()) {
		// 배경의 시작점을 넘어섰고, 배경의 끝에는 도달하지 않았다면
		if (player->getXPos() >= mBg_START && mBg_CurrXpos < mBg_END) {
			mBg_MoveSpeed = mP_WalkSpeed;
			DistToDest = mP_WalkSpeed;

			player->setSpeed(0);
		}

		// 마지막 배경 프레임의 도착했지만, 스크린에서 더 움직일 수 있다면
		else if (mBg_CurrXpos > mBg_END && player->getXPos() + player->getSpeed() <= mP_MAX_XPOS) {
			mBg_MoveSpeed = 0;
			DistToDest = mP_WalkSpeed;
			player->setSpeed(mP_WalkSpeed);
		}

		// 스크린의 끝의 도닥했다면
		else if (player->getXPos() + player->getSpeed() >= mP_MAX_XPOS) {
			mBg_MoveSpeed = 0;
			DistToDest = 0;
			player->setSpeed(0);
		}

		// 그게 아니라, 처음 장소 ~ 출발 장소
		else {
			DistToDest = mP_WalkSpeed;
			player->setSpeed(mP_WalkSpeed);
		}
	}
	else if (!player->getIsRight() && player->getIsMove()) {
		// 배경 맨 왼쪽이면 움직임을 막는다.
		if (player->getXPos() <= 0) {
			DistToDest = 0;
			player->setSpeed(0);
		}

		// 배경 맨 왼쪽 ~ 시작점에 가기전
		else if (player->getXPos() > 0 &&
			player->getXPos() + player->getSpeed() <= mBg_START) 
		{
			DistToDest = -mP_WalkSpeed;
			player->setSpeed(mP_WalkSpeed);
		}

		// 시작점을 넘어선다면, 배경이 움직이지 않도록
		else {
			mBg_MoveSpeed = 0;
			DistToDest = -mP_WalkSpeed;
			player->setSpeed(mP_WalkSpeed);
		}
	}
	else {
		DistToDest = 0;
		mBg_MoveSpeed = 0;
	}
}

void BackGround::BlockCheck()
{

	if (m_CurrBlock_MaxX <= 0 || m_CurrBlock_MaxX >= m_2stCheckP) {

		if (AABBCheck()) {
			mBg_MoveSpeed = 0;
		}
		else {
			player->Add_GroundYpos(m_Floor_h);
			m_CurrBlock_MaxX = m_2stCheckP;
			CheckYPos -= m_Floor_h;
		}

		if (m_CurrBlock_MaxX > m_2stCheckP) {
			player->Add_GroundYpos(-m_Floor_h);

			std::cout << player->getYPos() << std::endl;

			if (player->getYPos() < player->getGroundYPos())
			{
				player->setVeloYpos(1);
			}
			else
				player->setVeloYpos(0);
		}
	}
	else {
	}

}

void BackGround::BlockInstall()
{

}

bool BackGround::AABBCheck()
{
	if (player->getYPos() > CheckYPos) {
		DistToDest = 0;
		return true;
	}
	else {
		return false;
	}
}

void BackGround::draw()
{
	The_TextMananger::Instance()->drawMove(m_textureID,
		mBg_CurrXpos, m_position.getY(),
		TheGame::Instance()->getRenderer());
}

void BackGround::update()
{ 
	m_CurrBlock_MaxX -= DistToDest;
	//std::cout << m_CurrBlock_MaxX << "!!" << std::endl;

	move_byPlayer();
	BlockCheck();

	mBg_CurrXpos += mBg_MoveSpeed;
}