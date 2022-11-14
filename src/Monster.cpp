#include"main.h"

#include "Monster.h"

#include "TextManger.h"

Monster::Monster(LoaderParams* pParam)
    :SDLGameObject(pParam)
{

}

void Monster::update()
{
    m_currFrame = ((SDL_GetTicks() / 100) % 6);
    m_acceleration.setX(1);

    SDLGameObject::update();
}

void Monster::clean()
{
    TheTextureManager::get_Instance()->Destory_T(m_textureID);
}