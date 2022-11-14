#include "SDLGameObject.h"

#include "TextManger.h"
#include "Game.h"

SDLGameObject::SDLGameObject(LoaderParams* pParams)
    : GameObject(pParams) {
    m_x = pParams->getX();
    m_y = pParams->getY();
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextID();
    m_currentRow = 0;
    m_currentFrame = 0;
}

void SDLGameObject::draw() {
    The_TextMananger::Instance()->drawFrame(m_textureID,
        m_x, m_y, m_width,
        m_height, m_currentRow, m_currentFrame,
        TheGame::Instance()->getRenderer() , SDL_FLIP_NONE);
}

void SDLGameObject::setData(int framew, int frameh)
{
   /* m_CurrFw = framew;
    m_CurrFh = frameh;
    m_CurrF = 0;*/
}