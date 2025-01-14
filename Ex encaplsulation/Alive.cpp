#include "Alive.h"

Alive::Alive(float maxHP)
{
	mMaxHP = maxHP;
	mCurrrentHP = mMaxHP;
}

float Alive::GetMaxHP()
{
	return mMaxHP;
}

float Alive::GetCurrrentHP()
{
	return mCurrrentHP;
}

void Alive::TakeDamage(float damage)
{
	mCurrrentHP -= damage;
}