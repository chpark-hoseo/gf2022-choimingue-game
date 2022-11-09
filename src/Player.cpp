#include"Player.h"
#include"TextManger.h"
#include"InputHandler.h"

#include <iostream>

void Player::update()
{
	handleInput();

	if (mP_State == IDLE) {
		setData(mCP_WALKW, mCP_WALKH);
		mP_aniWF = 0;
		mP_aniAF = 0;
		GameBg->setSpeed(0);
	}

	else if (mP_State == WALK) {
		move();
		mP_aniWF += mCP_anifSpeed;
		mP_Currxpos += mP_WSpeed;
		mP_CurrF = (mP_aniWF / 105) % mCP_WALK_FULLCNT;
	}
	else if (mP_State == ATTACK) {
		attack();
		mP_aniAF += mCP_anifSpeed;
		mP_CurrF = (mP_aniAF / 105) % mCP_ATT_FULLCNT;
	}

	if (isJump) {
		jump();
	}
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		setData(mCP_WALKW, mCP_WALKH);
		mP_State = WALK;
		isRight = true;
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		setData(mCP_WALKW, mCP_WALKH);
		mP_State = WALK;
		isRight = false;
	}

	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
		setData(mCP_AttackW, mCP_AttackH);
		mP_State = ATTACK;
	}

	else {
		setData(mCP_WALKW, mCP_WALKH);
		mP_State = IDLE;
	}
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		isJump = true;
	}
}

void Player::setData(int FrameW, int FrameH)
{
	mP_CurrFw = FrameW;
	mP_CurrFh = FrameH;
	mP_CurrF = 0;
}

void Player::move()
{
	// 오른쪽 이동일때
	if (isRight ) {

		// 배경이동의 시작점에 도착했고, 마지막 배경 프레임의 도착하지 않았다면 // GameBg->getXpos() => 100, GameBg->setSpeed(0) => //0
		if (mP_Currxpos + mP_WSpeed >= mBg_Start && GameBg->getXpos() < mBg_End) {
			GameBg->setSpeed(3);

			mP_WSpeed = 0;
		}

		// 마지막 배경 프레임의 도착했지만, 스크린에서 더 움직일 수 있다면
		else if (GameBg->getXpos() >= mBg_End && mP_Currxpos < mP_MAX_XPOS) {
			GameBg->setSpeed(0);
			mP_WSpeed = 2;
		}

		// 스크린의 끝의 도닥했다면
		else if (mP_Currxpos >= mP_MAX_XPOS) {
			mP_WSpeed = 0;
		}

		// 그게 아니라, 처음 장소 ~ 출발 장소
		else {
			mP_WSpeed = 2;
		}
	}

	// 왼쪽 이동이라면
	else {

		// 배경 맨 왼쪽이면 움직임을 막는다.
		if (mP_Currxpos + mP_WSpeed <= 0)
			mP_WSpeed = 0;

		// 배경 맨 왼쪽 ~ 시작점에 가기전
		else if (mP_Currxpos > 0 && mP_Currxpos <= mBg_Start)
			mP_WSpeed = -2;

		// 시작점을 넘어선다면, 배경이 움직이지 않도록
		else {
			GameBg->setSpeed(0);
			mP_WSpeed = -2;
		}
	}

		mP_Currxpos += mP_WSpeed;
		mP_CurrF = (mP_aniWF / 105) % mCP_ATT_FULLCNT;
}

void Player::attack()
{
	if (mP_Currxpos <= m_AxSk_xPos && mP_Currxpos + mP_CurrAttF >= m_AxSk_xPos && mP_CurrAttF >= 3)
	{
		m_AxSk_State = HIT;
		m_AxSkCurrF = (mP_CurrAttF / 100) % 7;
		m_AxSkHp--;

		if (!m_AxSkHp)
			The_TextMananger::Instance()->Delet_Texture("Askull");
	}
}

void Player::jump()
{
	if (isJump) {

		// 최대 높이까지 도착하지 않았다면, 올라가기
		if (mP_yPos > mCP_JUMPMAXH)
			mP_yPos -= mP_JSpeed;

		// 최대 높이의 도달했다면, 떨어지기
		else {
			mP_JSpeed = -mP_JSpeed;
			mP_yPos -= mP_JSpeed;
		}

		// 땅에 도착했다면, 점프 상태가 아님
		if (mP_yPos >= mCB_GYPOS) {
			isJump = false;
			mP_JSpeed = -mP_JSpeed;
		}
	}
}

void Player::draw(SDL_Renderer* m_pRenderer)
{
	if (isRight)
		The_TextMananger::Instance()->drawFrame("Player", mP_Currxpos, mP_yPos, mP_CurrFw, mP_CurrFh, mP_State * mP_FrameIntv, mP_CurrF, m_pRenderer, SDL_FLIP_HORIZONTAL);
	else
		The_TextMananger::Instance()->drawFrame("Player", mP_Currxpos, mP_yPos, mP_CurrFw, mP_CurrFh, mP_State * mP_FrameIntv, mP_CurrF, m_pRenderer, SDL_FLIP_NONE);
}