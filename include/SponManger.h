#pragma once

#include"BackGround.h"
#include "Monster.h"

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
	void sponByGameBg();								// ��� ��ġ�� ���� ��ü�� ����
	
private:
	SponManger() = default;
	static SponManger* s_pInstance;

	BackGround* GmBg;									// ��� ��ü
	Monster* monster;									// sdl ��ü, ��������

	int GmBg_XPos;										// ����� x��ǥ

}typedef TheSponManger;