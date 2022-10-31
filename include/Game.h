#pragma once
#include "main.h"
#include "TextManger.h"

#include "GameObject.h"
#include "Player.h"
#include "Monster.h"

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
	Monster m_GmMonster_slow;				// ���� ������Ʈ ��ü - 1��°
	Monster m_GmMonster_fast;				// ���� ������Ʈ ��ü - 2��°

	const char* adr_Dog = "assets/animate-alpha.png";				// ĳ������ �׸� �ּ�
	const char* adr_monster = "assets/Dogge.png";					// ������ �׸� �ּ�

	const int m_MonstW = 27;					// ������ ���� ��������Ʈ ����, 27
	const int m_MonstH = 31;					// ������ ���� ��������Ʈ ����, 31
	int m_fastSpeed = 3;						// ���� �ӵ�
	int m_slowSpeed = 1;						//				�����ӵ�

	const int m_DogW = 128;						// �������� ���� ��������Ʈ ����, 128
	const int m_DogH = 98;						// �������� ���� ��������Ʈ ����, 98

	int m_DogCurrFrame = 0;						// �������� ���� ������, 0
};