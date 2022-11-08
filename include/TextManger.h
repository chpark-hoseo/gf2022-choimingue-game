#pragma once
#pragma once
#include <SDL2/SDL.h>
#include<map>
#include <string>

class TextManger
{
private:
	TextManger() = default;
	static TextManger* s_pInstance;

public:
	static TextManger* Instance()
	{
		if (s_pInstance == NULL)
			s_pInstance = new TextManger();

		return s_pInstance;
	}

	// 그림 파일을 가져오는 역할을 진행
	bool load(const char* fileName, std::string id, SDL_Renderer* pRenderer);

	//정적인 그림을 그리는 함수 (태그, 화면 좌표x, 화면 좌표y, 그림 길이, 높이)
	void draw(std::string id, const int Screen_xPos, const int Screen_yPos, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// 플레이어의 움직임에 따라 배경의 원본 그림이 움직임
	void drawMove(std::string id, int Scr_xPos, const int Screen_yPos,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// 애니매이션 작업을 할 그림
	void drawFrame(std::string id, const int Screen_xPos, const int Screen_yPos,
		const int Frame_w, const int Frame_h, int CurrRow, int CurrFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip);

	// 생성된 그림을 지움
	void Delet_Texture(std::string id);

private:
	std::map<std::string, SDL_Texture*> m_textureMap;

}typedef The_TextMananger;

