#pragma once
#include "Entity.h"
#include "Alive.h"
#include "AMovable.h"

class Mob : public Entity, public Alive, public AMovable
{
public:
	Mob(Vector2 pos, float maxHP, Vector2 vecteur, float speed);

	void TakeDamage(float damage) override;
	void Move() override;


};

