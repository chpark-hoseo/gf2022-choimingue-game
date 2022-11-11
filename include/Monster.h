#pragma
#include "GameCharacter.h"

class Monster : public GameCharacter
{
public:
	void draw(SDL_Renderer* pRenderer);
	void update();

private:
	// <���Ͱ� ���� � ���������� ���� �޶���>
	int m_State;													// ���� ����
	int m_CurrFw = 48;												// ���� ���¿� ���� �������� �ʺ� (�⺻ �� Idle)
	int m_CurrFh = 49;												// ���� ���¿� ���� �������� ���� (�⺻ �� Idle)
	int m_FrameIntv = 50;											// ������ ������ ����
	int m_CurrF = 0;												// ���� ���° ����������

	// ������ �ִϸ��̼� ���� ����
	int m_aniWF = 0;												// �ȱ� �������� �ٲ�� ���� ������
	int m_aniAF = 0;												// ���� �������� �ٲ�� ���� ������
	const int m_ANISpeed = 15;										// �������� �ٲ�� �ϴ� �� (const��, 15)
	const int m_AllFullCnt = 7;										// ��� �ൿ�� �������� 7

	// <�⺻ ���� ���� ����>
	const int m_IDLEW = 48;											// �⺻ ���� ������ ����(const��, 48)
	const int m_IDLEH = 49;											// �⺻ ���� ������ ����(const��, 49)

	// <�̵� ���� ����>
	int m_Currxpos = 0;												// ���� x��ǥ
	const int m_WALKW = 46;											// �̵� ������ ����(const��, 46)
	const int m_WALKH = 46;											// �̵� ������ ����(const��, 46)

	// <���� ���� ����>
	const int m_ATTW = 42;											// ���� ������ ����(const��, 42)
	const int m_ATTH = 50;											// ���� ������ ����(const��, 50)

	// <�ǰ� ���� ����>
	const int m_HITW = 47;											// ���� ������ ����(const��, 47)
	const int m_HITH = 46;											// ���� ������ ����(const��, 46)

	// <��� ���� ����>
	const int m_DIEW = 80;											// ���� ������ ����(const��, 47)
	const int m_DIEH = 55;											// ���� ������ ����(const��, 46)

	// <������ ����>
	int m_hp = 100;													// ������ ü�� 100
	int m_damage = 20;												// ������ ������ 20
	int m_WSpeed = 0;												// �����̴� �ӵ�
};