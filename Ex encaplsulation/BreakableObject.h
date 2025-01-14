#pragma once
#include "Entity.h"
#include "Alive.h"

class BreakableObject : public Entity, public Alive
{
public:
	BreakableObject(Vector2 pos, float maxHP);

	void TakeDamage(float damage) override;
};

