#pragma once
#include "GameObject.h"

class GameCharacter : public GameObject
{
public:
	virtual void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();

	void setData(int FrameW, int FrameH);

protected:
	enum State
	{
		IDLE, WALK, ATTACK, HIT, DIE
	};

	// <���Ͱ� ���� � ���������� ���� �޶���>
	int m_State;												// ���� ����
	int m_CurrFw;												// ���� ���¿� ���� �������� �ʺ�
	int m_CurrFh;												// ���� ���¿� ���� �������� ����
	int m_FrameIntv;											// ������ ������ ����
	int m_CurrF;												// ���� ���° ����������

	// <�⺻ ���� ���� ����>
	const int m_IDLEW;											// �⺻ ���� ������ ����
	const int m_IDLEH;											// �⺻ ���� ������ ����

	// <�̵� ���� ����>
	int m_Currxpos;												// ���� x��ǥ
	const int m_WALKW;											// �̵� ������ ����
	const int m_WALKH;											// �̵� ������ ����

	// <���� ���� ����>
	const int m_ATTW;											// ���� ������ ����
	const int m_ATTH;											// ���� ������ ����

	// <�ǰ� ���� ����>
	const int m_HITW;											// ���� ������ ����
	const int m_HITH;											// ���� ������ ����

	// <��� ���� ����>
	const int m_DIEW;											// ���� ������ ����
	const int m_DIEH;											// ���� ������ ����

	// <����>
	int m_hp;													// ü��
	int m_damage;												// ������ 
	int m_WSpeed;												// �����̴� �ӵ�
};