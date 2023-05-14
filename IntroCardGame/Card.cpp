#include "Card.h"

string Card::GetName() {
	return this->name;
}
int Card::GetCost() {
	return this->cost;
}
string Card::GetType() {
	return this->type;
}
int Card::GetModifiedValue() {
	return -1;
}
