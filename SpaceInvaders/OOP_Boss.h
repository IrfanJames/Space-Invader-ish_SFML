#pragma once
#include "OOP_Entity.h"

class Boss : public Entity {
	bool forward0OrBackward1 = 1;
	int disp = 0;
public:
	Boss() {
		name = "BigBoss";
		life = 100.0f;
		x = W / 2;
		y = -300;
		//dy = 5;
	}

	void update() {
		if (y <= 200) { dy += 0.1f; }
		else {
			if (disp <= 0 || disp >= 150) {
				if (forward0OrBackward1 == 1) forward0OrBackward1 = 0;
				else if (forward0OrBackward1 == 0) forward0OrBackward1 = 1;

				disp = 0;
			}

			{ dx = (forward0OrBackward1) ? 0.1 : -0.1;
			dy = (forward0OrBackward1) ? -0.1 : 0.1;
			disp++; }

		}
		x += dx; y += dy;
	}
};