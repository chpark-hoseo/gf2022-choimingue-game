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
	int getSpeed();

	int getYPos();													// �÷��̾��� y ��ǥ�� ������

	void Add_GroundYpos(int GroundYpos);							// ����� ���� ��ǥ�� ������

	void jump();													// ���� �Լ�

protected:

	const int m_HitTime = 10;										// �ǰ� ���� ���� �ð�
	int m_CurrHitTime = 0;											// ���� �ǰ� �Ǵ� �ð�
	int m_CurrAttF = 0;												// ���� ���� ������

	// <���� � ��Ȳ���� Ȯ����>
	bool isRight = true;											// ������ �������� Ȯ��
	bool isAttack = false;											// �����ϴ��� Ȯ��
	bool isJump = false;											// �����ϴ��� Ȯ��

	int m_GroundYpos = 330;											// ������ y��ǥ (�ʱⰪ 330)
	int m_AddYPos = 0;

	// <���� ���� ����>
	int m_JUMP_MaxH = m_GroundYpos - 60;							// �ִ� ���� ���� (const��, ������ ���� : 310 - �ִ� ���� ���� : 60 )
	int m_JSpeed = 2;												// ���� �ӵ�
};