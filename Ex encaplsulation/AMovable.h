#pragma once
#include "Vector2.h"

class AMovable
{
	Vector2 mVecteur;
	float mSpeed;

public:
	AMovable(Vector2 vecteur, float speed);

	virtual void SetDirection(Vector2 vecteur);
	virtual void SetSpeed(float speed);

	Vector2 GetVecteur();
	float GetSpeed();

	virtual void Move() = 0;
};

