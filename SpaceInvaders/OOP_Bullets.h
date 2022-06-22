#pragma once
#include "OOP_Entity.h"


class Bullets : public Entity {
public:
	Bullets() {
		name = "Bullet";
	}
	void update() {
		dx = sin(angle * DegToRad) * 20;
		dy = -cos(angle * DegToRad) * 20;

		x += dx; y += dy;
		if (x > W || x<0 || y>L || y < 0) life = 0;
	}
};