#include"main.h"
#include "TextManger.h"

#include "Player.h"

Player::Player(LoaderParams* pParams)
	:SDLGameObject(pParams)
{

}

void Player::update()
{
	m_position.setX(m_position.getX() - 1);
	m_currFrame = ((SDL_GetTicks() / 100) % 6);
}

void Player::clean()
{
	TheTextureManager::get_Instance()->Destory_T(m_textureID);
}