#include "BreakableObject.h"
#include "iostream"

BreakableObject::BreakableObject(Vector2 pos, float maxHP) : Entity(pos), Alive(maxHP)
{
	std::cout << "Breakable Object just created at x = " << this->GetX() << " and y = " << this->GetY() << " with " << this->GetMaxHP() << " life" << std::endl;
}

void BreakableObject::TakeDamage(float damage)
{
	Alive::TakeDamage(damage);

	if (this->GetCurrrentHP() <= 0)
		std::cout << "Breakable Object just broke" << std::endl;
}
