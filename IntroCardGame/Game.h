#pragma once
#include "Player.h"
#include "AttackCard.h"
#include "HealthCard.h"
#include <memory>
class Game
{
private:
	Player player1, player2;
	string name;
	Player *currentPlayer;
	int cardChoice = 1;
	const int setWidth = 3;
public:
	Game() {
		name = "Player 1";
		currentPlayer = &player1;
		player1.SetOpponent(&player2);
		player2.SetOpponent(&player1);
	}
	void InitDecks();
	void GameLoop();
	void DisplayPlayerStats(Player player);
};

