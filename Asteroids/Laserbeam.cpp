#include "stdafx.h"
#include "Laserbeam.h"
#include "Game.h"
#include "Asteroid_Big.h"

Laserbeam::Laserbeam(int damage, float velocity) : 
	_damage(damage),
	_velocity(velocity),
	_previousFrameInbound(true),
	_currentFrameInbound(false)
{
	load("images/Laserbeam.png");
	assert(isLoaded());

	getSprite().setOrigin(getSprite().getLocalBounds().width / 2, getSprite().getLocalBounds().height / 2);
	getSprite().setColor(sf::Color(0, 255, 0));
}

void Laserbeam::update(float elapsedTime)
{
	float moveX = -1 * _velocity * cos((getSprite().getRotation() + 90) * PI / 180.0) * elapsedTime;
	float moveY = -1 * _velocity * sin((getSprite().getRotation() + 90) * PI / 180.0) * elapsedTime;

	getSprite().move(moveX, moveY);

	collision();

	sf::FloatRect windowBounds(0, 0, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT);

	if (getSprite().getGlobalBounds().intersects(windowBounds))
		_currentFrameInbound = true;
	else
		_currentFrameInbound = false;

	if (_previousFrameInbound == true
		&& _currentFrameInbound == false)
	{
		setDestroying(true);
	}

	_previousFrameInbound = _currentFrameInbound;
}

void Laserbeam::collision()
{
	std::cout << "test" << std::endl;
	std::vector<VisibleGameObject*> vec = Game::_gameObjectManager.get("Asteroid");
	sf::FloatRect boundsAsteroid;
	sf::FloatRect boundsLaserbeam = getSprite().getGlobalBounds();

	for (int i = 0; i < vec.size(); i++)
	{
		boundsAsteroid = ((Asteroid_Big*)vec[i])->getSprite().getGlobalBounds();
		if (boundsLaserbeam.intersects(boundsAsteroid))
		{
			vec[i]->setDestroying(true);
			setDestroying(true);
		}
	}
}