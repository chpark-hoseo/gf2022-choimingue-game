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
		// ����� �������� �Ѿ��, ����� ������ �������� �ʾҴٸ�
		if (player->getXPos() >= mBg_START && mBg_CurrXpos < mBg_END) {
			mBg_MoveSpeed = mP_WalkSpeed;
			DistToDest = mP_WalkSpeed;

			player->setSpeed(0);
		}

		// ������ ��� �������� ����������, ��ũ������ �� ������ �� �ִٸ�
		else if (mBg_CurrXpos > mBg_END && player->getXPos() + player->getSpeed() < mP_MAX_XPOS) {
			mBg_MoveSpeed = 0;
			DistToDest = mP_WalkSpeed;
			player->setSpeed(mP_WalkSpeed);

			std::cout << "Still Walk " << std::endl;
		}

		// ��ũ���� ���� �����ߴٸ�
		else if (player->getXPos() + player->getSpeed() > mP_MAX_XPOS) {
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
			DistToDest =0;
			player->setSpeed(0);
		}

		// ��� �� ���� ~ �������� ������
		else if (player->getXPos() > 0 &&
			player->getXPos() < mBg_START) 
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
	// 3�� �浹 ������ ����������,
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
		// 3�� �浹 ������ ������ ���� ����������
		if (m_CurrBlock_MinX <= 0) {

			// �浹��, �÷��̾�� ����� ���߰�
			if (AABBCheck()) {
				mBg_MoveSpeed = 0;
				player->setSpeed(0);
			}

			// �浹�� ���ҽ�, ���� ���� ����ŭ ����
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