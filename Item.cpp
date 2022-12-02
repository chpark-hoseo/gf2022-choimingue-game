#include "Item.h"

#include"TextManger.h"
#include"Game.h"

Item::Item(LoaderParams* pParams)
	:SDLGameObject(pParams)
{
	m_position.setX(TheGame::Instance()->SCREEN_WIDTH);
}

void Item::draw()
{
	The_TextMananger::Instance()->drawMove(m_textureID,
		m_CurrXpos, m_position.getY(),
		TheGame::Instance()->getRenderer());
}

void Item::update()
{
	m_CurrXpos = m_position.getX() - MoveSpeed;
}

void Item::getBgSpeed(int MoveSpeed)
{
	this->MoveSpeed = MoveSpeed;
}