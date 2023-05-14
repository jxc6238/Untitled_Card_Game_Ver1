#pragma once
#include <stack>
#include "Card.h"
class Deck
{
private:
	stack<Card*> playerDeck;
public:
	Deck() = default;
	void ShuffleDeck();
	void AddCard(Card* card);
	Card* TurnDrawCard();
	bool DeckIsEmpty();
};

