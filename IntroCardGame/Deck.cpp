#include "Deck.h"
#include <vector>
#include <time.h>
Card* Deck::TurnDrawCard() {
	Card* nextCardPtr = playerDeck.top();
	playerDeck.pop();
	return nextCardPtr;
}
bool Deck::DeckIsEmpty() {
	return playerDeck.empty();
}
void Deck::ShuffleDeck() {
	vector<Card*> tmp;
	int position;
	while (playerDeck.empty() != true) {
		tmp.push_back(this->playerDeck.top());
		playerDeck.pop();
	}
	srand(time(NULL));
	while (tmp.empty() != true) {
		position = rand() % (tmp.size());
		this->playerDeck.push(tmp[position]);
		tmp.erase(tmp.begin() + position);
	}
}
void Deck::AddCard(Card* card) {
	playerDeck.push(card);
}