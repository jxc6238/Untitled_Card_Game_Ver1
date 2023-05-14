#include "Player.h"
#include "AttackCard.h"
#include "ArmorCard.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
int Player::GetArmor() {
	return this->armor;
}
int Player::GetHealth() {
	return this->health;
}
void Player::SetArmor(int armor) {
	this->armor = armor;
}
void Player::SetHealth(int health) {
	this->health = health;
}
void Player::SetOpponent(Player* player) {
	this->opponent = player;
}
Player Player::GetOpponent() {
	return *this->opponent;
}
void Player::FillDeck(ifstream& playerFile) {
	//ifstream playerFile;
	//playerFile.open("player1.txt");
	string line;
	string variedValue, type, name, cost;
	while (getline(playerFile, line)) {
		stringstream stmp(line);
		getline(stmp, type, ',');
		getline(stmp, variedValue, ',');
		getline(stmp, name, ',');
		getline(stmp, cost);
		if (type == "AttackCard") {
			this->playerDeck.AddCard(new AttackCard(stoi(variedValue), type, name, stoi(cost)));
		}
		else if (type == "HealthCard") {
			this->playerDeck.AddCard(new HealthCard(stoi(variedValue), type, name, stoi(cost)));
		}
		else if (type == "ArmorCard") {
			this->playerDeck.AddCard(new ArmorCard(stoi(variedValue), type, name, stoi(cost)));
		}
		//this->hand.push_back(playerDeck.TurnDrawCard());
	}
}
void Player::Draw() {
	if (playerDeck.DeckIsEmpty() == true) {
		return;
	}
	else {
		this->hand.push_back(this->playerDeck.TurnDrawCard());
	}
}
void Player::Shuffle() {
	this->playerDeck.ShuffleDeck();
}
void Player::DisplayHand() {
	for (int i = 0; i < hand.size(); i++) {
		Card tmp = *this->hand[i];
		cout << i + 1 << ". Type:" << tmp.GetType() << " Name:"
			<< tmp.GetName() << " Cost:" << tmp.GetCost() << " Modifier:";
		baseCardPtr = hand[i];
		if (tmp.GetType() == "AttackCard") {
			//baseCardPtr = hand[i];
			cout << static_cast<AttackCard*>(baseCardPtr)->GetModifiedValue();
		}
		else if (hand[i]->GetType() == "HealthCard") {
			//baseCardPtr = hand[i];
			cout << static_cast<HealthCard*>(baseCardPtr)->GetModifiedValue();
		}
		else if (tmp.GetType() == "ArmorCard") {
			cout << static_cast<ArmorCard*>(baseCardPtr)->GetModifiedValue();
		}
		cout << endl;
	}
}
int Player::HandSize() {
	return this->hand.size();
}
int Player::GetAvailableRollResource() {
	return this->d20Roll;
}
void Player::RollD20() {
	srand(time(NULL));
	this->d20Roll = rand() % (20 - 1 + 1) + 1;
}
void Player::PlayCard(int cardNum) {
	if (this->GetAvailableRollResource() < this->hand[cardNum - 1]->GetCost()) {
		cout << "Not enough points to play that card!" << endl << endl;
		return;
	}
	int modifier = this->hand[cardNum - 1]->GetModifiedValue();
	if (this->hand[cardNum - 1]->GetType() == "AttackCard") {
		if (this->opponent->GetArmor() > 0) {
			if (this->opponent->GetArmor() > modifier) {
				this->opponent->SetArmor(this->opponent->GetArmor() - modifier);
				modifier = 0;
			}
			else {
				modifier = modifier - this->opponent->GetArmor();
				this->opponent->SetArmor(0);
			}
			this->opponent->SetHealth(this->opponent->GetHealth() - modifier);
		}
		else {
			this->opponent->SetHealth(this->opponent->GetHealth() - modifier);
		}
	}
	else if (this->hand[cardNum - 1]->GetType() == "HealthCard") {
		if (this->health + modifier > 20) {
			this->SetHealth(20);
		}
		else {
			this->SetHealth(this->GetHealth() + modifier);
		}
	}
	else if (this->hand[cardNum - 1]->GetType() == "ArmorCard") {
		this->SetArmor(this->GetArmor() + modifier);
	}
	this->d20Roll = this->d20Roll - this->hand[cardNum - 1]->GetCost();
	cout << endl;
	Card* tmp = this->hand[cardNum - 1];
	hand.erase(hand.begin() + (cardNum - 1));
	delete tmp;
}
