#include"main.h"

#include "Monster.h"

#include "TextManger.h"
#include "InputHandler.h"

Monster::Monster(LoaderParams* pParam)
    :SDLGameObject(pParam)
{

}

void Monster::update()
{
    m_currFrame = ((SDL_GetTicks() / 100) % 6);
    HandleInput();

    SDLGameObject::update();
}

void Monster::HandleInput()
{
    if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::Instance()->LEFT)) {
        printf("shoot \n");
    }
    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    m_velocity = (*vec - m_position) / 100;
}

void Monster::clean()
{
    TheTextureManager::get_Instance()->Destory_T(m_textureID);
}