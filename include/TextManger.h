#pragma once
#include <SDL2/SDL.h>
#include<map>
#include <string>

class TextManger
{

private:
	TextManger() {}
	~TextManger() {}

	static TextManger* instance;

public:

	// �̱��� ������ ��ü�� ������ ����
	static TextManger* get_Instance()
	{
		if (instance == NULL)
			instance = new TextManger();

		return instance;
	}
		
	// �׸� ������ �������� ������ ����
	bool load(const char* fileName, std::string id, SDL_Renderer* pRenderer);

	//������ �׸��� �׸��� �Լ� (�±�, ȭ�� ��ǥx, ȭ�� ��ǥy, �׸� ����, ����)
	void draw(std::string id, const int Screen_xPos, const int Screen_yPos, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// �ִϸ��̼� �۾��� �� �׸�
	void drawFrame(std::string id, const int Screen_xPos, const int Screen_yPos,
		const int Frame_w,const int Frame_h, int CurrRow, int CurrFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//void Destory_T(std::string id);

private:
	std::map<std::string, SDL_Texture*> m_textureMap;



}typedef TheTextureManager;

