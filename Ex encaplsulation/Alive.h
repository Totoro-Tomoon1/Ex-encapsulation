#pragma once

class Alive
{
	float mMaxHP;
	float mCurrrentHP;

public:
	Alive(float maxHP);

	virtual float GetMaxHP();
	virtual float GetCurrrentHP();
	virtual void TakeDamage(float damage);
};

