#pragma once
#include <SFML/Graphics.hpp>
#include "OOP_Animation.h"
#include <iostream>

using namespace sf;
using namespace std;

class Entity {
public:
	float x, y, dx, dy, radius, angle, life;
	string name;
	Animation anim;

	Entity() { life = 20.0f; x = W / 2; y = L / 2; dx = 0.0f; dy = 0.0f; angle = 0.0f; radius = 1.0f; }

	void setAll(Animation& a, float X, float Y, float Angle = 0.0f, float Radius = 1.0f) {
		x = X; y = Y; angle = Angle; radius = Radius;
		anim = a;
	}

	virtual void update() {};
	//virtual void hit() {};

	void draw(RenderWindow& app) {
		anim.sprite.setPosition(x, y);
		anim.sprite.setRotation(angle);
		app.draw(anim.sprite);
	}

};