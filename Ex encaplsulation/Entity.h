#pragma once
#include "Vector2.h"

class Entity
{
	Vector2 mPos;

public:
	Entity(Vector2 pos);

	virtual float GetX();
	virtual float GetY();

	virtual void SetNewPosition(float x, float y);
};