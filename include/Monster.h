#pragma once
#include "GameCharacter.h"
#include "BackGround.h"

class Monster : public GameCharacter
{
public:
	Monster(LoaderParams* pParams);

	void draw();
	void update();

	// <�÷��̾��� ��ġ�� ���� ���°� ��ȭ��>
	void setPlayerXPos(int xPos);									// �÷��̾��� x��ǥ�� �����´�.
	void stateMachine();											// �÷��̾��� ��ġ�� ���� ���¸� �˾Ƽ� �����Ѵ�.

	void setBgSpeed(int Bg_Speed);

private:

	// ������ �ִϸ��̼� ���� ����
	const int m_AllFullCnt = 7;										// ��� �ൿ�� �������� 7
	
	// ������ ���� ��ȯ�� ���õ� ����
	const int deathMaxCnt = 150;
	int deathCount = 0;
	int m_PlayerXPos = 0;											// �÷��̾��� x ��ǥ�� �޾ƿ�
	
	const int m_ChaseDist = 150;									// �÷��̾ �Ѵ� ��Ÿ�
	const int m_AttDist = 40;										// �÷��̾ �����ϴ� ��Ÿ�

	int Bg_Speed;

protected:
	const char* monster_Name = NULL;
};