#include "BackGround.h"

#include"TextManger.h"
#include"Game.h"

#include <iostream>

BackGround::BackGround(LoaderParams* pParams)
	:SDLGameObject(pParams) 
{
	m_1stCheckP = m_1stFloor_w - mP_WalkW;
	m_2stCheckP = m_2stFloor_w - mP_WalkW;
	m_3stCheckP = m_3stFloor_w - mP_WalkW;

	m_CurrBlock_MinX = m_1stCheckP;
	m_CurrBlock_MaxX = m_CurrBlock_MinX + Pwalk_FrameW;
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
		// ����� �������� �Ѿ��, ����� ������ �������� �ʾҴٸ�
		if (player->getXPos() >= mBg_START && mBg_CurrXpos < mBg_END) {
			mBg_MoveSpeed = mP_WalkSpeed;
			DistToDest = mP_WalkSpeed;

			player->setSpeed(0);
		}

		// ������ ��� �������� ����������, ��ũ������ �� ������ �� �ִٸ�
		else if (mBg_CurrXpos > mBg_END && player->getXPos() + player->getSpeed() <= mP_MAX_XPOS) {
			mBg_MoveSpeed = 0;
			DistToDest = mP_WalkSpeed;
			player->setSpeed(mP_WalkSpeed);
		}

		// ��ũ���� ���� �����ߴٸ�
		else if (player->getXPos() + player->getSpeed() >= mP_MAX_XPOS) {
			mBg_MoveSpeed = 0;
			DistToDest = 0;
			player->setSpeed(0);
		}

		// �װ� �ƴ϶�, ó�� ��� ~ ��� ���
		else {
			DistToDest = mP_WalkSpeed;
			player->setSpeed(mP_WalkSpeed);
		}
	}
	else if (!player->getIsRight() && player->getIsMove()) {
		// ��� �� �����̸� �������� ���´�.
		if (player->getXPos() <= 0) {
			DistToDest = 0;
			player->setSpeed(0);
		}

		// ��� �� ���� ~ �������� ������
		else if (player->getXPos() > 0 &&
			player->getXPos() + player->getSpeed() <= mBg_START) 
		{
			DistToDest = -mP_WalkSpeed;
			player->setSpeed(mP_WalkSpeed);
		}

		// �������� �Ѿ�ٸ�, ����� �������� �ʵ���
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

	if (m_CurrBlock_MinX<= 0) {
		if (AABBCheck()) {
			mBg_MoveSpeed = 0;
		}
		else {
			player->Add_GroundYpos(m_Floor_h);
			m_CurrBlock_MinX = m_2stCheckP;
			CheckYPos -= m_Floor_h;
		}
	}

	if (m_CurrBlock_MinX > m_2stCheckP) {
		m_CurrBlock_MinX = 0;
		player->Add_GroundYpos(-m_Floor_h);
	}
}

void BackGround::BlockInstall(int MapFloor)
{
	switch (MapFloor)
	{
	case FirstFloor:
		m_CurrBlock_MinX = m_2stFloor_w;
		m_CurrBlock_MaxX = m_CurrBlock_MinX + Pwalk_FrameW;
		break;

	case SecondFloor:
		m_CurrBlock_MinX = m_3stFloor_w;
		m_CurrBlock_MaxX = m_CurrBlock_MinX + Pwalk_FrameW;
		break;

	default:
		break;
	}
}

bool BackGround::AABBCheck()
{
	if (player->getYPos() > CheckYPos ) {
		DistToDest = 0;
		return true;
	}
	else {
		std::cout << "Don't block" << std::endl;
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

	std::cout << m_CurrBlock_MinX;

	move_byPlayer();
	BlockCheck();

	mBg_CurrXpos += mBg_MoveSpeed;
}