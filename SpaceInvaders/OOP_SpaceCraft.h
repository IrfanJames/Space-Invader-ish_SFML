#pragma once
#include "OOP_Entity.h"

class SpaceCraft : public Entity {
public:
	bool automatic;
	float health;
	SpaceCraft() {
		life = defaultEnemyLife; x = 0.1f; y = 0.1f; radius = 1; angle = -90; name = "Enemy"; automatic = 1; // health = 20;

		dx = (rand() % 2 + 1);
		dx = (rand() % 2 == 1) ? dx : -dx;

		dy = (rand() % 2 + 1);
		dy = (rand() % 2 == 1) ? dy : -dy;

		/*dx = (rand() % 2 == 1) ? 2 : -2;
		dy = (rand() % 2 == 1) ? 2 : -2;*/


		/*dy = (float)(rand() % 2 - 2);
		if (dy == 0)
			if (rand() % 2 == 1) dy++; else dy--;

		if (dx == 0 || dy == 0) cout << "Zero Alert !!!\n";*/


	}
	friend Entity;
	void hit(float Damage) { health -= Damage; }
	void update() {
		
		//dx *= (x <= (87 + 30)) * sin((87 - x + 1)) + (x >= (W - 87)) * sin(W - 87 - 30 - x + 1) + ((87 + 30) < x && x < (W - 87 - 30)); //87 is half-width  of jet //desselerration starts at 10 //+1 to avoid zero in sin()
		//dy *= (y <= (99 + 30)) + (y >= (L - 99 - 30 - 444)) * -1 + ((99 + 30) < y && y < (L - 99 - 30 - 444)) * 1; //99 is half-height of jet //can't go beyond 444 //desselerration starts at 10 //+1 to avoid zero in sin()

		dx *= -(x <= 87 || x >= (W - 87)) + (87 < x && x < (W - 87)); //87 is half-width  of jet //desselerration starts at 10 //+1 to avoid zero in sin()
		dy *= -(y <= 99 || y >= (L - 99 - 300)) + (99 < y && y < (L - 99 - 300)); //99 is half-height of jet //can't go beyond 444 //desselerration starts at 10 //+1 to avoid zero in sin()

		x += dx * 1.5; y += dy * 1.5;
		
		/*x = (x > W) * 0 + (x <= 0) * W + (0 <= x && x <= W) * x;
		y = (y > L) * 0 + (y <= 0) * L + (0 <= y && y <= L) * y;*/
		/*x += (x > W || x <= 0) * -dx + (0 <= x && x <= W) * dx;
		y += (y > L || y <= 0) * -dy + (0 <= y && y <= L) * dy;*/
	}
};

///spaceship movement///

		//if (thrust)
		//{
		//	dx += cos(angle * DegToRad) * 0.5f;
		//	dy += sin(angle * DegToRad) * 0.5f;
		//}
		//else {
		//	dx *= 0.99f;
		//	dy *= 0.99f;
		//}
		//float speed = sqrt(dx * dx + dy * dy);

		//if (speed > maxSpeed) {
		//	dx *= maxSpeed / speed;
		//	dy *= maxSpeed / speed;
		//}

		//if (Keyboard::isKeyPressed(Keyboard::Down)) { x -= dx; y -= dy; }
		//else { x += dx; y += dy; }

		////x = (x > W) * 0 + (x <= 0) * W + (0 <= x && x <= W) * x;
		////y = (y > L) * 0 + (y <= 0) * L + (0 <= y && y <= L) * y;

		//if (x > W) x = 0; if (x < 0) x = W;
		//if (y > L) y = 0; if (y < 0) y = L;
		//sWe.sprite.setPosition(x, y);
		//sWe.sprite.setRotation(angle + 90);