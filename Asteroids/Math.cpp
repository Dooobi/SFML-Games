#include "stdafx.h"
#include "Math.h"

float Math::angleBetweenPoints(float x1, float y1, float x2, float y2)
// Vector von Punkt 1 (x1, y1) bis Punkt 2 (x2, y2)
{
	float m = (y2 - y1) / (x2 - x1);
	float angle = atan(m) * 180.0f / PI;	// Winkel-Bereich: ]-90.0f, 90.0f[

	if (x1 < x2) 
	{
		angle += 360.0f;
	}
	else
	{
		angle += 180.0f;
	}

	if (angle >= 360.0f)
		angle -= 360.0f;

	return angle;
}