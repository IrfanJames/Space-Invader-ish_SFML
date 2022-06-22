#pragma once
#include "OOP_Entity.h"


class We : public Entity {
public:
	We() {
		life = 100.0f; x = W/2; y = 200; radius = 1; angle = -90; name = "We"; dx = 0; dy = 0;
	}

	void update() {
		
		if (thrust)
		{
			dx += sin(angle * DegToRad) * 0.5f;
			dy += -cos(angle * DegToRad) * 0.5f;
		}
		else {
			dx *= 0.99f;
			dy *= 0.99f;
		}
		float speed = sqrt(dx * dx + dy * dy);

		if (speed > maxSpeed) {
			dx *= maxSpeed / speed;
			dy *= maxSpeed / speed;
		}

		

		//x = (x > W) * 0 + (x <= 0) * W + (0 <= x && x <= W) * x;
		//y = (y > L) * 0 + (y <= 0) * L + (0 <= y && y <= L) * y;

		/*if (x > W) x = 0; if (x < 0) x = W;
		if (y > L) y = 0; if (y < 0) y = L;*/

		if (x > W - 90) x = W - 90; if (x < 0 + 90) x = 0 + 90;
		if (y > L - 90) y = L - 90; if (y < 0 + 90) y = 0 + 90;

		anim.sprite.setPosition(x, y);
		anim.sprite.setRotation(angle + 90);


		////dx *= (x <= (87 + 30)) * sin((87 - x + 1)) + (x >= (W - 87)) * sin(W - 87 - 30 - x + 1) + ((87 + 30) < x && x < (W - 87 - 30)); //87 is half-width  of jet //desselerration starts at 10 //+1 to avoid zero in sin()
		////dy *= (y <= (99 + 30)) + (y >= (L - 99 - 30 - 444)) * -1 + ((99 + 30) < y && y < (L - 99 - 30 - 444)) * 1; //99 is half-height of jet //can't go beyond 444 //desselerration starts at 10 //+1 to avoid zero in sin()

		//dx *= -(x <= 87 || x >= (W - 87)) + (87 < x && x < (W - 87)); //87 is half-width  of jet //desselerration starts at 10 //+1 to avoid zero in sin()
		//dy *= -(y <= 99 || y >= (L - 99 - 444)) + (99 < y && y < (L - 99 - 444)); //99 is half-height of jet //can't go beyond 444 //desselerration starts at 10 //+1 to avoid zero in sin()

		//x += dx; y += dy;

		///*x = (x > W) * 0 + (x <= 0) * W + (0 <= x && x <= W) * x;
		//y = (y > L) * 0 + (y <= 0) * L + (0 <= y && y <= L) * y;*/
		///*x += (x > W || x <= 0) * -dx + (0 <= x && x <= W) * dx;
		//y += (y > L || y <= 0) * -dy + (0 <= y && y <= L) * dy;*/
	}
};