#include"main.h"

#include "Monster.h"

#include "TextManger.h"

Monster::Monster(LoaderParams* pParam)
    :SDLGameObject(pParam)
{

}

void Monster::update()
{
    m_x++;
    m_y++;

    m_currFrame = ((SDL_GetTicks() / 100) % 6);
}

void Monster::clean()
{
    TheTextureManager::get_Instance()->Destory_T(m_textureID);
}