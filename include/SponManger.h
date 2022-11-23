#pragma once

#include"BackGround.h"
#include "Monster.h"

#define kSkull_SponXpos 1500							// 칼병사가 등장하는 x좌표

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
	void sponByGameBg();								// 배경 위치에 따라 객체를 만듬
	
private:
	SponManger() = default;
	static SponManger* s_pInstance;

	BackGround* GmBg;									// 배경 객체
	Monster* monster;									// sdl 객체, 내보내줌

	int GmBg_XPos;										// 배경의 x좌표

}typedef TheSponManger;