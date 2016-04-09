#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"

#include "Spacefighter.h"

void Game::start(void)
{
	if (_gameState != Uninitialized) {
		return;
	}

	_mainWindow.create(sf::VideoMode(500, 500), "Asteroids");
	_gameState = Game::ShowingSplash;

	Spacefighter *player1 = new Spacefighter();
	player1->load("Spacefighter.png");
	player1->setPosition(_mainWindow.getSize().x / 2, _mainWindow.getSize().y / 2);

	_gameObjectManager.add("Player1", player1);
	_gameState = Game::ShowingSplash;

	sf::Clock clock;
	while (!isExiting()) {
		gameLoop(clock.restart().asSeconds());
	}

	_mainWindow.close();
}

bool Game::isExiting()
{
	if (_gameState == Game::Exiting) {
		return true;
	}

	return false;
}

sf::RenderWindow& Game::getWindow()
{
	return _mainWindow;
}

void Game::gameLoop(float elapsedTime) {
	sf::Event currentEvent;

	while (_mainWindow.pollEvent(currentEvent)) {
		switch (_gameState) {
			case Game::ShowingSplash:
				break;
			case Game::ShowingMenu:
				break;
			case Game::Playing:
				if (currentEvent.type == sf::Event::Closed) {
					_gameState = Game::Exiting;
				}
				break;
		}
	}

	switch (_gameState) {
	case Game::ShowingSplash:
		showSplashScreen();
		break;
	case Game::ShowingMenu:
		showMenu();
		break;
	case Game::Playing:
		_mainWindow.clear(sf::Color(0, 0, 0));
		_gameObjectManager.updateAll(elapsedTime);
		_gameObjectManager.drawAll(_mainWindow);
		_mainWindow.display();

		if (currentEvent.type == sf::Event::Closed) {
			_gameState = Game::Exiting;
		}
		break;
	}
}

void Game::showSplashScreen() {
	SplashScreen splashScreen;
	splashScreen.show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::showMenu() {
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.show(_mainWindow);

	switch (result) {
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
	}
}
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;