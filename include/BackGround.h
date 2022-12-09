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

	int getBgSpeed();

	// <���� �浹�� ���õ� �Լ�>
	void BlockCheck();
	void BlockInstall(int MapFloor);
	bool AABBCheck();

private:
	enum Floor
	{
		 FirstFloor =1, SecondFloor, ThirdFloor, DownFloor
	};

	Player* player = NULL;

	const int mP_WalkW = 38;										// �÷��̾� �ȱ� �������� ����
	const int mP_WALKH = 58;
	//int mP_WalkSpeed = 0;											// �÷��̾��� �ӵ�
	
	int mBg_MoveSpeed = 0;											// ����� �����̴� �ӵ�
	int mBg_CurrXpos = 0;											// ����� ���� x ��ǥ
	int mGround_yPos = 330;											// �ʱ� ���� y ��ǥ

	const int mBg_END = 5000 - SCREEN_WIDTH;						// ����� �������� ������ ��ǥ
	const int mBg_START = SCREEN_WIDTH / 3.0;						// ����� �����̱� �����ϴ� ��ǥ
	const int mP_MAX_XPOS = SCREEN_WIDTH - mP_WalkW;				// �÷��̾ ������ �� �ִ� �ִ� ��ǥ

	const int m_1stFloor_w = 1101;									// ù��° ����� ����
	const int m_2stFloor_w = 1711;									// �ι�° ����� ����
	const int m_3stFloor_w = 1228;									// ����° ����� ����

	int m_1stCheckP;												// ù��° �浹 ����
	int m_2stCheckP;												// �ι�° �浹 ����
	int m_3stCheckP;												// ����° �浹 ����

	const int m_Floor_h = 26;										// ��ϸ����� ����
	const int m_Final_FloorH = 52;

	int m_CurrBlock_MaxX;											// ���� �浹�� �ִ� x��
	int m_CurrBlock_MinX;											// ���� �浹�� �ּ� x��

	int DistToDest = 0;												// ������������ �Ÿ����� �������ִ°�
	
	int FloorState = 1;												// ���� ����, �⺻�� = 1
	int m_CurrCheckP = m_2stFloor_w;								// ���� �浹 üũ ����
	bool IsDown = false;

	int CheckYPos = mGround_yPos - m_Floor_h;						// ���� �浹üũ�� y���� ��ǥ
};