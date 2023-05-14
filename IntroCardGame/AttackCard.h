#pragma once
#include "Card.h"
#include "Player.h"
class AttackCard : public Card
{
private:
	int attackValue;
public:
	AttackCard(int attackValue, string type, string name, int cost) : 
		Card(type, name, cost) {
		this->attackValue = attackValue;
	}
	int GetAttackValue();
	int GetModifiedValue() override;
};

