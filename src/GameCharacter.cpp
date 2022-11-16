#include "GameCharacter.h"
#include "TextManger.h"

GameCharacter::GameCharacter(LoaderParams* pParams)
    : SDLGameObject(pParams) 
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

void GameCharacter::setState(int State)
{
    m_State = State;
}

void GameCharacter::setHp(int damage)
{
    m_hp += damage;
}

int GameCharacter::getState()
{
    return m_State;
}

int GameCharacter::getHp()
{
    return m_hp;
}

int GameCharacter::getXPos()
{
    return m_position.getX();
}

int GameCharacter::getATTWidth()
{
    return m_ATTW;
}

int GameCharacter::getCurrATTF()
{
    return m_CurrF;
}

int GameCharacter::getDamage()
{
    return m_damage;
}