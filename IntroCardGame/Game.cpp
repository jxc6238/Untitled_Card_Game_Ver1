#include "Game.h"
#include <fstream>
#include <iostream>
#include <iomanip>
void Game::InitDecks() {
	ifstream playerFile;
	playerFile.open("player1.txt");
	player1.FillDeck(playerFile);
	playerFile.close();
	playerFile.open("player2.txt");
	player2.FillDeck(playerFile);
	playerFile.close();
	player1.Shuffle();
	player2.Shuffle();
	for (int i = 0; i < 2; i++) {
		player1.Draw();
	}
	for (int i = 0; i < 2; i++) {
		player2.Draw();
	}
}
void Game::DisplayPlayerStats(Player player) {
	cout << "Current Health: " << player.GetHealth() << setw(this->setWidth)
		<< " Current Armor: " << player.GetArmor() << setw(this->setWidth)
		<< " Available points: " << player.GetAvailableRollResource()
		<< endl;
}
void Game::GameLoop() {
	do {
		currentPlayer->Draw();
		currentPlayer->RollD20();
		while (this->cardChoice != -1) {
			cout << name << " Stats: " << endl;
			DisplayPlayerStats(*currentPlayer);
			cout << "Opponent Stats: " << endl;
			DisplayPlayerStats(currentPlayer->GetOpponent());
			this->currentPlayer->DisplayHand();
			cout << "Please select a card to play or enter -1 to end turn: "
				<< endl;
			cin >> this->cardChoice;
			while ((this->cardChoice <= 0 || this->cardChoice >
				this->currentPlayer->HandSize())
				&& this->cardChoice != -1) {
				cout << "Invalid selection, please select a card to play or enter -1 to end turn: "
					<< endl;
				cin >> this->cardChoice;
			}
			if (this->cardChoice != -1) {
				currentPlayer->PlayCard(cardChoice);
			}
		}
		if (currentPlayer == &player1) {
			currentPlayer = &player2;
			name = "Player 2";
		}
		else if (currentPlayer == &player2) {
			currentPlayer = &player1;
			name = "Player 1";
		}
		cardChoice = 1;
		cout << endl << endl;
	} while (!player1.GetHealth() <= 0 || !player2.GetHealth() <= 0);
	return;
}