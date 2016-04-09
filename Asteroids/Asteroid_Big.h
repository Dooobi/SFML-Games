#ifndef ASTEROID_BIG_H
#define ASTEROID_BIG_H

#include "VisibleGameObject.h"

class Asteroid_Big 
	: public VisibleGameObject 
{
public:
	Asteroid_Big();
	~Asteroid_Big();

	void update(float elapsedTime);

private:
	float _velocity;
};

#endif