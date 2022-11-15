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

	// 몬스터의 애니메이션 관련 변수
	const int m_AllFullCnt = 7;										// 모든 행동의 프레임은 7
	
	// 몬스터의 상태 변환과 관련된 변수
	int m_PlayerXPos;												// 플레이어의 x 좌표를 받아옴
	
	const int m_ChaseDist = 150;									// 플레이어를 쫓는 사거리
	const int m_AttDist = 40;										// 플레이어를 공격하는 사거리
	
};