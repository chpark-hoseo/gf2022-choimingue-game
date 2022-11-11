#pragma once
#include<SDL2/SDL.h>
#include"GameObject.h"
#include"Player.h"

class BackGround : public GameObject
{
public:

	// �׸��� �׸�, drawMove
	void draw(SDL_Renderer* pRenderer);

	// �÷��̾� ��ü���Լ� ����� �ӵ��� ������
	void setSpeed(int MoveSpeed);

	void move_byPlayer();

	void update();

	void setPlayerData(Player* player);

private:
	Player* player;
	const int mP_WalkW = 38;				// �÷��̾� �ȱ� �������� ����
	const int mP_WalkSpeed = 3;

	int mBg_MoveSpeed = 0;					// ����� �����̴� �ӵ�
	int mBg_CurrXpos = 0;					// ����� ���� x ��ǥ

	int mBg_END = 5000 - SCREEN_WIDTH;								// ����� �������� ������ ��ǥ
	int mBg_START = SCREEN_WIDTH / 3.0;								// ����� �����̱� �����ϴ� ��ǥ
	const int mP_MAX_XPOS = SCREEN_WIDTH - mP_WalkW;				// �÷��̾ ������ �� �ִ� �ִ� ��ǥ
};

