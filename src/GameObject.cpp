#include "GameObject.h"
#include "TextManger.h"

void GameObject::load(int x, int y, int width, int height, const char* textureID)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_textureID = textureID;
    m_currentRow = 0;
    m_currentFrame = 0;
}

void GameObject::draw(SDL_Renderer* pRenderer) {
    TheTextureManager::get_Instance()->drawFrame
            (m_textureID,
            m_x, m_y,
            m_width, m_height,
            m_currentRow,
            m_currentFrame,
            pRenderer);
}

void GameObject::update()
{
    m_x++;
}

void GameObject::clean()
{
    TheTextureManager::get_Instance()->Destory_T(m_textureID);
}