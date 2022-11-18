#pragma once

#include "SDLGameObject.h"
#include "Player.h"

#include "LoaderParams.h"

class BackGround : public SDLGameObject
{

public:
	BackGround(LoaderParams* pParams);								// ��� ��ü�� �ε���

	void draw();													// drawMove�Լ��� ���
	void update();													// ����� �̵��ϴ°��� update����
	
	// <��� �̵��� ���õ� �Լ�>
	void setPlayerData(Player* player);								// �÷��̾� ��ü�� �޾ƿ�
	void move_byPlayer();											// �÷��̾��� ��ġ�� ���� ����� �̵�

	// <���� ������ ���õ� �Լ�>
	int getBgXpos();												// ����� x��ǥ�� ������
	int getGroundyPos();											// ����� �� ��ǥ�� ������

private:
	Player* player = NULL;

	const int mP_WalkW = 38;										// �÷��̾� �ȱ� �������� ����
	const int mP_WalkSpeed = 3;

	int mBg_MoveSpeed = 0;											// ����� �����̴� �ӵ�
	int mBg_CurrXpos = 0;											// ����� ���� x ��ǥ
	const int mGround_yPos = 330;

	const int mBg_END = 5000 - SCREEN_WIDTH;						// ����� �������� ������ ��ǥ
	const int mBg_START = SCREEN_WIDTH / 3.0;						// ����� �����̱� �����ϴ� ��ǥ
	const int mP_MAX_XPOS = SCREEN_WIDTH - mP_WalkW;				// �÷��̾ ������ �� �ִ� �ִ� ��ǥ
};

