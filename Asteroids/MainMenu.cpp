#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::show(sf::RenderWindow& renderWindow)
{
	// Load menu image from file
	sf::Texture texture;
	texture.loadFromFile("images/MainMenu.png");
	sf::Sprite sprite(texture);

	float scaleX = (float)renderWindow.getSize().x / texture.getSize().x;
	float scaleY = (float)renderWindow.getSize().y / texture.getSize().y;
	sprite.setScale(scaleX, scaleY);

	// Setup clickable regions

	// Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top = 94 * scaleY;
	playButton.rect.left = 0 * scaleX;
	playButton.rect.width = renderWindow.getSize().x;
	playButton.rect.height = 153 * scaleY;
	playButton.action = Play;

	// Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.top = 252 * scaleY;
	exitButton.rect.left = 0 * scaleX;
	exitButton.rect.width = renderWindow.getSize().x;
	exitButton.rect.height = 112 * scaleY;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	renderWindow.draw(sprite);
	renderWindow.display();

	return getMenuResponse(renderWindow);
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

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow& renderWindow)
{
	sf::Event menuEvent;

	while (true) {
		while (renderWindow.pollEvent(menuEvent)) {
			if (menuEvent.type == sf::Event::MouseButtonPressed) {
				return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed) {
				return Exit;
			}
		}
	}
}