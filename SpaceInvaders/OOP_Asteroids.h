#pragma once
#include "OOP_Entity.h"


class Asteroids :public Entity {
	float dRotation;
public:
	Asteroids() {
		name = "Asteroid";
		dx = (float)(rand() % 3 - 1);
		dy = (float)(rand() % 3 + 1);

		life = (float)(rand() % 8 + 5);

		dRotation += rand() % 5 - 2;
		if (dRotation == 0) dRotation = (rand() % 2 == 1) ? 1 : -1;//treniry operator for =>//if (rand() % 2 == 1) dRotation++; else dRotation--;
	}

	void update() {
		angle += dRotation;
		x += dx; y += dy;
		if (y < 0)
		{
			x = (x > W) * 0 + (x <= 0) * W + (0 <= x && x <= W) * x;
			//y = (y > L) * 0 + (y <= 0) * L + (0 <= y && y <= L) * y;
		}
		else if (x > (W + 85) || x<0 || y>(L + 85) || y < -550) life = 0;

	}

};