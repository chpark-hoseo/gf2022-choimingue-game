#pragma once
#include"game.h"
#include "main.h"
#include "Player.h"
#include "vector"

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
	SDL_Texture* m_pTexture;

	bool m_bRunning;

	enum State
	{
		IDLE, WALK, ATTACK, HIT, DEAD
	};

	// <�÷��̾��� �̵� ���� ����>
	const int Pwalk_FrameW = 38;									// �÷��̾� �⺻ ���� Idle�� ����, 38
	const int Pwalk_FrameH = 58;									//								 , 58

	// <�÷��̾��� ���� ���� ����>
	const int Ground_yPos = 380;									// ������ y��ǥ

	// <������ ���� ����>
	int m_AxSk_Speed = 0;											// �������� �ٰ����� �ӵ�
	int m_AxSk_xPos = 500;											// �������� x ��ǥ
	int m_AxSk_State = 0;											// ���� �������� ����

	int m_AxSkHp = 50;
	int m_AxSkCurrFh = 47;											// ���� ������ ����
	int m_AxSkCurrF = 0;											// ���� ���° ������

	const char* adr_Char = "assets/Zelda_Walk+Attack.png";			// ������ �׸� �ּ�
	const char* adr_Bg = "assets/Back_Ground2.png";					// ��� �׸��� �ּ�
	const char* adr_Kskull = "assets/KnifeSkull_Idle.png";			// Į�� ������ �ּ�
	const char* adr_Askull = "assets/AxeSkull_Full.png";			// ���� ������ �ּ�

	std::vector<GameObject*> m_gameObjects;
};