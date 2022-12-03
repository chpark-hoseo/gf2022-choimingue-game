#include "Item.h"

#include"TextManger.h"
#include"Game.h"
//#include "ColliderManger.h"

#include"iostream"

Item::Item(LoaderParams* pParams)
	:SDLGameObject(pParams)
{
}

void Item::draw()
{
	The_TextMananger::Instance()->draw(m_textureID,
		m_position.getX(), m_GroundYpos,
		m_TBox_FrameW, m_TBox_FrameH,
		TheGame::Instance()->getRenderer());
}

void Item::update()
{
	m_velocity.setX(-MoveSpeed);
	SDLGameObject::update();
}

void Item::setBgSpeed(int MoveSpeed)
{
	this->MoveSpeed = MoveSpeed;
}

int Item::getXpos()
{
	return m_position.getX();
}

int Item::getYpos()
{
	return m_position.getY();
}

void Item::setGroundYPos(int GroundYpos)
{
	this->m_GroundYpos = GroundYpos;

	m_position.setY(GroundYpos);
	std::cout << m_position.getY() << std::endl;
}

int Item::getFrameH()
{
	return m_TBox_FrameH;
}

int Item::getItemType()
{
	return m_CurrItem_Type;
}

void Item::setItemType(int ItemType)
{
	m_CurrItem_Type = ItemType;
}