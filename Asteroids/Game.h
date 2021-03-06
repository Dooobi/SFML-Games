#ifndef GAME_H
#define GAME_H

#include "GameObjectManager.h"
#include "InputHandler.h"

class Game
{
public:
	static void start();
	static sf::RenderWindow& getWindow();
	const static sf::InputStream& getInput();
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 800;
	static GameObjectManager _gameObjectManager;
	static InputHandler _inputHandler;

private:
	static bool isExiting();
	static void gameLoop(float elapsedTime);

	static void showSplashScreen();
	static void showMenu();

	enum GameState { Uninitialized, ShowingSplash,
		Paused, ShowingMenu, Playing, Exiting };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};

#endif