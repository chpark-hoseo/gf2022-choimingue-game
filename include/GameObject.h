#pragma once
#include <SDL2/SDL.h>

class GameObject {

public:
	// 스프라이트의 데이터를 가져오는 함수
	void load(int x, int y, int width, int height, const char* textureID);

	void draw(SDL_Renderer* pRenderer);				// 그림을 그려주는 함수
	void update();									// 변경사항을 적용해줌, 오른쪽 이동

	void clean();									// 그림 데이터를 삭제하는 함수

protected:
	const char* m_textureID;

	int m_x;
	int m_y;
	int m_width;
	int m_height;

	int m_currentFrame;
	int m_currentRow;
};