#pragma once
#include "main.h"
#include "TextManger.h"

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
	TextManger m_textManger;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int obj_Speed = 1;										// ��ü�� �����̴� �ӵ� = 1
	int nChgWay_Cnt = 0;									// ���� ������ �ٲ� Ƚ��

	const char* adr_Dog = "assets/animate-alpha.png";				// ĳ������ �׸� �ּ�
	const int m_DogW = 128;
	const int m_DogH = 98;
	int m_DogCurrFrame = 0;
};