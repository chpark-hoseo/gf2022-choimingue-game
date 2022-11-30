#pragma once
#include "GameCharacter.h"
#include "BackGround.h"

class Monster : public GameCharacter
{
public:
	Monster(LoaderParams* pParams);

	void draw();
	void update();

	// <플레이어의 위치에 따라 상태가 변화함>
	void setPlayerXPos(int xPos);									// 플레이어의 x좌표를 가져온다.
	void stateMachine();											// 플레이어의 위치에 따른 상태를 알아서 결정한다.

	void setBgSpeed(int Bg_Speed);

private:

	// 몬스터의 애니메이션 관련 변수
	const int m_AllFullCnt = 7;										// 모든 행동의 프레임은 7
	
	// 몬스터의 상태 변환과 관련된 변수
	const int deathMaxCnt = 150;
	int deathCount = 0;
	int m_PlayerXPos = 0;											// 플레이어의 x 좌표를 받아옴
	
	const int m_ChaseDist = 150;									// 플레이어를 쫓는 사거리
	const int m_AttDist = 40;										// 플레이어를 공격하는 사거리

	int Bg_Speed;

protected:
	const char* monster_Name = NULL;
};