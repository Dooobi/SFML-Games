#ifndef SPACEFIGHTER_H
#define SPACEFIGHTER_H

#include "VisibleGameObject.h"
#include "Laserbeam.h"

class Spacefighter :
	public VisibleGameObject 
{
public:
	Spacefighter(int hp = 2);
	~Spacefighter();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& renderWindow);

	float getVelocity() const;
	float getDirection() const;

private:
	void shoot();
	void movement(float elapsedTime);

	std::vector<Laserbeam> laserbeams;
	int _hp;
	float _motorPower;
	float _acceleration;
	float _velocity;
	float _maxVelocity;
	float _turnrate;
	float _maxTurnrate;
	float _friction;
	float _cooldown;
	float _maxCooldown;
	bool _autoShoot;
};

#endif