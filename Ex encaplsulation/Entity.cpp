#include "Entity.h"

Entity::Entity(Vector2 pos) : mPos(pos)
{
}

float Entity::GetX()
{
	return mPos.GetX();
}

float Entity::GetY()
{
	return mPos.GetY();
}

void Entity::SetNewPosition(float x, float y)
{
	mPos.SetNewPosition(x, y);
}