#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public :
	void update();
	void handleInput();
	void draw(SDL_Renderer* m_pRenderer);

	void setSpeed(int P_WSpeed);									// �÷��̾��� ���ǵ尪�� �����Ŵ (Bg��ü�ּ� ���)
	void setData(int FrameW, int FrameH);
	
	int getXpos();													// �÷��̾��� x ��ǥ�� ������
	bool getIsRight();												// �÷��̾��� ������ Ȯ��
	bool getIsMove();												// �÷��̾ �����̴����� Ȯ��

	void attack();													// ���� �Լ�
	void jump();													// ���� �Լ�

protected:

	// <�÷��̾ ���� � ���������� ���� �޶���>
	int m_State = IDLE;												// ���� ����
	int m_CurrFw = 38;												// ���� ���¿� ���� �������� �ʺ�
	int m_CurrFh = 58;												// ���� ���¿� ���� �������� ����
	int m_FrameIntv = 75;											// ������ ������ ����
	int m_CurrF = 0;												// ���� ���° ����������

	// �÷��̾��� �ִϸ��̼� ���� ����
	int m_aniWF = 0;												// �ȱ� �������� �ٲ�� ���� ������
	int m_aniAF = 0;												// ���� �������� �ٲ�� ���� ������
	const int m_ANISpeed = 15;										// �������� �ٲ�� �ϴ� �� (const��, 15)

	// <���� � ��Ȳ���� Ȯ����>
	bool isRight = true;											// ������ �������� Ȯ��
	bool isAttack = false;											// �����ϴ��� Ȯ��
	bool isJump = false;											// �����ϴ��� Ȯ��

	// <�⺻ ���� ���� ����>
	const int m_IDLEW = 38;											// �⺻ ���� ������ ����(const��, 38)
	const int m_IDLEH = 58;											// �⺻ ���� ������ ����(const��, 58)

	// <�̵� ���� ����>
	int m_WSpeed = 0;												// �����̴� �ӵ�
	int m_Currxpos = 0;												// ���� x��ǥ
	const int m_WALKW = 38;											// �̵� ������ ����(const��, 38)
	const int m_WALKH = 58;											// �̵� ������ ����(const��, 58)
	const int m_WALK_FullCnt = 8;									// �ȱ� �� ������ ��(const��, 8)

	// <���� ���� ����>
	int m_CurrAttF = 0;												// ���� ���� ������
	const int m_ATTW = 75;											// ���� ������ ����(const��, 75)
	const int m_ATTH = 75;											// ���� ������ ����(const��, 75)
	const int m_ATT_FullCnt = 6;									// ������ �� �����Ӽ�, 8 (const��, 6)

	// <���� ���� ����>
	const int mBG_YPOS = 330;										// ������ y��ǥ (const��, 330)
	const int m_JUMP_MaxH = mBG_YPOS - 60;							// �ִ� ���� ���� (const��, ������ ���� : 310 - �ִ� ���� ���� : 60 )
	int m_yPos = mBG_YPOS;											// �÷��̾��� y��ǥ, �ʱⰪ = ������ y��ǥ
	int m_JSpeed = 2;												// ���� �ӵ�

	int m_AxSk_xPos = 1;
	int m_AxSk_State = 1;
	int m_AxSkCurrF = 1;
	int m_AxSkHp = 1;
};