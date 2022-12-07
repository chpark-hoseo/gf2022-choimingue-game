#pragma once

#include"BackGround.h"
#include "ASkull.h"
#include "KSkull.h"
#include "Item.h"
#include"SDLGameObject.h"

class SponManger
{
public :
	static SponManger* Instance()
	{
		if (s_pInstance == NULL)
			s_pInstance = new SponManger();

		return s_pInstance;
	}

	void setBgData(BackGround* GmBg_Data);				// ��� ��ü�� ������
	SDLGameObject* addGameobj();						// ��� ��ġ�� ���� ������� ��ü�� Game���� �߰�����
	SDLGameObject* sponByGameBg();						// ��� ��ġ�� ���� ��ü�� ����
	
private:
	enum MonsterSponXpos
	{
		aSkull_SponXpos = 8, kSkull_SponXpos = 1500, TBox_SponXpos = 3900
	};

	SponManger() = default;
	static SponManger* s_pInstance;

	BackGround* GmBg;									// ��� ��ü
	ASkull* m_ASkull;									// ���� ���� ��ü
	KSkull* m_KSkull;									// Į ���� ��ü
	Item* m_TBox;										// ������ ��ü

	SDLGameObject* SponObj;								// �� ������ �ϳ��� ������

	int GmBg_XPos;										// ����� x��ǥ

	const int Askull_IdleW = 48;
	const int Askull_IdleH = 49;

	const int Kskull_IdleW = 51;
	const int Kskull_IdleH = 49;

	const int TBox_FrameH = 70;
	const int TBox_FrameW = 70;

}typedef TheSponManger;