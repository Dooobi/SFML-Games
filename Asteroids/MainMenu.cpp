#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::show(sf::RenderWindow& window)
{
	// Load menu image from file
	sf::Texture texture;
	texture.loadFromFile("images/MainMenu.png");
	sf::Sprite sprite(texture);

	// Setup clickable regions

	// Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top = 94;
	playButton.rect.left = 0;
	playButton.rect.width = window.getSize().x;
	playButton.rect.height = 153;
	playButton.action = Play;

	// Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.top = 252;
	exitButton.rect.left = 0;
	exitButton.rect.width = window.getSize().x;
	exitButton.rect.height = 112;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return getMenuResponse(window);
}

MainMenu::MenuResult MainMenu::handleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++) {
		sf::Rect<int> menuItemRect = it->rect;
		if (menuItemRect.contains(x, y)) {
			return it->action;
		}
	}

	return Nothing;
}

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (true) {
		while (window.pollEvent(menuEvent)) {
			if (menuEvent.type == sf::Event::MouseButtonPressed) {
				return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed) {
				return Exit;
			}
		}
	}
}