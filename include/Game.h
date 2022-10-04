#pragma once
#include"game.h"
#include "main.h"

class Game
{
public:
	// ������ ũ��
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 480;

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

	SDL_Texture* m_pGdTexture;		// �÷��̾�(����)
	SDL_Rect m_srcGd;
	SDL_Rect m_disGd;

	SDL_Texture* m_pBgTexture;		// ���
	SDL_Rect m_srcBg;
	SDL_Rect m_disBg;

	SDL_Texture* m_pKnTexture;		// Į�� ����
	SDL_Rect m_srcKn;
	SDL_Rect m_disKn;

	SDL_Texture* m_pAxTexture;		// ���� ����
	SDL_Rect m_srcAx;
	SDL_Rect m_disAx;

	// �̹����� �޾ƿ��� �Լ� + bmp�� 0, png�� 1�̴�.
	SDL_Texture* Text_Maker(const char* Par_Objname, SDL_Rect* scr, SDL_Rect* dis, int extDif);
	void Text_Ctrl(const char* Par_Objname, SDL_Rect* scr, SDL_Rect* dis);

	int ext_bmp = 0;
	int ext_png = 1;

	int obj_Speed = 1;												// ��ü�� �����̴� �ӵ� = 1
	int nChgWay_Cnt = 0;											// ���� ������ �ٲ� Ƚ��

	const char* adr_Char = "assets/Gelda_Idle.png";					// ������ �׸� �ּ�
	const char* adr_Bg = "assets/Back_Ground.png";					// ��� �׸��� �ּ�
	const char* adr_Kskull = "assets/KnifeSkull_Idle.png";			// Į�� ������ �ּ�
	const char* adr_Askull = "assets/AxeSkull_Idle.png";			// ���� ������ �ּ�
};