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

		// 마지막 배경 프레임의 도착했지만, 스크린에서 더 움직일 수 있다면
		else if (mBg_CurrXpos > mBg_END && player->getXPos() + player->getSpeed() <= mP_MAX_XPOS) {
			mBg_MoveSpeed = 0;
			player->setSpeed(mP_WalkSpeed);
		}

		// 스크린의 끝의 도닥했다면
		else if (player->getXPos() + player->getSpeed() >= mP_MAX_XPOS) {
			player->setSpeed(0);
		}

		// 그게 아니라, 처음 장소 ~ 출발 장소
		else {
			player->setSpeed(mP_WalkSpeed);
		}
	}
	else if (!player->getIsRight() && player->getIsMove()) {
		// 배경 맨 왼쪽이면 움직임을 막는다.
		if (player->getXPos() < 0) {
			player->setSpeed(0);
		}

		// 배경 맨 왼쪽 ~ 시작점에 가기전
		else if (player->getXPos() + player->getSpeed() >= 0 && player->getXPos() + player->getSpeed() <= mBg_START) {
			player->setSpeed(mP_WalkSpeed);
		}

		// 시작점을 넘어선다면, 배경이 움직이지 않도록
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