#pragma once
#include "main.h"

class Game
{
public:
	// ������ ũ��
	const int SCREEN_WIDTH = 640;
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

	SDL_Texture* m_pCTexture;	// ����̰��� ��
	SDL_Rect m_srcCat;			
	SDL_Rect m_disCat;			

	SDL_Texture* m_pDTexture;	// �������� ������
	SDL_Rect m_srcDog;			
	SDL_Rect m_disDog;			

	SDL_Texture* m_pBgTexture;	// ���
	SDL_Rect m_srcBg;
	SDL_Rect m_disBg;

	// �̹����� �޾ƿ��� �Լ� + bmp�� 0, png�� 1�̴�.
	SDL_Texture* Text_Maker(const char* Par_Objname, SDL_Rect *scr, SDL_Rect *dis, int extDif);

	int ext_bmp = 0;
	int ext_png = 1;

	int obj_Speed = 1;										// ��ü�� �����̴� �ӵ� = 1
	int nChgWay_Cnt = 0;									// ���� ������ �ٲ� Ƚ��

	const int yPower = 30;

	// �ǽ� 1��
	//const char* adr_Cat = "assets/animate.png";
	
	// �ǽ� 2��
	const char* adr_Cat = "assets/animate-alpha.png";				// ĳ������ �׸� �ּ�
	const char* adr_Bg = "assets/Back_Ground.png";
	const char* adr_Dog = "assets/Dogge.png";

	int m_angle = 0;
};