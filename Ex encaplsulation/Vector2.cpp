#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
	mX = x;
	mY = y;
}

float Vector2::GetX()
{
	return mX;
}

float Vector2::GetY()
{
	return mY;
}

void Vector2::SetNewPosition(float x, float y)
{
	mX = x;
	mY = y;
}