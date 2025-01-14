#pragma once
#include "Entity.h"
#include "Alive.h"
#include "AMovable.h"
#include "IAttacker.h"

class Player : public Entity, public Alive, public AMovable, public IAttacker
{
public:
	Player(Vector2 pos, float maxHP, Vector2 vecteur, float speed);

	void TakeDamage(float damage) override;
	void Move() override;
	void Attack(Alive* target) override;
};

