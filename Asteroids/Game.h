#ifndef GAME_H
#define GAME_H

#include "GameObjectManager.h"

class Game
{
public:
	static void start();
	static sf::RenderWindow& getWindow();
	const static sf::InputStream& getInput();
	const static int SCREEN_WIDTH = 500;
	const static int SCREEN_HEIGHT = 500;

private:
	static bool isExiting();
	static void gameLoop(float elapsedTime);

	static void showSplashScreen();
	static void showMenu();

	enum GameState { Uninitialized, ShowingSplash,
		Paused, ShowingMenu, Playing, Exiting };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	
	static GameObjectManager _gameObjectManager;
};

#endif