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
	void drawInfo(std::string name);

private:
	void setInitialPosition(std::mt19937 mt);
	float _velocity;
	bool _previousFrameInbound;
	bool _currentFrameInbound;
};

#endif