#pragma once

#include"BackGround.h"
#include "ASkull.h"
#include "KSkull.h"
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

	void setBgData(BackGround* GmBg_Data);				// 배경 객체를 가져옴
	SDLGameObject* addGameobj();						// 배경 위치에 따라 만들어진 객체를 Game에서 추가해줌
	SDLGameObject* sponByGameBg();						// 배경 위치에 따라 객체를 만듬
	
private:
	enum MonsterSponXpos
	{
		aSkull_SponXpos = 3, kSkull_SponXpos = 1500
	};

	SponManger() = default;
	static SponManger* s_pInstance;

	BackGround* GmBg;									// 배경 객체
	ASkull* m_ASkull;									// 도끼 몬스터 객체
	KSkull* m_KSkull;									// 칼 몬스터 객체

	SDLGameObject* SponObj;								// 이 모든것을 하나로 묶어줌

	int GmBg_XPos;										// 배경의 x좌표
	
	const int Askull_defaultXpos = 400;
	const int Askull_IdleW = 48;
	const int Askull_IdleH = 49;

	const int Kskull_IdleW = 51;
	const int Kskull_IdleH = 49;

}typedef TheSponManger;