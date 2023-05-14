// IntroCardGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"

int main()
{
    Game game;
    game.InitDecks();
    game.GameLoop();
    cout << "The game has ended!" << endl;
}
