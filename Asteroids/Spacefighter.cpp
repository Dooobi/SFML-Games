#include "stdafx.h"
#include "Spacefighter.h"
#include "Game.h"

Spacefighter::Spacefighter() :
_motorPower(0),
_acceleration(400),
_velocity(0),
_maxVelocity(9500.0f),	// not really needed because at high speed the friction caps the velocity (velocity loss by friction increases with speed)
_turnrate(0),
_maxTurnrate(270.0f),
_friction(1.5f)
{
	load("images/Spacefighter.png");
	assert(isLoaded());

	getSprite().setOrigin(getSprite().getLocalBounds().width / 2, getSprite().getLocalBounds().height / 2);
}

Spacefighter::~Spacefighter()
{
}

void Spacefighter::draw(sf::RenderWindow& renderWindow)
{
	VisibleGameObject::draw(renderWindow);
}

float Spacefighter::getVelocity() const
{
	return _velocity;
}

void Spacefighter::update(float elapsedTime)
{
	_turnrate = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_turnrate = _maxTurnrate;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_turnrate = -_maxTurnrate;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_turnrate = 0.0f;
	}

	_motorPower = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_motorPower = 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_motorPower = -1.0f;
	}

	// Computing velocity
	_velocity += (_motorPower * _acceleration - _velocity * _friction) * elapsedTime;

	if (_turnrate > _maxTurnrate)
		_turnrate = _maxTurnrate;
	if (_turnrate < -_maxTurnrate)
		_turnrate = -_maxTurnrate;

	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;
	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;

	sf::Vector2f pos = getPosition();

	if (pos.x < 0)
	{
		setPosition(Game::SCREEN_WIDTH, pos.y);
	}
	else if (pos.x > Game::SCREEN_WIDTH)
	{
		setPosition(0, pos.y);
	}

	if (pos.y < 0)
	{
		setPosition(pos.x, Game::SCREEN_HEIGHT);
	}
	else if (pos.y > Game::SCREEN_HEIGHT)
	{
		setPosition(pos.x, 0);
	}

	float moveX = -1 * _velocity * cos((getSprite().getRotation() + 90) * PI / 180.0) * elapsedTime;
	float moveY = -1 * _velocity * sin((getSprite().getRotation() + 90) * PI / 180.0) * elapsedTime;
	/*
	system("cls");
	std::cout << "El. Time: " << elapsedTime << std::endl;
	std::cout << "Turnrate: " << _turnrate << std::endl;
	std::cout << "Velocity: " << _velocity << std::endl;
	std::cout << "Move X  : " << moveX << std::endl;
	std::cout << "Move Y  : " << moveY << std::endl;
	std::cout << "Coord X : " << getPosition().x << std::endl;
	std::cout << "Coord Y : " << getPosition().y << std::endl;
	*/
	getSprite().rotate(-1 * _turnrate * elapsedTime);
	getSprite().move(moveX, moveY);
}