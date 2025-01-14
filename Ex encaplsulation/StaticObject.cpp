#include "StaticObject.h"
#include <iostream>

StaticObject::StaticObject(Vector2 pos) : Entity(pos)
{
	std::cout << "Static Object just created at x = " << this->GetX() << " and y = " << this->GetY() << std::endl;
}