#include "SDLGameObject.h"

#include "TextManger.h"
#include "Game.h"

SDLGameObject::SDLGameObject(LoaderParams* pParams)
    : GameObject(pParams),
    m_position(pParams->getX(), pParams->getY()) {

    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextID();
    m_currentRow = 0;
    m_currentFrame = 0;
}

void SDLGameObject::draw() {
    The_TextMananger::Instance()->drawFrame(m_textureID,
        m_position.getX(), m_position.getY(),
        m_width, m_height,
        m_currentRow, m_currentFrame,
        TheGame::Instance()->getRenderer() , SDL_FLIP_NONE);
}