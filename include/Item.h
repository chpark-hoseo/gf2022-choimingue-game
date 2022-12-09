#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Item : public SDLGameObject
{
public:
	enum ItemType
	{
		TBox = 0
	};

	Item(LoaderParams* pParams);
	void draw();
	void update();

	void setBgSpeed(int MoveSpeed);				// ����� �ӵ��� �������� �Լ�

	int getXpos();								// �ڽ��� x��ǥ�� ��ȯ��
	int getYpos();								// �ڽ��� y��ǥ�� ��ȯ��
	void setGroundYPos(int GroundYpos);			// ��水ü���� ���� ���̸� ������

	int getFrameH();							// �ڽ��� ���̸� ��ȯ

	int getItemType();
	void setItemType(int ItemType);

private:
	int MoveSpeed = 0;							// ����� �ӵ��� ���� ��ġ�� ����Ǵ°�
	int m_CurrXpos = 0;

	const int m_TBox_FrameH = 70;
	const int m_TBox_FrameW = 70;

	int m_GroundYpos;							// ���� y��ǥ

	int m_CurrItem_Type;						// ���� �������� ������ �����´�.
};

