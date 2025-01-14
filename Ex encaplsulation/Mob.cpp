#include "Mob.h"
#include "Entity.h"
#include "Alive.h"
#include "AMovable.h"
#include "iostream"

Mob::Mob(Vector2 pos, float maxHP, Vector2 vecteur, float speed) : Entity(pos), Alive(maxHP), AMovable(vecteur, speed)
{
	std::cout << "Mob just created at x = " << this->GetX() << " and y = " << this->GetY() << " with " << this->GetMaxHP() << " life with direction x = " << this->GetVecteur().GetX() << " and y = " << this->GetVecteur().GetY() << std::endl;
}

void Mob::TakeDamage(float damage)
{
	Alive::TakeDamage(damage);

	if (this->GetCurrrentHP() <= 0)
	{
		std::cout << "Mob just die" << std::endl;
	}
}

void Mob::Move()
{
	float distance = sqrt((this->GetVecteur().GetX() * this->GetVecteur().GetX()) + (this->GetVecteur().GetY() * this->GetVecteur().GetY()));

	if (distance > this->GetSpeed())
	{
		float facteur = this->GetSpeed() / distance;
		this->SetNewPosition(this->GetX() + this->GetVecteur().GetX() * facteur, this->GetY() + this->GetVecteur().GetY() * facteur);
	}
	else
	{
		this->SetNewPosition(this->GetX() + this->GetVecteur().GetX(), this->GetY() + this->GetVecteur().GetY());
	}

	std::cout << "Mob move to x = " << this->GetX() << " and y = " << this->GetY() << std::endl;
}
