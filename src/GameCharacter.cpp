#include "GameCharacter.h"
#include "TextManger.h"

GameCharacter::GameCharacter(LoaderParams* pParams)
    : SDLGameObject(pParams) 
{

}

void GameCharacter::setData(int framew, int frameh)
{
    m_CurrFw = framew;
    m_CurrFh = frameh;
    m_CurrF = 0;
}