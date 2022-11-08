#include "InputHandler.h"
#include "Game.h"

#include "iostream"

void InputHandler::update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			TheGame::Instance()->quit();
		}

		if (event.type == SDL_KEYUP) {
			m_keystates = SDL_GetKeyboardState(0);
			std::cout << "Up" << std::endl;
		}

		if (event.type == SDL_KEYDOWN) {
			m_keystates = SDL_GetKeyboardState(0);
			std::cout << "Down" << std:: endl;
		}
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != NULL) {
		if (m_keystates[key] == 1)
			return true;
		else
			return false;
	}
	return false;

}

void InputHandler::clean()
{

}

InputHandler* InputHandler::s_pInstance = 0;