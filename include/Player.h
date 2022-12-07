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
	int getGroundYPos();
	void Add_GroundYpos(int GroundYpos);							// ����� ���� ��ǥ�� ������

	int getWalkW();													// �ȴ� �������� ���̸� ��ȯ

private:
	int const MoveSpeed = 4;										// �ȱ� �ӵ� (��ġ��)
	int m_CurrHitTime = 0;											// ���� �ǰ� �Ǵ� �ð�
	int m_CurrAttF = 0;												// ���� ���� ������

	// <���� � ��Ȳ���� Ȯ����>
	bool isRight = true;											// ������ �������� Ȯ��
	bool isAttack = false;											// �����ϴ��� Ȯ��
	bool isJump = false;											// �����ϴ��� Ȯ��

	int m_GroundYpos = 330;											// ������ y��ǥ (�ʱⰪ 330)
	int m_AddYPos = 0;

	// <���� ���� ����>
	const float m_JumpSpeed = 3.5;
};