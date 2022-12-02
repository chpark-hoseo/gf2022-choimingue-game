#include "InterfaceManger.h"

#include "TextManger.h"
#include "Game.h"
#include "ColliderManger.h"

void InterfaceManger::setDefaltData(Player* player)
{
	this->player = player;
}

void InterfaceManger::gameOverdraw()
{
	if (player->getHp() <= 0) {

	SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 0, 100);

	The_TextMananger::Instance()->draw("GameOver",
		0, 0,
		TheGame::Instance()->SCREEN_WIDTH, TheGame::Instance()->SCREEN_HEIGHT,
		TheGame::Instance()->getRenderer(),
		SDL_FLIP_NONE);
	}
}

void InterfaceManger::gameEndingdraw()
{
	if (TheColiiderManger::Instance()->AABBCheck() && 
		TheColiiderManger::Instance()->getCollTag() == TBox) {

		The_TextMananger::Instance()->draw("GameEnding",
			0, 0,
			TheGame::Instance()->SCREEN_WIDTH, TheGame::Instance()->SCREEN_HEIGHT,
			TheGame::Instance()->getRenderer(),
			SDL_FLIP_NONE);
	}
}

TheInterfaceManger* TheInterfaceManger::s_pInstance = 0;