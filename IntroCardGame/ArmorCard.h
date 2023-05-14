#pragma once
#include "Card.h"
class ArmorCard : public Card
{
private:
	int armorValue;
public:
	ArmorCard(int armorValue, string type, string name, int cost) :
		Card(type, name, cost) {
		this->armorValue = armorValue;
	}
	int GetModifiedValue() override;
};

