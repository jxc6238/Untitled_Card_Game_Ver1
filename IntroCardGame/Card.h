#pragma once
#include <string>
using namespace std;
class Card
{
private:
	string name;
	string type;
	int cost;
public:
	Card(string type, string name, int cost) {
		this->type = type;
		this->name = name;
		this->cost = cost;
	}
	Card() = default;
	string GetName();
	string GetType();
	int GetCost();
	virtual int GetModifiedValue();
};

