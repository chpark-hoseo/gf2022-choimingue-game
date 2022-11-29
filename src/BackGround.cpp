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