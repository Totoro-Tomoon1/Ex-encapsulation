#include "AMovable.h"

AMovable::AMovable(Vector2 vecteur, float speed) : mVecteur(vecteur)
{
	mSpeed = speed;
}

void AMovable::SetDirection(Vector2 vecteur)
{
	mVecteur = vecteur;
}

void AMovable::SetSpeed(float speed)
{
	mSpeed = speed;
}

Vector2 AMovable::GetVecteur()
{
	return mVecteur;
}

float AMovable::GetSpeed()
{
	return mSpeed;
}
