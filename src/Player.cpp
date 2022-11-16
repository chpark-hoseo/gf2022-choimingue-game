#include"Player.h"
#include"Game.h"

#include"TextManger.h"
#include"InputHandler.h"
#include "Vector2D.h"

#include <iostream>

Player::Player(LoaderParams* pParams) : 
	GameCharacter(pParams)
{
	m_State = IDLE;
	m_CurrFw = 38;
	m_CurrFh = 58;
	m_FrameIntv = 75;
	m_CurrF = 0;

	// 애니메이션 관련 변수
	m_aniWF = 0;
	m_aniAF = 0;

	// <기본 상태 관련 변수>
	m_IDLEW = 38;
	m_IDLEH = 58;

	// <이동 관련 변수>
	m_WALKW = 38;
	m_WALKH = 58;
	m_WALK_FullCnt = 8;

	// <공격 관련 변수>
	m_ATT_FullCnt = 6;
	m_ATTW = 75;
	m_ATTH = 75;	

	// <스탯>
	m_hp = 1000;
	m_damage = 10;
	m_WSpeed = 0;
}

void Player::update()
{
	while (m_State == HIT)
	{
		m_position.setY(-1);
		m_CurrHitTime++;
		if (m_CurrHitTime >= m_HitTime)
			break;
	}
	m_CurrHitTime = 0;

	handleInput();

	std::cout << m_hp << std::endl;
	
	switch (m_State)
	{
	case IDLE:
		setData(m_IDLEW, m_IDLEH);
		m_aniWF = 0;
		m_aniAF = 0;
		break;

	case WALK:
		m_position.setX(m_WSpeed);

		m_aniWF += m_ANISpeed;
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

void Player::draw()
{
	if (isRight)
		The_TextMananger::Instance()->drawFrame("Player",
			m_position.getX(), m_position.getY() - 5,
			m_CurrFw, m_CurrFh,
			m_State * m_FrameIntv, m_CurrF,
			TheGame::Instance()->getRenderer(),
			SDL_FLIP_HORIZONTAL);
	else
		The_TextMananger::Instance()->drawFrame("Player",
			m_position.getX(), m_position.getY() - 5,
			m_CurrFw, m_CurrFh,
			m_State * m_FrameIntv, m_CurrF,
			TheGame::Instance()->getRenderer(),
			SDL_FLIP_NONE);
}

void Player::setSpeed(int P_WSpeed) {
	m_WSpeed = P_WSpeed;
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