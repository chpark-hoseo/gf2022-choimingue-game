#include "Vector2D.h"

Vector2D Vector2D::operator+(const Vector2D& v2)
{
	return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

Vector2D Vector2D::operator-(const Vector2D& v2)
{
	return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

Vector2D Vector2D::operator*(float scalar)
{
	return Vector2D(m_x * scalar, m_y * scalar);
}

Vector2D Vector2D::operator/(float scalar)
{
	return Vector2D(m_x / scalar, m_y / scalar);
}

Vector2D& Vector2D::operator*=(float scalar)
{
	m_x *= scalar;
	m_y *= scalar;

	return *this;
}

Vector2D& Vector2D::operator/=(float scalar)
{
	m_x /= scalar;
	m_y /= scalar;

	return *this;
}

void Vector2D::normalize()
{
	float Vector_L = length();

	// 0으론 나눌수 없음
	if (Vector_L > 0) {
		(*this) *= 1 / Vector_L;
	}
}

Vector2D& operator+=(Vector2D& v1, Vector2D& v2)
{
	v1.m_x += v2.m_x;
	v1.m_y += v2.m_y;

	return v1;
}

Vector2D& operator-=(Vector2D& v1, Vector2D& v2)
{
	v1.m_x -= v2.m_x;
	v1.m_y -= v2.m_y;

	return v1;
}