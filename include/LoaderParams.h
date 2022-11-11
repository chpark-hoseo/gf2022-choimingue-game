#pragma once
#include "String"

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, std::string textureID)
		: m_x(x),
		m_y(y),
		m_width(width),
		m_height(height),
		m_textureID(textureID){}

	int getX() { return m_x; }
	int getY() { return m_y; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	std::string getTextID() { return m_textureID; }

private:
	int m_x, m_y;
	int m_width, m_height;
	std::string m_textureID;
};

