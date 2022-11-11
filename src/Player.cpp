#include"Player.h"
#include"TextManger.h"
#include"InputHandler.h"

#include <iostream>

void Player::update()
{
	handleInput();

	switch (m_State)
	{
	case IDLE:
		setData(m_IDLEW, m_IDLEH);
		m_aniWF = 0;
		m_aniAF = 0;
		break;

	case WALK:
		m_aniWF += m_ANISpeed;
		m_Currxpos += m_WSpeed;
		m_CurrF = (m_aniWF / 105) % m_WALK_FullCnt;
		break;

	case ATTACK:
		m_aniAF += m_ANISpeed;
		m_CurrF = (m_aniAF / 90) % m_ATT_FullCnt;
		break;

	default:
		break;
	}
	

	if (isJump) {
		jump();
	}
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		setData(m_WALKW, m_WALKH);
		m_State = WALK;
		isRight = true;
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		setData(m_WALKW, m_WALKH);
		m_State = WALK;
		isRight = false;
	}

	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
		setData(m_ATTW, m_ATTH);
		m_State = ATTACK;
	}

	else {
		setData(m_WALKW, m_WALKH);
		m_State = IDLE;
	}
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		isJump = true;
	}
}

void Player::draw(SDL_Renderer* m_pRenderer)
{
	if (isRight)
		The_TextMananger::Instance()->drawFrame("Player", m_Currxpos, m_yPos, m_CurrFw, m_CurrFh, m_State * m_FrameIntv, m_CurrF, m_pRenderer, SDL_FLIP_HORIZONTAL);
	else
		The_TextMananger::Instance()->drawFrame("Player", m_Currxpos, m_yPos, m_CurrFw, m_CurrFh, m_State * m_FrameIntv, m_CurrF, m_pRenderer, SDL_FLIP_NONE);
}

void Player::setSpeed(int P_WSpeed) {
	m_WSpeed = P_WSpeed;
}

int Player::getXpos() {
	return m_Currxpos;
}

bool Player::getIsRight(){
	return isRight;
}

bool Player::getIsMove() {
	if(m_State == WALK)
		return true;
	else
		return false;
}

void Player::attack()
{
	if (m_Currxpos <= m_AxSk_xPos && m_Currxpos + m_ATTW >= m_AxSk_xPos && m_CurrAttF >= 3)
	{
		m_AxSk_State = HIT;
		m_AxSkCurrF = (m_CurrAttF / 100) % 7;
		m_AxSkHp--;

		if (!m_AxSkHp)
			return;
			//The_TextMananger::Instance()->Delet_Texture("Askull");
	}
}

void Player::jump()
{
	if (isJump) {

		// 최대 높이까지 도착하지 않았다면, 올라가기
		if (m_yPos > m_JUMP_MaxH)
			m_yPos -= m_JSpeed;

		// 최대 높이의 도달했다면, 떨어지기
		else {
			m_JSpeed = -m_JSpeed;
			m_yPos -= m_JSpeed;
		}

		// 땅에 도착했다면, 점프 상태가 아님
		if (m_yPos >= mBG_YPOS) {
			isJump = false;
			m_JSpeed = -m_JSpeed;
		}
	}
}