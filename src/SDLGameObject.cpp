#include "SDLGameObject.h"
#include "TextManger.h"
#include "Game.h"

SDLGameObject::SDLGameObject(LoaderParams* pParam)
	:GameObject(pParam)
{
	m_x = pParam->getX();
	m_y = pParam->getY();
	
	m_width = pParam->getWidth();
	m_height = pParam->getHeight();
	m_textureID = pParam->getTextID();

	m_currRow = 0;
	m_currFrame = 0;
}

void SDLGameObject::draw()
{
	TheTextureManager::get_Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currRow, m_currFrame, TheGame::getInstace()->getRenderer());
}