#include "stdafx.h"
#include "Asteroid_Big.h"

Asteroid_Big::Asteroid_Big()
{
	load("images/Asteroid_Big.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getLocalBounds().width / 2, getSprite().getLocalBounds().height / 2);

	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_real_distribution<float> distAngle(0.0f, 360.0f);	// get a random number with: dist(mt)
	std::uniform_real_distribution<float> distVelocity(50.0f, 100.0f);

	_velocity = distVelocity(mt);
	getSprite().setRotation(distAngle(mt));
}

Asteroid_Big::~Asteroid_Big()
{
}

void Asteroid_Big::update(float elapsedTime)
{
	float moveX = _velocity * cos(getSprite().getRotation() * PI / 180.0) * elapsedTime;
	float moveY = _velocity * sin(getSprite().getRotation() * PI / 180.0) * elapsedTime;

	getSprite().move(moveX, moveY);
}

