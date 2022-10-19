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
	SDL_Texture* m_pTexture;

	bool m_bRunning;

	enum State
	{
		IDLE, WALK, ATTACK, HIT, DEAD
	};

	int m_anit_Pw = 0;
	int m_anit_Pa = 0;
	int m_anifSpeed = 15;

	// <�÷��̾ ���� � ���������� ���� �޶���>
	int m_objState = IDLE;											// �÷��̾��� ���� ����
	int m_objCurrFw = 38;											// �÷��̾ ���� � �������̰�, �ʺ� ����
	int m_objCurrFh = 58;											//									���̰� ����
	int m_Intv_pFrame = 75;											// ������ ������ ����
	int m_objCurrF = 0;												// �÷��̾�� ���� ���° ����������

	// <�÷��̾��� �ӵ� ���� ����>
	int obj_pWSpeed = 0;											// �÷��̾� �ӵ�
	float obj_pJSpeed = 1;											// �÷��̾��� ���� �ӵ�

	bool isRight = false;											// ������ �������� Ȯ��
	bool isAttack = false;											// �÷��̾ �����ϴ��� Ȯ��
	bool isJump = false;											// �÷��̾ �����ϴ��� Ȯ��

	// <�÷��̾��� �̵� ���� ����>
	const int Pwalk_FrameW = 38;									// �÷��̾��� �̵� ������ ����, 38
	const int Pwalk_FrameH = 58;									//						  ����, 58
	int m_CurrPxpos = 0;											// ���� �÷��̾��� x��ǥ

	// <�÷��̾��� ���� ���� ����>
	const int PAtt_FrameW = 75;										// �÷��̾��� ���� ������ ����, 75
	const int PAtt_FrameH = 75;										//						  ����, 75
	int m_CurrPAttF = 0;											// �÷��̾��� ���� ���� ������

	// <�÷��̾��� ���� ���� ����>
	int Player_yPos = 310;											// �÷��̾��� y��ǥ, �ʱⰪ = ������ y��ǥ
	const int Ground_yPos = 310;									// ������ y��ǥ
	const int Max_JumpH = Ground_yPos - 60;							// �ִ� ���� ���� (������ ���� : 310 - �ִ� ���� ���� : 45 )

	// <��� �̵�>
	const int m_BgStartP = SCREEN_WIDTH / 3.0;						// ����� �����̱� �����ϴ� ����
	int m_BgMoveSpeed = 0;											// ����� �����̴� �ӵ�
	int m_BgEndP = 5000;											// ����� ������ ����
	int m_BgMoveEndP = m_BgEndP - SCREEN_WIDTH / 3.0;				// ������ ��

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
};