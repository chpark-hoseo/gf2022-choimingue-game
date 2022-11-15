#pragma
#include "GameCharacter.h"
#include "Player.h"

class Monster : public GameCharacter
{
public:
	Monster(LoaderParams* pParams);

	void draw();
	void update();

	void setPlayerXPos(int xPos);
	void stateMachine();

	void setHp(int damage);

private:

	// ������ �ִϸ��̼� ���� ����
	const int m_AllFullCnt = 7;										// ��� �ൿ�� �������� 7
	
	// ������ ���� ��ȯ�� ���õ� ����
	int m_PlayerXPos;												// �÷��̾��� x ��ǥ�� �޾ƿ�
	
	const int m_ChaseDist = 150;									// �÷��̾ �Ѵ� ��Ÿ�
	const int m_AttDist = 40;										// �÷��̾ �����ϴ� ��Ÿ�
	
};