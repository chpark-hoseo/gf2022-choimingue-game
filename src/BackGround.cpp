#include "BackGround.h"

#include"TextManger.h"
#include"Game.h"

#include <iostream>

BackGround::BackGround(LoaderParams* pParams)
	:SDLGameObject(pParams) 
{

}

void BackGround::setSpeed(int MoveSpeed)
{
	mBg_MoveSpeed = MoveSpeed;
}

void BackGround::setPlayerData(Player* player)
{
	this->player = player;
}

void BackGround::move_byPlayer()
{

	if (player->getIsRight() && player->getIsMove()) {
		if (player->getXPos() + player->getSpeed() >= mBg_START && mBg_CurrXpos < mBg_END) {
			mBg_MoveSpeed = 3;

			player->setSpeed(0);
		}

		// ������ ��� �������� ����������, ��ũ������ �� ������ �� �ִٸ�
		else if (mBg_CurrXpos > mBg_END && player->getXPos() + player->getSpeed() <= mP_MAX_XPOS) {
			mBg_MoveSpeed = 0;
			player->setSpeed(mP_WalkSpeed);
		}

		// ��ũ���� ���� �����ߴٸ�
		else if (player->getXPos() + player->getSpeed() >= mP_MAX_XPOS) {
			player->setSpeed(0);
		}

		// �װ� �ƴ϶�, ó�� ��� ~ ��� ���
		else {
			player->setSpeed(mP_WalkSpeed);
		}
	}
	else if (!player->getIsRight() && player->getIsMove()) {
		// ��� �� �����̸� �������� ���´�.
		if (player->getXPos() < 0) {
			player->setSpeed(0);
		}

		// ��� �� ���� ~ �������� ������
		else if (player->getXPos() + player->getSpeed() >= 0 && player->getXPos() + player->getSpeed() <= mBg_START) {
			player->setSpeed(mP_WalkSpeed);
		}

		// �������� �Ѿ�ٸ�, ����� �������� �ʵ���
		else {
			mBg_MoveSpeed = 0;
			player->setSpeed(mP_WalkSpeed);
		}
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
	move_byPlayer();
	mBg_CurrXpos += mBg_MoveSpeed;
}