#pragma once
#include "main.h"

class Game
{
public:
	// ������ ����
	bool init(const char* Stitle, int xpos, int ypos, int Swidth, int Sheight, int flags);

	// ���� ���� ����
	void update();

	// ȭ�� ����
	void renderer();

	// �����۵������� Ȯ��
	bool running();

	// ���� ����
	void handleEvent();

	// ȭ�� �����
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	SDL_Texture* m_pTexture;
	SDL_Rect m_srcRect;			// ���� �簢��
	SDL_Rect m_disRect;			// ��� �簢��

	// 2��° ������ ��� ����
	SDL_Texture* m_pCutTexture;
	SDL_Rect m_srcCut;
	SDL_Rect m_disCut;

	// �̹����� �޾ƿ��� �Լ� + bmp�� 0, png�� 1�̴�.
	SDL_Texture* Text_Maker(const char* Par_Objname, SDL_Rect *scr, SDL_Rect *dis, int extDif);

	int ext_bmp = 0;
	int ext_png = 1;

	int obj_Speed = 1;										// ��ü�� �����̴� �ӵ� = 1
	int nChgWay_Cnt = 0;									// ���� ������ �ٲ� Ƚ��

	const char* adr_Char = "assets/Char.png";				// ĳ������ �׸� �ּ�
	const char* adr_Bg = "assets/Back_Ground.png";			// ��� �׸��� �ּ�
	const char* adr_Rider = "assets/rider.bmp";				// ���̴� �׸��� �ּ�

	bool IsCutText = false;					// �߶�� �ϴ� �׸����� Ȯ��

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
};