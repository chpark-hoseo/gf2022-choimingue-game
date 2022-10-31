#pragma once
#include "main.h"
#include "TextManger.h"
#include "GameObject.h"
#include "Player.h"

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
	SDL_Window* m_pWindow;					// ����â ���� ����
	SDL_Renderer* m_pRenderer;				// �׸�â ���� ���� 
	bool m_bRunning;						// ������ ���� �۵��ϴ��� ����

	GameObject m_GmObj;						// ���� ������Ʈ ��ü
	Player m_GmPl;							// �÷��̾� ������Ʈ ��ü

	const char* adr_Dog = "assets/animate-alpha.png";				// ĳ������ �׸� �ּ�
	const int m_DogW = 128;											// �������� ���� ��������Ʈ ����, 128
	const int m_DogH = 98;											// �������� ���� ��������Ʈ ����, 98
	int m_DogCurrFrame = 0;											// �������� ���� ������, 0
};