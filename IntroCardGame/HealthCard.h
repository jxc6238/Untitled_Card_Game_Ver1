#pragma once
#include "Card.h"
class HealthCard : public Card
{
private:
	int healthValue;
public:
	HealthCard(int health, string type, string name, int cost) : 
		Card(type, name, cost) {
		this->healthValue = health;
	}
	int getHealthValue();
	void PlayCard();
	int GetModifiedValue() override;
};

