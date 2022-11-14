#include "SDLGameObject.h"
#include "TextManger.h"
#include "Game.h"

SDLGameObject::SDLGameObject(LoaderParams* pParam)
	:GameObject(pParam),
	m_position(pParam->getX(),pParam->getY()), 
	m_velocity(0,0),
	m_acceleration(0,0)
{

	m_width = pParam->getWidth();
	m_height = pParam->getHeight();
	m_textureID = pParam->getTextID();

	m_currRow = 0;
	m_currFrame = 0;
}

void SDLGameObject::draw()
{
	TheTextureManager::get_Instance()->drawFrame(m_textureID, 
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, m_currRow, m_currFrame,
		TheGame::getInstace()->getRenderer());
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}