#include "GameCharacter.h"
#include "TextManger.h"

void GameCharacter::load(int x, int y, int width, int height, std::string textureID)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_textureID = textureID;
    m_currentRow = 0;
    m_currentFrame = 0;
}

void GameCharacter::draw(SDL_Renderer* pRenderer)
{
    The_TextMananger::Instance()
        ->draw(m_textureID,
            m_x, m_y,
            m_width, m_height,
            pRenderer);
}

void GameCharacter::update()
{

}

void GameCharacter::clean()
{
    The_TextMananger::Instance()->Delet_Texture(m_textureID);
}

void GameCharacter::setData(int framew, int frameh)
{
    m_CurrFw = framew;
    m_CurrFh = frameh;
    m_CurrF = 0;
}