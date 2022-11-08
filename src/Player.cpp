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
	}

	else if (mP_State == WALK) {
		move();
		mP_aniWF += mCP_anifSpeed;
		mP_Currxpos += mP_WSpeed;
		mP_CurrF = (mP_aniWF / 100) % mCP_WALK_FULLCNT;
	}
	else if (mP_State == ATTACK) {
		attack();
		mP_aniAF += mCP_anifSpeed;
		mP_CurrF = (mP_aniAF / 100) % mCP_ATT_FULLCNT;
	}

	if (isJump) {
		jump();
	}
}

void Player::handleInput()
{
	std::cout << mP_State;

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		setData(mCP_WALKW, mCP_WALKH);
		mP_State = WALK;
		isRight = true;
		mP_WSpeed = 3;
	}

	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		setData(mCP_WALKW, mCP_WALKH);
		mP_State = WALK;
		isRight = false;
		mP_WSpeed = -3;
	}

	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_KP_A)) {
		setData(mCP_AttackW, mCP_AttackH);
		mP_State = ATTACK;
	}
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_KP_SPACE)) {
		isJump = true;
	}
}

void Player::setData(int FrameW, int FrameH)
{
	mP_CurrFw = FrameW;
	mP_CurrFh = FrameH;
	mP_CurrF = 0;
}

void Player::setBgData(BackGround* GameBg)
{
	this->GameBg = GameBg;
}

void Player::move()
{
	// ������ �̵��϶�
	if (isRight) {

		// ����̵��� �������� �����߰�, ������ ��� �������� �������� �ʾҴٸ�
		if (mP_Currxpos + mP_WSpeed >= mBg_Start && GameBg->getXpos()< mBg_End) {
			GameBg->setSpeed(10);
			mP_WSpeed = 0;
		}

		// ������ ��� �������� ����������, ��ũ������ �� ������ �� �ִٸ�
		else if (GameBg->getXpos() >= mBg_End && mP_Currxpos < mP_MAX_XPOS) {
			GameBg->setSpeed(0);
			mP_WSpeed = 3;
		}

		// ��ũ���� ���� �����ߴٸ�
		else if (mP_Currxpos >= mP_MAX_XPOS) {
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
		else if (mP_Currxpos > 0 && mP_Currxpos <= mBg_Start)
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

void Player::draw(SDL_Renderer* m_pRenderer)
{
	if (isRight)
		The_TextMananger::Instance()->drawFrame("Player", mP_Currxpos, mP_yPos, mP_CurrFw, mP_CurrFh, mP_State * mP_FrameIntv, mP_CurrF, m_pRenderer, SDL_FLIP_HORIZONTAL);
	else
		The_TextMananger::Instance()->drawFrame("Player", mP_Currxpos, mP_yPos, mP_CurrFw, mP_CurrFh, mP_State * mP_FrameIntv, mP_CurrF, m_pRenderer, SDL_FLIP_NONE);
}