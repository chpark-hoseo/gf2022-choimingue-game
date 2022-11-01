#include"Player.h"
#include"TextManger.h"
#include <iostream>

void Player::update()
{
	if (mP_State == IDLE) {
		setData(mCP_WALKW, mCP_WALKH);
		mP_aniWF = 0;
		mP_aniAF = 0;
	}

	else if (mP_State == WALK) {
		move();
		mP_aniWF += mCP_anifSpeed;
		mP_Currxpos += mP_WSpeed;
		mP_CurrF = (mP_aniWF / 100) % mCP_FULLWALKF;
	}
	else if (mP_State == ATTACK) {
		attack();
		mP_aniAF += mCP_anifSpeed;
		mP_CurrF = (mP_aniAF / 100) % mCP_FULLATTF;
	}

	if (isJump) {
		jump();
	}
}

void Player::setState(int State)
{
	mP_State = State;
}

void Player::setData(int FrameW, int FrameH)
{
	mP_CurrFw = FrameW;
	mP_CurrFh = FrameH;
	mP_CurrF = 0;
}

void Player::setWalkData(int WalkSpeed, int isRight)
{
	mP_WSpeed = WalkSpeed;
	this->isRight = isRight;
}

void Player::setIsJump(int isJump)
{
	this->isJump = isJump;
}

void Player::setBgData(BackGround* GameBg)
{
	this->GameBg = GameBg;
}

int Player::getState()
{
	return mP_State;
}

int Player::getIsJump()
{
	return isJump;
}

void Player::move()
{
	// 오른쪽 이동일때
	if (isRight) {

		// 오른쪽 시작점에 도착했고, 끝이 아니라면
		if (mP_Currxpos + mP_WSpeed >= mCB_STARTF && GameBg->getXpos()< mB_EndP - SCREEN_WIDTH) {
			GameBg->setSpeed(3);
			mP_WSpeed = 0;
		}

		// 배경 화면의 끝에 도닥했으나, 플레이어가 배경의 끝에 도달하지 않았을때
		else if (GameBg->getXpos() >= mB_EndP - SCREEN_WIDTH && mP_Currxpos < SCREEN_WIDTH - mCP_WALKW) {
			GameBg->setSpeed(0);
			mP_WSpeed = 3;
		}

		// 플레이어가 배경의 끝에 도달했을때
		else if (mP_Currxpos >= SCREEN_WIDTH - mCP_WALKW) {
			mP_WSpeed = 0;
		}

		// 그게 아니라, 처음 장소 ~ 출발 장소
		else {
			mP_WSpeed = 3;
		}
	}

	// 왼쪽 이동이라면
	else {

		// 배경 맨 왼쪽이면 움직임을 막는다.
		if (mP_Currxpos + mP_WSpeed <= 0)
			mP_WSpeed = 0;

		// 배경 맨 왼쪽 ~ 시작점에 가기전
		else if (mP_Currxpos > 0 && mP_Currxpos <= mCB_STARTF)
			mP_WSpeed = -3;

		// 시작점을 넘어선다면, 배경이 움직이지 않도록
		else {
			mP_WSpeed = -3;
			GameBg->setSpeed(0);
		}

		mP_Currxpos += mP_WSpeed;
		mP_CurrF = (mP_aniWF / 100) % 8;
	}
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

void Player::drawFrame(SDL_Renderer* m_pRenderer)
{
	if (isRight)
		The_TextMananger::Instance()->drawFrame("Player", mP_Currxpos, mP_yPos, mP_CurrFw, mP_CurrFh, mP_State * mP_FrameIntv, mP_CurrF, m_pRenderer, SDL_FLIP_HORIZONTAL);
	else
		The_TextMananger::Instance()->drawFrame("Player", mP_Currxpos, mP_yPos, mP_CurrFw, mP_CurrFh, mP_State * mP_FrameIntv, mP_CurrF, m_pRenderer, SDL_FLIP_NONE);
}