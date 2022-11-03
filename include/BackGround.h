#pragma once
#include<SDL2/SDL.h>
#include"GameObject.h"

class BackGround : public GameObject
{
public:
	// �׷��� ��ġ��, �±׸� �޾ƿ�
	void load(int y, std::string textureID);

	// �׸��� �׸�, drawMove
	void drawMove(SDL_Renderer* pRenderer);

	// �÷��̾� ��ü���Լ� ����� �ӵ��� ������
	void setSpeed(int MoveSpeed);

	// ����� x ��ǥ�� ������
	int getXpos();

	// ����� �������� ���ߴ� ��ǥ�� ������ (����, ����� �������� ����)
	int getBg_End();

	// ����� �����̴� �������� ��ǥ�� ������ (����, ����� ������)
	int getBg_Start();

	void update();

private:
	int mBg_MoveSpeed = 0;					// ����� �����̴� �ӵ�
	int mBg_CurrXpos = 0;					// ����� ���� x ��ǥ

	int mBg_END = 5000 - SCREEN_WIDTH;								// ����� �������� ������ ��ǥ
	int mBg_START = SCREEN_WIDTH / 3.0;								// ����� �����̱� �����ϴ� ��ǥ
};

