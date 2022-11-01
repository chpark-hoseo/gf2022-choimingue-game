#include<GameObject.h>
#include<TextManger.h>
#include <SDL2/SDL.h>

void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_textureID = textureID;
    m_currentRow = 0;
    m_currentFrame = 0;
}

void GameObject::draw(SDL_Renderer* pRenderer) 
{
    The_TextMananger::Instance()
        ->draw(m_textureID,
            m_x, m_y,
            m_width, m_height,
            pRenderer);
}

void GameObject::update()
{

}

void GameObject::move()
{

}

void GameObject::clean()
{
    The_TextMananger::Instance()->Delet_Texture(m_textureID);
}
