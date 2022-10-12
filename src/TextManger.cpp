#include "TextManger.h"
#include "Game.h"

Game game;

bool TextManger::load(const char* fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* ptSurface = NULL;
	SDL_Texture* texture = NULL;

	ptSurface = IMG_Load(fileName);							// 그림 데이터를 가져옴

	texture = SDL_CreateTextureFromSurface(pRenderer, ptSurface);
	SDL_FreeSurface(ptSurface);

	if (texture != nullptr) {
		m_textureMap[id] = texture;
		return true;
	}
	else
		return false;
}

void TextManger::draw(std::string id, const int Screen_xPos, const int Screen_yPos, int width, int height,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect src;
	SDL_Rect dis;

	src.x = 0;
	src.y = 0;

	src.w = dis.w = width;
	src.h = dis.h = height;

	dis.x = Screen_xPos;
	dis.y = Screen_yPos;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &src, &dis, 0, NULL, flip);
}

void TextManger::drawMove(std::string id, const int Screen_xPos, const int Screen_yPos,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect src;
	SDL_Rect dis;

	SDL_QueryTexture(m_textureMap[id], NULL, NULL, &src.w, &src.h);

	src.x = Screen_xPos;
	src.y = 0;

	dis.w = src.w = game.SCREEN_WIDTH;
	dis.h = src.h;

	dis.x = 0;
	dis.y = Screen_yPos;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &src, &dis, 0, NULL, flip);
}

void TextManger::drawFrame(std::string id, const int Screen_xPos, const int Screen_yPos,
	const int Frame_w, const int Frame_h, int CurrRow, int CurrFrame,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect src;
	SDL_Rect dis;

	src.x = Frame_w * CurrFrame;
	src.y = CurrRow;

	src.w = dis.w = Frame_w;
	src.h = dis.h = Frame_h;

	dis.x = Screen_xPos;
	dis.y = Screen_yPos;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &src, &dis, 0, NULL, flip);
}

void TextManger::Delet_Texture(std::string id)
{
	SDL_DestroyTexture(m_textureMap[id]);
}