#include "Player.h"
#include "Entity.h"
#include "Alive.h"
#include "AMovable.h"
#include "IAttacker.h"
#include "iostream"

Player::Player(Vector2 pos, float maxHP, Vector2 vecteur, float speed) : Entity(pos), Alive(maxHP), AMovable(vecteur, speed)
{
	std::cout << "Player just created at x = " << this->GetX() << " and y = " << this->GetY() << " with " << this->GetMaxHP() << " life with direction x = " << this->GetVecteur().GetX() << " and y = " << this->GetVecteur().GetY() << std::endl;

}

void Player::TakeDamage(float damage)
{
	Alive::TakeDamage(damage);

	if (this->GetCurrrentHP() <= 0)
	{
		std::cout << "Player just die" << std::endl;
	}
}

void Player::Move()
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

	std::cout << "Player move to x = " << this->GetX() << " and y = " << this->GetY() << std::endl;
}

void Player::Attack(Alive* target)
{
	target->TakeDamage(10);
	std::cout << "Player just attacked" << std::endl;
}
