#pragma once
#include"game.h"
#include "GameObject.h"
#include "vector"

class Game
{
private:
	Game() {}
	static Game* s_pInstatance;

public:
	// �̱��� ����
	static Game* Instance()
	{
		if (s_pInstatance == NULL) {
			s_pInstatance = new Game();
		}
		return s_pInstatance;
	}

	SDL_Renderer* getRenderer() const;

	// ������ ũ��
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 480;

	// ������ ����
	bool init(const char* Stitle, int xpos, int ypos, int Swidth, int Sheight, int flags);

	// ���� ���� ����
	void update();

	// ȭ�� ����
	void renderer();

	SDL_Renderer* getRenderer() { return m_pRenderer; }

	// �����۵������� Ȯ��
	bool running();

	// ���� ����
	void handleEvent();

	// ȭ�� �����
	void clean();

	void quit();

	const char* adr_Kskull = "assets/KnifeSkull_Idle.png";			// Į�� ������ �ּ�
	const char* adr_Askull = "assets/AxeSkull_Full.png";			// ���� ������ �ּ�

private:
	SDL_Window* m_pWindow = NULL;
	SDL_Renderer* m_pRenderer = NULL;

	bool m_bRunning = false;

	// <�÷��̾��� ���� �⺻ ����>
	const int Pwalk_FrameW = 38;									// �÷��̾� �⺻ ���� Idle�� ����, 38
	const int Pwalk_FrameH = 58;									//								 , 58

	// <�ʱ� ���� ��ǥ>
	const int Ground_yPos = 330;									// ������ y��ǥ

	// <������ ���� ����>
	int m_AxSk_Speed = 0;											// �������� �ٰ����� �ӵ�
	int m_AxSk_xPos = 500;											// �������� x ��ǥ
	int m_AxSk_State = 0;											// ���� �������� ����

	int m_AxSkHp = 50;
	int m_AxSkCurrFh = 47;											// ���� ������ ����
	int m_AxSkCurrF = 0;											// ���� ���° ������

	const char* adr_Char = "assets/Zelda_Walk+Attack.png";			// ������ �׸� �ּ�
	const char* adr_Bg = "assets/Back_Ground2.png";					// ��� �׸��� �ּ�

	const char* adr_GameOver = "assets/Big_GameOver.png";				// ���� ������ �ּ�

	std::vector<GameObject*> m_gameObjects;
}typedef TheGame;