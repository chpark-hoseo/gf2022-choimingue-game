#include"main.h"

#include "Monster.h"

#include "TextManger.h"

Monster::Monster(LoaderParams* pParam)
    :SDLGameObject(pParam)
{

}

void Monster::update()
{
    m_position.setX(m_position.getX() + 1);
    m_position.setY(m_position.getY() + 1);

    m_currFrame = ((SDL_GetTicks() / 100) % 6);
}

void Monster::clean()
{
    TheTextureManager::get_Instance()->Destory_T(m_textureID);
}