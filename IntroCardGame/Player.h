#pragma once
#include "Deck.h"
#include "HealthCard.h"
#include "AttackCard.h"
#include "Card.h"
#include <vector>
class Player
{
private:
	int health, armor, d20Roll;
	vector<Card*> hand;
	Deck playerDeck;
	Card* baseCardPtr = NULL;
	Player* opponent = NULL;
public:
	Player() {
		d20Roll = 0;
		health = 20;
		armor = 5;
	}
	int GetArmor();
	int GetHealth();
	void SetArmor(int armor);
	void SetHealth(int health);
	void FillDeck(ifstream& playerFile);
	void DisplayHand();
	int HandSize();
	void PlayCard(int cardNum);
	Player GetOpponent();
	void SetOpponent(Player* opponent);
	void Shuffle();
	void Draw();
	void RollD20();
	int GetAvailableRollResource();
};

