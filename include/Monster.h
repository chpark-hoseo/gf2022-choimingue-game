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

	// 몬스터의 애니메이션 관련 변수
	const int m_AllFullCnt = 7;										// 모든 행동의 프레임은 7
};