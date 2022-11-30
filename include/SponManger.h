#pragma once

#include"BackGround.h"
#include "ASkull.h"
#include "KSkull.h"
#include"SDLGameObject.h"

#define kSkull_SponXpos 1500							// Į���簡 �����ϴ� x��ǥ

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
	SDLGameObject* sponByGameBg();								// ��� ��ġ�� ���� ��ü�� ����
	
private:
	SponManger() = default;
	static SponManger* s_pInstance;

	BackGround* GmBg;									// ��� ��ü
	ASkull* m_ASkull;									// ���� ���� ��ü
	KSkull* m_KSkull;									// Į ���� ��ü

	SDLGameObject* SponObj;								// �� ������ �ϳ��� ������

	int GmBg_XPos;										// ����� x��ǥ

}typedef TheSponManger;