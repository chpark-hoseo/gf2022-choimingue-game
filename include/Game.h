#pragma once
#include "main.h"
#include "TextManger.h"
#include "Vector"

#include "GameObject.h"

class Game
{
private:
	Game(){}
	static Game* s_pInstance;				// 정적 멤버 변수

public:
	static Game* getInstace()
	{
		if (s_pInstance == NULL)
			s_pInstance = new Game();

		return s_pInstance;
	}

	// 윈도우 크기
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	// 윈도우 생성
	bool init(const char* Stitle, int xpos, int ypos, int Swidth, int Sheight, int flags);

	// 게임 내용 수정
	void update();

	// 화면 띄우기
	void renderer();

	// 정상작동중인지 확인
	bool running();

	void quit() { m_bRunning = false; }

	// 종료 설정
	void handleEvent();

	// 화면 지우기
	void clean();

	SDL_Renderer* getRenderer();

private:
	SDL_Window* m_pWindow;					// 윈도창 생성 변수
	SDL_Renderer* m_pRenderer;				// 그림창 생성 변수 
	bool m_bRunning;						// 게임이 정상 작동하는지 변수

	const char* adr_Dog = "assets/animate-alpha.png";				// 캐릭터의 그림 주소
	const char* adr_monster = "assets/Dogge.png";					// 몬스터의 그림 주소

	const int m_MonstW = 27;					// 몬스터의 가로 스프라이트 길이, 27
	const int m_MonstH = 31;					// 몬스터의 세로 스프라이트 길이, 31
	int m_fastSpeed = 3;						// 빠른 속도
	int m_slowSpeed = 1;						//				느린속도

	const int m_DogW = 128;						// 강아지의 가로 스프라이트 길이, 128
	const int m_DogH = 98;						// 강아지의 세로 스프라이트 길이, 98

	int m_DogCurrFrame = 0;						// 강아지의 현재 프레임, 0

	std::vector<GameObject*> m_gameObjects;		// 다형성으로 자식 객체들을 넣을 변수

}typedef TheGame;