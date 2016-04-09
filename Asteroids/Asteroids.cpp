// Asteroids.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.h"

using namespace std;
using namespace sf;

int _tmain(int argc, _TCHAR* argv[])
{
	Game game;
	game.start();

	return 0;
}

