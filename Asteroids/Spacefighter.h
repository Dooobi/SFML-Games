#ifndef SPACEFIGHTER_H
#define SPACEFIGHTER_H

#include "VisibleGameObject.h"

class Spacefighter :
	public VisibleGameObject 
{
public:
	Spacefighter();
	~Spacefighter();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& renderWindow);

	float getVelocity() const;
	float getDirection() const;

private:
	float _motorPower;
	float _acceleration;
	float _velocity;
	float _maxVelocity;
	float _turnrate;
	float _maxTurnrate;
	float _friction;
};

#endif