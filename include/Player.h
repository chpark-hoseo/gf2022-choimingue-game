#include "GameObject.h"
#include "BackGround.h"

#pragma once
class Player : public GameObject
{
public :
	Player(BackGround* GameBg) {
		this->GameBg = GameBg;
	}

	void update();
	void handleInput();

	void setData(int FrameW, int FrameH);
	void setBgData(BackGround* GameBg);

	void move();
	void attack();
	void jump();

	void draw(SDL_Renderer* m_pRenderer);

private:
	enum State
	{
		IDLE, WALK, ATTACK, HIT, DEAD
	};

	BackGround* GameBg;

	// <�÷��̾ ���� � ���������� ���� �޶���>
	int mP_State = IDLE;											// �÷��̾��� ���� ����
	int mP_CurrFw = 38;												// �÷��̾ ���� ���¿� ���� �������� �ʺ�
	int mP_CurrFh = 58;												// �÷��̾ ���� ���¿� ���� �������� ����
	int mP_FrameIntv = 75;											// ������ ������ ����
	int mP_CurrF = 0;												// �÷��̾�� ���� ���° ����������

	// �÷��̾��� �ִϸ��̼� ���� ����
	int mP_aniWF = 0;												// �ȱ� �������� �ٲ�� ���� ������
	int mP_aniAF = 0;												// ���� �������� �ٲ�� ���� ������
	const int mCP_anifSpeed = 15;									// �������� �ٲ�� �ϴ� ��

	// <���� � ��Ȳ���� Ȯ����>
	bool isRight = true;											// ������ �������� Ȯ��
	bool isAttack = false;											// �÷��̾ �����ϴ��� Ȯ��
	bool isJump = false;											// �÷��̾ �����ϴ��� Ȯ��

	// <�̵� ���� ����>
	int mP_WSpeed = 0;												// �÷��̾� �ӵ�
	int mP_Currxpos = 0;											// ���� �÷��̾��� x��ǥ
	const int mCP_WALKW = 38;										// �÷��̾��� �̵� ������ ����, 38
	const int mCP_WALKH = 58;										//						  ����, 58
	const int mCP_WALK_FULLCNT = 8;									// �ȱ⿡ �� ������ ��

	// <��� �̵� ���� ����>
	int mBg_End = 5000 - SCREEN_WIDTH;								// ����� �̵��� ������ ��ǥ
	int mBg_Start = SCREEN_WIDTH / 3.0;								// ����� �̵��� ���۵Ǵ� ��ǥ
	const int mP_MAX_XPOS = SCREEN_WIDTH - mCP_WALKW;				// �÷��̾ ������ �� �ִ� �ִ� ��ǥ

	// <���� ���� ����>
	int mP_CurrAttF = 0;											// �÷��̾��� ���� ���� ������
	const int mCP_AttackW = 75;										// �÷��̾��� ���� ������ ����, 75
	const int mCP_AttackH = 75;										//						  ����, 75
	const int mCP_ATT_FULLCNT = 6;								// �ȱ⿡ �� ������ ��

	// <���� ���� ����>
	float mP_JSpeed = 2;											// �÷��̾��� ���� �ӵ�
	int mP_yPos = 310;												// �÷��̾��� y��ǥ, �ʱⰪ = ������ y��ǥ
	const int mCB_GYPOS = 310;										// ������ y��ǥ
	const int mCP_JUMPMAXH = mCB_GYPOS - 60;						// �ִ� ���� ���� (������ ���� : 310 - �ִ� ���� ���� : 45 )

	int m_AxSk_xPos = 1;
	int m_AxSk_State = 1;
	int m_AxSkCurrF = 1;
	int m_AxSkHp = 1;
};