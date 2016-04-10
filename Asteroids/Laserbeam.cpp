#include "stdafx.h"
#include "Laserbeam.h"
#include "Game.h"

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