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

	m_position.setY(mBG_YPOS);

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
	m_hp = 100;
	m_damage = 10;
	m_WSpeed = 3;
}

void Player::update()
{
	m_CurrHitTime = 0;

	if(m_State != DIE)
		handleInput();
	
	switch (m_State)
	{
	case IDLE:
		setData(m_IDLEW, m_IDLEH);
		m_aniWF = 0;
		m_aniAF = 0;

		m_velocity.setX(0);
		break;

	case WALK:
		m_velocity.setX(m_WSpeed);

		m_aniWF += m_ANISpeed;
		m_CurrF = (m_aniWF / 105) % m_WALK_FullCnt;
		break;

	case ATTACK:
		m_aniAF += m_ANISpeed;
		m_CurrF = (m_aniAF / 90) % m_ATT_FullCnt;

		m_velocity.setX(0);
		break;

	case DIE:
		clean();

	default:
		break;
	}
	
	/*if (m_position.getY() > m_GroundYpos)
	{
		m_velocity.setY(1);
	}
	else
		m_velocity.setY(0);*/

	if (isJump) {
		jump();
	}


	SDLGameObject::update();
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

		m_WSpeed = -m_WSpeed;
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
			m_position.getX(), m_position.getY()-5,
			m_CurrFw, m_CurrFh,
			m_State * m_FrameIntv, m_CurrF,
			TheGame::Instance()->getRenderer(),
			SDL_FLIP_HORIZONTAL);

	else
		The_TextMananger::Instance()->drawFrame("Player",
			m_position.getX(), m_position.getY()-5,
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

	if (m_State == WALK) {
		return true;
	}
	else
		return false;
}

int Player::getSpeed() {
	return m_velocity.getX();
}

int Player::getYPos()
{
	return m_position.getY();
}

int Player::getGroundYPos()
{
	return m_GroundYpos;
}

void Player::Add_GroundYpos(int GroundYpos)
{
	m_AddYPos = GroundYpos;
}

void Player::setVeloYpos(int P_veloY)
{
	m_velocity.setY(P_veloY);
}

void Player::jump()
{
	m_velocity.setY(-m_JSpeed);

	if (m_position.getY() < m_JUMP_MaxH) {
		m_JSpeed = -m_JSpeed;
		m_velocity.setY(-m_JSpeed);
	}

	else if (m_position.getY() == m_JUMP_MaxH) {
		if (m_AddYPos) {
			m_GroundYpos -= m_AddYPos;
			m_JUMP_MaxH = m_GroundYpos - 60;
			m_AddYPos = 0;
			std::cout << "!!!!!" << std::endl;
		}
	}

	// 땅에 도착했다면, 점프 상태가 아님
	if (m_position.getY() + m_velocity.getY() >= m_GroundYpos) {
		isJump = false;
		m_JSpeed = -m_JSpeed;
		m_velocity.setY(0);
	}
}