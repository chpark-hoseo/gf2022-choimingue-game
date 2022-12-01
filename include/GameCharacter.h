#pragma once
#include"SDLGameObject.h"
#include "LoaderParams.h"

class GameCharacter : public SDLGameObject
{
public:
	GameCharacter(LoaderParams* pParams);

	virtual void draw() {}
	virtual void update(){}
	virtual void clean();

	void setData(int FrameW, int FrameH);						// ���� ���¿� ���� ���� �������ش�.
	void setHp(int damage);										// ü���� ���� �������ش�.
	void setState(int State);									// ���� ���¸� ��ȯ���� �ݴϴ�.

	int getState();												// ���� ���¸� �����´�.
	int getHp();												// ���� ü���� �����´�.

	int getXPos();												// x��ǥ�� ������
	int getATTWidth();											// ���� �������� ���̸� �����´�.
	int getCurrATTF();											// ���° ���� ���������� Ȯ��
	int getDamage();											// �������� ������ ������


	// <�⺻ ���� ���� ����>
	int m_IDLEW;												// �⺻ ���� ������ ����
	int m_IDLEH;												// �⺻ ���� ������ ����

	enum State
	{
		IDLE, WALK, ATTACK, HIT, DIE
	};

protected:

	// <���Ͱ� ���� � ���������� ���� �޶���>
	int m_State;												// ���� ����
	int m_CurrFw;												// ���� ���¿� ���� �������� �ʺ�
	int m_CurrFh;												// ���� ���¿� ���� �������� ����
	int m_FrameIntv;											// ������ ������ ����
	int m_CurrF;												// ���� ���° ����������

	// �ִϸ��̼� ���� ����
	int m_aniWF = 0;											// �ȱ���� �������� �ٲ�� ���� ������
	int m_aniAF = 0;											// ���ݰ��� �������� �ٲ�� ���� ������
	int m_aniHF = 0;											// �ǰݰ��� �������� �ٲ�� ���� ������
	int m_aniDF = 0;											// �������� �������� �ٲ�� ���� ������
	const int m_ANISpeed = 15;									// �������� �ٲ�� �ϴ� ��

	// <�̵� ���� ����>
	const int mBG_YPOS = 330;									// ������ y��ǥ (const��, 330)
	int m_WALK_FullCnt;											// �̵��� �� ������ ��
	int m_WALKW;												// �̵� ������ ����
	int m_WALKH;												// �̵� ������ ����

	// <���� ���� ����>
	int m_ATT_FullCnt;											// ���ݿ� �� ������ ��
	int m_ATTW;													// ���� ������ ����
	int m_ATTH;													// ���� ������ ����

	// <�ǰ� ���� ����>
	int m_HIT_FullCnt;											// �ǰݿ� �� ������ ��
	int m_HITW;													// �ǰ� ������ ����
	int m_HITH;													// �ǰ� ������ ����

	// <��� ���� ����>
	int m_DIE_FullCnt;											// ������ �� ������ ��
	int m_DIEW;													// ���� ������ ����
	int m_DIEH;													// ���� ������ ����

	// <���� ���� ����>
	int m_TOMBW;												// ���� ������ ����
	int m_TOMBH;												// ���� ������ ����

	// <����>
	int m_hp;													// ü��
	int m_damage;												// ������ 
	int m_WSpeed;												// �����̴� �ӵ�
};