#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow& renderWindow) {
	sf::Texture texture;
	if (!texture.loadFromFile("images/Asteroids_Splash.png"))
		return;

	sf::Sprite sprite(texture);

	float scaleX = (float)renderWindow.getSize().x / texture.getSize().x;
	float scaleY = (float)renderWindow.getSize().y / texture.getSize().y;
	sprite.setScale(scaleX, scaleY);

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event currentEvent;
	while (true) {
		while (renderWindow.pollEvent(currentEvent)) {
			if (currentEvent.type == sf::Event::EventType::KeyPressed
				|| currentEvent.type == sf::Event::EventType::MouseButtonPressed
				|| currentEvent.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}