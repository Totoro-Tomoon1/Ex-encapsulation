#include "World.h"
#include "StaticObject.h"
#include "BreakableObject.h"
#include "Mob.h"
#include "Player.h"
#include <cmath>

void World::Init()
{
	StaticObject* newStaticObject = new StaticObject(Vector2(5, 2));
	BreakableObject* newBreakableObject = new BreakableObject(Vector2(-14, 2), 1);
	Mob* newMob = new Mob(Vector2(8, 6), 20, Vector2(15, 7), 2);
	Player* newPlayer = new Player(Vector2(4, 3), 10, Vector2(-10, -2), 0.5);

	mEntity.push_back(newStaticObject);
	mEntity.push_back(newBreakableObject);
	mEntity.push_back(newMob);
	mEntity.push_back(newPlayer);
}

void World::Step()
{
	for (Entity* entity : mEntity)
	{
		if (Mob* temp = dynamic_cast<Mob*>(entity))
		{
			for (Entity* entity : mEntity)
			{
				if (BreakableObject* temp2 = dynamic_cast<BreakableObject*>(entity))
				{
					temp->SetDirection(Vector2(temp2->GetX() - temp->GetX(), temp2->GetY() - temp->GetY()));
					std::cout << temp2->GetX() - temp->GetX() << "    " << temp2->GetY() - temp->GetY() << std::endl;
					temp->Move();
				}
			}

		}

		if (Player* temp = dynamic_cast<Player*>(entity))
		{
			bool mobIsDead = false;
			for (Entity* entity : mEntity)
			{
				if (Mob* temp2 = dynamic_cast<Mob*>(entity))
				{
					if (temp2->GetCurrrentHP() > 0)
					{
						temp->SetDirection(Vector2(temp2->GetX() - temp->GetX(), temp2->GetY() - temp->GetY()));
						//std::cout << temp2->GetX() - temp->GetX() << "    " << temp2->GetY() - temp->GetY() << std::endl;
						temp->Move();

						float distance = sqrt((temp->GetX() - temp2->GetX()) * (temp->GetX() - temp2->GetX()) + (temp->GetY() - temp2->GetY()) * (temp->GetY() - temp2->GetY()));

						if (distance <= 1)
						{
							temp->Attack(temp2);
						}
					}
					else
						mobIsDead = true;
				}
				if (mobIsDead)
				{
					for (Entity* entity2 : mEntity)
					{
						if (BreakableObject* temp2 = dynamic_cast<BreakableObject*>(entity2))
						{
							temp->SetDirection(Vector2(temp2->GetX() - temp->GetX(), temp2->GetY() - temp->GetY()));
							//std::cout << temp2->GetX() - temp->GetX() << "    " << temp2->GetY() - temp->GetY() << std::endl;
							temp->Move();

							float distance = sqrt((temp->GetX() - temp2->GetX()) * (temp->GetX() - temp2->GetX()) + (temp->GetY() - temp2->GetY()) * (temp->GetY() - temp2->GetY()));

							if (distance <= 1)
							{
								temp->Attack(temp2);
							}
						}
					}
				}
			}
		}
	}

	if (IsWin())
	{
		std::cout << "Simulation Finished" << std::endl;
	}
}

bool World::IsWin()
{
	for (Entity* entity : mEntity)
	{
		if (Mob* temp = dynamic_cast<Mob*>(entity))
		{
			if (temp->GetCurrrentHP() > 0)
			{
				//std::cout << "false" << std::endl;
				return false;
			}
		}

		else if (BreakableObject* temp = dynamic_cast<BreakableObject*>(entity))
		{
			if (temp->GetCurrrentHP() > 0)
			{
				//std::cout << "false" << std::endl;
				return false;
			}
		}
	}
	//std::cout << "true" << std::endl;

	return true;
}
