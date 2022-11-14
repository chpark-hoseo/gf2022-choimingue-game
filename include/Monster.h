#pragma
#include "GameCharacter.h"
#include "SDLGameObject.h"

class Monster : public GameCharacter
{
public:
	Monster(LoaderParams* pParams);

	void draw();
	void update();

private:

	// ������ �ִϸ��̼� ���� ����
	const int m_AllFullCnt = 7;										// ��� �ൿ�� �������� 7
};