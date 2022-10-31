#pragma once
#include <SDL2/SDL.h>

class GameObject {

public:
	// ��������Ʈ�� �����͸� �������� �Լ�
	void load(int x, int y, int width, int height, const char* textureID);

	void draw(SDL_Renderer* pRenderer);				// �׸��� �׷��ִ� �Լ�
	void update();									// ��������� ��������, ������ �̵�

	void clean();									// �׸� �����͸� �����ϴ� �Լ�

protected:
	const char* m_textureID;

	int m_x;
	int m_y;
	int m_width;
	int m_height;

	int m_currentFrame;
	int m_currentRow;
};