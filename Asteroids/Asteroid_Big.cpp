#include "stdafx.h"
#include "Asteroid_Big.h"
#include "Game.h"

Asteroid_Big::Asteroid_Big() :
_currentFrameInbound(false),
_previousFrameInbound(false)
{
	std::cout << "Creating Asteroid:" << std::endl;	/// DEBUGGING
	load("images/Asteroid_Big.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getLocalBounds().width / 2, getSprite().getLocalBounds().height / 2);

	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_real_distribution<float> distVelocity(50.0f, 100.0f);
	_velocity = distVelocity(mt);

	setInitialPosition(mt);
}

Asteroid_Big::~Asteroid_Big()
{
}

void Asteroid_Big::setInitialPosition(std::mt19937 mt)	//////// HIER HIER HIER HIER HIER HIER HIER HIER HIER HIER HIER HIER HIER HIERH IERH IIHER HIER HIER HIER HIER 
{
	std::uniform_int_distribution<int> distBorder(1, 4);
	std::uniform_real_distribution<float> distBorderPos(0.0f, 1.0f);

	sf::FloatRect spr = getSprite().getLocalBounds();
	float x = 0.0f, y = 0.0f;
	int border = distBorder(mt);
	float borderPos = distBorderPos(mt);

	switch (border)	// Calculating Position
	{
	case 1:
		y = -spr.height / 2;
		x = (Game::SCREEN_WIDTH + spr.width) * borderPos - spr.width / 2;
		break;
	case 2:
		x = Game::SCREEN_WIDTH + spr.width / 2;
		y = (Game::SCREEN_HEIGHT + spr.height) * borderPos - spr.height / 2;
		break;
	case 3:
		y = Game::SCREEN_HEIGHT + spr.height / 2;
		x = (Game::SCREEN_WIDTH + spr.width) * borderPos - spr.width / 2;
		break;
	case 4:
		x = -spr.width / 2;
		y = (Game::SCREEN_HEIGHT + spr.height) * borderPos - spr.height / 2;
		break;
	}
	setPosition(x, y);	// Setting position

	sf::Vector2f point1, point2;
	float angle, angle1, angle2;
	switch (border)		// Calculating rotation
	{
	case 1:
		if (x < 0)
		{
			point1.x = 0.0f;
			point1.y = Game::SCREEN_HEIGHT;
			point2.x = Game::SCREEN_WIDTH;
			point2.y = 0.0f;
		}
		else if (x > Game::SCREEN_WIDTH)
		{
			point1.x = 0.0f;
			point1.y = 0.0f;
			point2.x = Game::SCREEN_WIDTH;
			point2.y = Game::SCREEN_HEIGHT;
		}
		else
		{
			point1.x = 0.0f;
			point1.y = 0.0f;
			point2.x = Game::SCREEN_WIDTH;
			point2.y = 0.0;
		}
		break;
	case 2:
		if (y < 0)
		{
			point1.x = 0.0f;
			point1.y = 0.0f;
			point2.x = Game::SCREEN_WIDTH;
			point2.y = Game::SCREEN_HEIGHT;
		}
		else if (y > Game::SCREEN_HEIGHT)
		{
			point1.x = Game::SCREEN_WIDTH;
			point1.y = 0.0f;
			point2.x = 0.0f;
			point2.y = Game::SCREEN_HEIGHT;
		}
		else
		{
			point1.x = Game::SCREEN_WIDTH;
			point1.y = 0.0f;
			point2.x = Game::SCREEN_WIDTH;
			point2.y = Game::SCREEN_HEIGHT;
		}
		break;
	case 3:
		if (x < 0)
		{
			point1.x = 0.0f;
			point1.y = 0.0f;
			point2.x = Game::SCREEN_WIDTH;
			point2.y = Game::SCREEN_HEIGHT;
		}
		else if (x > Game::SCREEN_WIDTH)
		{
			point1.x = Game::SCREEN_WIDTH;
			point1.y = 0.0f;
			point2.x = 0.0f;
			point2.y = Game::SCREEN_HEIGHT;
		}
		else
		{
			point1.x = 0.0f;
			point1.y = Game::SCREEN_HEIGHT;
			point2.x = Game::SCREEN_WIDTH;
			point2.y = Game::SCREEN_HEIGHT;
		}
		break;
	case 4:
		if (y < 0)
		{
			point1.x = 0.0f;
			point1.y = Game::SCREEN_HEIGHT;
			point2.x = Game::SCREEN_WIDTH;
			point2.y = 0.0f;
		}
		else if (y > Game::SCREEN_HEIGHT)
		{
			point1.x = 0.0f;
			point1.y = 0.0f;
			point2.x = Game::SCREEN_WIDTH;
			point2.y = Game::SCREEN_HEIGHT;
		}
		else
		{
			point1.x = 0.0f;
			point1.y = 0.0f;
			point2.x = 0.0f;
			point2.y = Game::SCREEN_HEIGHT;
		}
		break;
	}

	angle1 = Math::angleBetweenPoints(x, point1.y, point1.x, y);
	angle2 = Math::angleBetweenPoints(x, point2.y, point2.x, y);
	
	if (angle1 > angle2)
	{
		angle = angle1;
		angle1 = angle2;
		angle2 = angle;
	}
	
	if (border == 4)	// Spawn is on left border
	{
		std::uniform_real_distribution<float> distAngleBorders(angle2, angle1 + 360.0f);
		angle = distAngleBorders(mt);
	}
	else
	{
		std::uniform_real_distribution<float> distAngleBorders(angle1, angle2);
		angle = distAngleBorders(mt);
	}

	if (angle >= 360.0f)
		angle -= 360.0f;

	setRotation(angle);
	/*
	std::cout << "Position: (" << x << " | " << y << " )" << std::endl;
	std::cout << "Angle 1 : " << angle1 << std::endl;
	std::cout << "Angle 2 : " << angle2 << std::endl;
	std::cout << "Angle   : " << angle << std::endl;
	*/
}

void Asteroid_Big::update(float elapsedTime)
{
	float moveX = _velocity * cos(getSprite().getRotation() * PI / 180.0) * elapsedTime;
	float moveY = -1 * _velocity * sin(getSprite().getRotation() * PI / 180.0) * elapsedTime;

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

void Asteroid_Big::drawInfo(std::string name)
{
	sf::FloatRect bounds = getSprite().getGlobalBounds();

	std::cout << "Name: " << name << std::endl;
	std::cout << "Destroying: " << isDestroying() << std::endl;
	std::cout << "Bounds: " << std::endl;
	std::cout << " Top    : " << bounds.top << std::endl;
	std::cout << " Width  : " << bounds.width << std::endl;
	std::cout << " Left   : " << bounds.left << std::endl;
	std::cout << " Height : " << bounds.height << std::endl;
}