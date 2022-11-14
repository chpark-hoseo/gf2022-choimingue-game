#include"main.h"
#include "TextManger.h"
#include"InputHandler.h"

#include "Player.h"

Player::Player(LoaderParams* pParams)
	:SDLGameObject(pParams)
{

}

void Player::update()
{
	handleInput();

	m_currFrame = ((SDL_GetTicks() / 100) % 6);
	SDLGameObject::update();
}

void Player::handleInput()
{
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
			m_velocity.setX(2);
		}
		else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
			m_velocity.setX(-2);
		}
		else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
			m_velocity.setY(-2);
		}
		else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
			m_velocity.setY(2);
		}

}

void Player::clean()
{
	TheTextureManager::get_Instance()->Destory_T(m_textureID);
}