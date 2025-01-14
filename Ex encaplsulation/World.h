#pragma once
#include "iostream"
#include <vector>

class Entity;

class World
{
	std::vector<Entity*> mEntity;

public:
	void Init();
	void Step();
	bool IsWin();
};

