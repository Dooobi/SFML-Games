#ifndef LASERBEAM_H
#define LASERBEAM_H

#include "VisibleGameObject.h"

class Laserbeam
	: public VisibleGameObject
{
public:
	Laserbeam(int damage, float velocity);
	
	void update(float elapsedTime);

private:
	void collision();

	float _velocity;
	int _damage;
	bool _previousFrameInbound;
	bool _currentFrameInbound;
};

#endif