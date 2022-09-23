// SDL 
//
// written by changhoonpark@gmail.com

// 과제 1. << if -> while로 바꾸고 이유를 주석으로 추가 >>

/* if문을 사용한 경우, if문 밖으로 나갔을때, 사용자가 입력을 하게 된다면, 키가 씹히기 때문에
 while문을 사용하는 것이 바람직하다.*/

 // 과제 2. << 헤더 파일 중복과 순환참조의 차이점과 해결 방법 >>

 /* 헤더 파일 중복, 순환 참조시켜 컴파일시 속도가 느려지는 등의 문제가 발생하게 된다.
  이러한 이유로 인해 전방 선언이나, 인터페이스의 활용, 전처리기등을 활용하여 이를 막는다.
  특히, 전방 선언같은 경우에는 클래스의 존재 여부만 알기에 포인터로만 생성이 가능하다.*/

#include "main.h"
#include "GameClass.h"

int main(int argc, char* argv[])
{
	GameClass* game = new GameClass;
	bool g_brunning;

	int s_width = 640;				// 실행할 프로그램의 길이
	int s_heigh = 480;				//					 높이

	g_brunning = game->init("GameClass", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

	// 게임의 창이 띄워졌는지 확인5
	if (!g_brunning)
		return 0;

	while (game->running())
	{
		game->handleEvent();
		game->update();
		game->renderer();
	}
}