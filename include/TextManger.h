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

	// �׸� ������ �������� ������ ����
	bool load(const char* fileName, std::string id, SDL_Renderer* pRenderer);

	//������ �׸��� �׸��� �Լ� (�±�, ȭ�� ��ǥx, ȭ�� ��ǥy, �׸� ����, ����)
	void draw(std::string id, const int Screen_xPos, const int Screen_yPos, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// �÷��̾��� �����ӿ� ���� ����� ���� �׸��� ������
	void drawMove(std::string id, int Scr_xPos, const int Screen_yPos,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// �ִϸ��̼� �۾��� �� �׸�
	void drawFrame(std::string id, const int Screen_xPos, const int Screen_yPos,
		const int Frame_w, const int Frame_h, int CurrRow, int CurrFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip);

	// ������ �׸��� ����
	void Delet_Texture(std::string id);

private:
	std::map<std::string, SDL_Texture*> m_textureMap;

}typedef The_TextMananger;

