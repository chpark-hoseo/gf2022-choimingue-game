#include "BackGround.h"

#include"TextManger.h"
#include"Game.h"

#include <iostream>

BackGround::BackGround(LoaderParams* pParams)
	:SDLGameObject(pParams) 
{
	m_1stCheckP = m_1stFloor_w - mP_WalkW;
	m_2stCheckP = m_2stFloor_w - mP_WalkW;
	m_3stCheckP = m_3stFloor_w;

	m_CurrBlock_MinX = m_1stCheckP;
	m_CurrBlock_MaxX = m_CurrBlock_MinX + mP_WalkW;
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
		else if (mBg_CurrXpos > mBg_END && player->getXPos() + player->getSpeed() < mP_MAX_XPOS) {
			mBg_MoveSpeed = 0;
			DistToDest = mP_WalkSpeed;
			player->setSpeed(mP_WalkSpeed);

			std::cout << "Still Walk " << std::endl;
		}

		// 스크린의 끝의 도닥했다면
		else if (player->getXPos() + player->getSpeed() > mP_MAX_XPOS) {
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
			DistToDest =0;
			player->setSpeed(0);
		}

		// 배경 맨 왼쪽 ~ 시작점에 가기전
		else if (player->getXPos() > 0 &&
			player->getXPos() < mBg_START) 
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
	// 3층 충돌 지점을 도닥했을때,
	if (FloorState == ThirdFloor
		&& m_CurrBlock_MinX <= m_3stCheckP - SCREEN_WIDTH / 3) {

		FloorState = DownFloor;
	}

	if(FloorState >= DownFloor){
		if (m_CurrBlock_MinX <= 0 && !IsDown)
		{
			player->Add_GroundYpos(-m_Final_FloorH);
			BlockInstall(FloorState);
			IsDown = true;
		}

		else if (m_CurrBlock_MinX > m_CurrCheckP)
		{
			player->setSpeed(0);
			m_CurrBlock_MinX = m_CurrCheckP;
		}
	}

	else{
		// 3층 충돌 지점을 제외한 곳에 도착했을때
		if (m_CurrBlock_MinX <= 0) {

			// 충돌시, 플레이어와 배경을 멈추고
			if (AABBCheck()) {
				mBg_MoveSpeed = 0;
				player->setSpeed(0);
			}

			// 충돌을 안할시, 한층 높인 값만큼 진행
			else {
				FloorState++;

				player->Add_GroundYpos(m_Floor_h);

				BlockInstall(FloorState);

				CheckYPos -= m_Floor_h;
				mGround_yPos -= m_Floor_h;
			}
		}

		else if (m_CurrBlock_MinX > m_CurrCheckP) {
			FloorState--;

			m_CurrBlock_MinX = 0;
			player->Add_GroundYpos(-m_Floor_h);

			CheckYPos += m_Floor_h;
			mGround_yPos += m_Floor_h;
		}
	}
}

void BackGround::BlockInstall(int MapFloor)
{
	switch (MapFloor)
	{
	case FirstFloor:
		m_CurrBlock_MinX = m_1stFloor_w;
		m_CurrCheckP = m_2stFloor_w;

	case SecondFloor:
		m_CurrBlock_MinX = m_2stFloor_w;
		m_CurrCheckP = m_2stFloor_w;
		break;

	case ThirdFloor:
		m_CurrBlock_MinX = m_3stFloor_w;
		m_CurrCheckP = m_3stFloor_w;
		break;

	case DownFloor:
		m_CurrBlock_MinX = SCREEN_WIDTH - SCREEN_WIDTH / 3;
		m_CurrCheckP = SCREEN_WIDTH - SCREEN_WIDTH / 3;

	default:
		break;
	}
}

bool BackGround::AABBCheck()
{
	if (player->getYPos() > CheckYPos) {
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
	m_CurrBlock_MinX -= DistToDest;

	std::cout << m_CurrBlock_MinX << ", " << m_CurrCheckP << std::endl;

	move_byPlayer();
	BlockCheck();

	mBg_CurrXpos += mBg_MoveSpeed;
}