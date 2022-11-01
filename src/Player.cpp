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
	// ������ �̵��϶�
	if (isRight) {

		// ������ �������� �����߰�, ���� �ƴ϶��
		if (mP_Currxpos + mP_WSpeed >= mCB_STARTF && GameBg->getXpos()< mB_EndP - SCREEN_WIDTH) {
			GameBg->setSpeed(3);
			mP_WSpeed = 0;
		}

		// ��� ȭ���� ���� ����������, �÷��̾ ����� ���� �������� �ʾ�����
		else if (GameBg->getXpos() >= mB_EndP - SCREEN_WIDTH && mP_Currxpos < SCREEN_WIDTH - mCP_WALKW) {
			GameBg->setSpeed(0);
			mP_WSpeed = 3;
		}

		// �÷��̾ ����� ���� ����������
		else if (mP_Currxpos >= SCREEN_WIDTH - mCP_WALKW) {
			mP_WSpeed = 0;
		}

		// �װ� �ƴ϶�, ó�� ��� ~ ��� ���
		else {
			mP_WSpeed = 3;
		}
	}

	// ���� �̵��̶��
	else {

		// ��� �� �����̸� �������� ���´�.
		if (mP_Currxpos + mP_WSpeed <= 0)
			mP_WSpeed = 0;

		// ��� �� ���� ~ �������� ������
		else if (mP_Currxpos > 0 && mP_Currxpos <= mCB_STARTF)
			mP_WSpeed = -3;

		// �������� �Ѿ�ٸ�, ����� �������� �ʵ���
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

		// �ִ� ���̱��� �������� �ʾҴٸ�, �ö󰡱�
		if (mP_yPos > mCP_JUMPMAXH)
			mP_yPos -= mP_JSpeed;

		// �ִ� ������ �����ߴٸ�, ��������
		else {
			mP_JSpeed = -mP_JSpeed;
			mP_yPos -= mP_JSpeed;
		}

		// ���� �����ߴٸ�, ���� ���°� �ƴ�
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