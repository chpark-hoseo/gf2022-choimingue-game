#pragma once

#include "GameCharacter.h"

class Player : public GameCharacter
{
public :
	Player(LoaderParams* pParams);

	void update();
	void handleInput();
	void draw();

	void setSpeed(int P_WSpeed);									// �÷��̾��� ���ǵ尪�� �����Ŵ (Bg��ü�ּ� ���)
	
	// <��� �̵��� ���>
	bool getIsRight();												// �÷��̾��� ������ Ȯ��
	bool getIsMove();												// �÷��̾ �����̴����� Ȯ��

	void jump();													// ���� �Լ�

protected:

	const int m_HitTime = 10;										// �ǰ� ���� ���� �ð�
	int m_CurrHitTime = 0;											// ���� �ǰ� �Ǵ� �ð�
	int m_CurrAttF = 0;												// ���� ���� ������

	// <���� � ��Ȳ���� Ȯ����>
	bool isRight = true;											// ������ �������� Ȯ��
	bool isAttack = false;											// �����ϴ��� Ȯ��
	bool isJump = false;											// �����ϴ��� Ȯ��

	// <���� ���� ����>
	const int m_JUMP_MaxH = mBG_YPOS - 60;							// �ִ� ���� ���� (const��, ������ ���� : 310 - �ִ� ���� ���� : 60 )
	int m_yPos = mBG_YPOS;											// �÷��̾��� y��ǥ, �ʱⰪ = ������ y��ǥ
	int m_JSpeed = 2;												// ���� �ӵ�
};