#pragma once

class Vector2
{
	float mX;
	float mY;

public:
	Vector2(float x, float y);

	float GetX();
	float GetY();

	void SetNewPosition(float x, float y);
};