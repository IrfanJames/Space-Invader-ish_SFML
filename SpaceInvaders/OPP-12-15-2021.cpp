/* 1366 x 768
taskkill /F /IM SFML.exe
*/
#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "OOP_Classes.h"

//#include "Collision.hpp"
using namespace std;
using namespace sf;


bool Gray0OrPink1 = 0;
int Background = 1, BOSS = 1, JETS = 1;

bool isCollide(Entity* a, Entity* b) {
	return (b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y) < (a->radius + b->radius) * (a->radius + b->radius);
}


int main() {

	time_t bulletclock = 0;
	int bulletTime = 0;
	//float x = W / 2, y = L - 130, dx = 0, dy = 0, angle = -90;// , bulletadd = 0.05f;
	srand(time(NULL));

	RenderWindow app(VideoMode(W, L), "Test");
	app.setFramerateLimit(60);

	Texture t2, t3, t4;
	t2.loadFromFile("Images/Jet/We-2.png");
	t3.loadFromFile("Images/Flame-1.png");
	t4.loadFromFile("Images/Bullet-Yellow.png");

	Texture j1, j2, j3, j4;
	j1.loadFromFile("Images/Jet/Jet-1.png");
	j2.loadFromFile("Images/Jet/Jet-2.png");
	j3.loadFromFile("Images/Jet/Jet-3.png");
	j4.loadFromFile("Images/Jet/Jet-4.png");


	Texture b1, b2, b3, b4, b5, b6;
	b1.loadFromFile("Images/Background/Back-1.png");
	b2.loadFromFile("Images/Background/Back-2.png");
	b3.loadFromFile("Images/Background/Back-3.png");
	b4.loadFromFile("Images/Background/Back-4.png");
	b5.loadFromFile("Images/Background/Back-5.png");
	b6.loadFromFile("Images/Background/Back-6.png");

	Texture g1, g2, g3, p1, p2, p3, p4, p5, p6, p7, p8, p9;
	g1.loadFromFile("Images/Asteroids/Grey-1.png");
	g2.loadFromFile("Images/Asteroids/Grey-2.png");
	g3.loadFromFile("Images/Asteroids/Grey-3.png");
	p1.loadFromFile("Images/Asteroids/Pink-1.png");
	p2.loadFromFile("Images/Asteroids/Pink-2.png");
	p3.loadFromFile("Images/Asteroids/Pink-3.png");
	p4.loadFromFile("Images/Asteroids/Pink-4.png");
	p5.loadFromFile("Images/Asteroids/Pink-5.png");
	p6.loadFromFile("Images/Asteroids/Pink-6.png");
	p7.loadFromFile("Images/Asteroids/Pink-7.png");
	p8.loadFromFile("Images/Asteroids/Pink-8.png");
	p9.loadFromFile("Images/Asteroids/Pink-9.png");

	Texture B1, B2, B3, B4, B5, B6;
	B1.loadFromFile("Images/Boss/Boss-1.png");
	B2.loadFromFile("Images/Boss/Boss-2.png");
	B3.loadFromFile("Images/Boss/Boss-3.png");
	B4.loadFromFile("Images/Boss/Boss-4.png");
	B5.loadFromFile("Images/Boss/Boss-5.png");
	B6.loadFromFile("Images/Boss/Boss-6.png");


	Sprite sBack,  sFlame(t3);

	switch (Background) {
	case 1: sBack.setTexture(b1); break;
	case 2: sBack.setTexture(b2); break;
	case 3: sBack.setTexture(b3); break;
	case 4: sBack.setTexture(b4); break;
	case 5: sBack.setTexture(b5); break;
	case 6: sBack.setTexture(b6); break;
	default: break;
	}

	Animation sBullet(t4, 0, 0, 30, 63, 1, 0.1f);
	//sWe.setOrigin(116.5, 99);

	list<Entity*> entities;

	Animation sWe(t2, 0, 0, 233, 198, 1, 0.1f);

	We* ww = new We();
	ww->setAll(sWe, W / 2, 200, -90, 200);
	entities.push_back(ww);


	Animation sBoss;
	switch (BOSS) {
	case 1: sBoss.setAll(B1, 0, 0, 828, 460, 1, 0.2f); break;
	case 2: sBoss.setAll(B2, 0, 0, 828, 497, 1, 0.2f); break;
	case 3: sBoss.setAll(B3, 0, 0, 828, 377, 1, 0.2f); break;
	case 4: sBoss.setAll(B4, 0, 0, 828, 527, 1, 0.2f); break;
	case 5: sBoss.setAll(B5, 0, 0, 828, 273, 1, 0.2f); break;
	case 6: sBoss.setAll(B6, 0, 0, 981, 532, 1, 0.2f); break;
	default: break;
	}

	sBoss.sprite.setPosition(W / 2, 200);
	Boss* bb = new Boss();
	bb->setAll(sBoss, W / 2, 200, -90, 200);
	entities.push_back(bb);


	for (int c = 0; c < 50; c++) {
		Animation sAsteroid;
		if (Gray0OrPink1 == 0) {
			switch (rand() % 3 + 1) {
			case 1: sAsteroid.setAll(g1, 0, 0, 175, 156, 1, 0.2f); break;
			case 2: sAsteroid.setAll(g2, 0, 0, 175, 153, 1, 0.2f); break;
			case 3: sAsteroid.setAll(g3, 0, 0, 175, 153, 1, 0.2f); break;
			default: break;
			}
		}
		else {
			switch (rand() % 9 + 1) {
			case 1: sAsteroid.setAll(p1, 0, 0, 112, 131, 1, 0.2f); break;
			case 2: sAsteroid.setAll(p2, 0, 0, 128, 130, 1, 0.2f); break;
			case 3: sAsteroid.setAll(p3, 0, 0, 128, 129, 1, 0.2f); break;
			case 4: sAsteroid.setAll(p4, 0, 0, 128, 120, 1, 0.2f); break;
			case 5: sAsteroid.setAll(p5, 0, 0, 128, 121, 1, 0.2f); break;
			case 6: sAsteroid.setAll(p6, 0, 0, 131, 121, 1, 0.2f); break;
			case 7: sAsteroid.setAll(p7, 0, 0, 131, 114, 1, 0.2f); break;
			case 8: sAsteroid.setAll(p8, 0, 0, 131, 128, 1, 0.2f); break;
			case 9: sAsteroid.setAll(p9, 0, 0, 131, 123, 1, 0.2f); break;
			default: break;
			}
		}
		Asteroids* a = new Asteroids();
		a->setAll(sAsteroid, (float)(rand() % W), -(float)(rand() % 500), rand() % 360, 25.0f);
		float sss = ((float)(rand() % 50 + 30)) / 100;
		a->anim.sprite.setScale(sss, sss);
		entities.push_back(a);
	}

	Animation sEnemy;
	for (int c = 0; c < 8; c++) {
		SpaceCraft* s = new SpaceCraft();
		switch (rand() % 4 + 1) {
		case 1: sEnemy.setAll(j1, 0, 0, 173, 198, 1, 0.1f); break;
		case 2: sEnemy.setAll(j2, 0, 0, 173, 198, 1, 0.1f); break;
		case 3: sEnemy.setAll(j3, 0, 0, 173, 198, 1, 0.1f); break;
		case 4: sEnemy.setAll(j4, 0, 0, 173, 198, 1, 0.1f); break;
		default: break;
		}

	s->setAll(sEnemy, 400 * c + 20 + 100, 100 + 100, 90, 60);
	//s->setAll(sEnemy, (float)(rand() % (W - 87 - 87) + 87), (float)(rand() % (L - 99 - 99 - 450) + 99), 0, 80);
	entities.push_back(s);
	}

	float frame = 0, animationSpeed = 0.27f;
	int frameCount = 20;
	sFlame.setOrigin((float)(30 + (int)frame * 60), 0);


	while (app.isOpen()) {
		Event eve;
		while (app.pollEvent(eve)) {
			if (eve.type == eve.Closed) app.close();
			/*
			if (eve.type == eve.KeyPressed)
				if (eve.key.code == Keyboard::Space) {
					Bullets* b = new Bullets();
					b->setAll(sBullet, x, y, angle, 30);
					entities.push_back(b);
				}//*/
		}

		///Animation Example///

		frame += animationSpeed;
		frame = (frame > frameCount) * (frame - frameCount) + (frame <= frameCount) * frame;
		sFlame.setTextureRect(IntRect(int(frame) * 60, 0, 60, 60));

		if (Keyboard::isKeyPressed(Keyboard::Right))   ww->x += 10;//ww->angle += 1.5;  
		if (Keyboard::isKeyPressed(Keyboard::Left))    ww->x -= 10;//ww->angle -= 1.5;
		if (Keyboard::isKeyPressed(Keyboard::Up))	   ww->y -= 10;
		if (Keyboard::isKeyPressed(Keyboard::Down))	   ww->y -= 10;

		//if (Keyboard::isKeyPressed(Keyboard::Up)) thrust = true; else thrust = false;
		//*
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			Bullets* b = new Bullets;
			b->setAll(sBullet, ww->x, ww->y, ww->angle, 30);
			entities.push_back(b);
		}//*/

		/*
		for (auto e : entities)
			for (auto f : entities)
				if (e->name == "Asteroid" && f->name == "Bullet")
					if (isCollide(e, f)) { f->life = 0; e->life -= 10; }
					else;
				else if (e->name == "Enemy" && f->name == "Bullet")
					if (isCollide(e, f)) { f->life = 0; e->life -= 5; }
					else;
				else if (e->name == "BigBoss" && f->name == "Bullet")
					if (isCollide(e, f)) { f->life = 0; e->life -= 5; }
					else;
				else if ((e->name == "Enemy" || f->name == "Enemy") && rand() % 73 == 0) { // 73 by trial 'n error// Or what worked
					Bullets* b = new Bullets();
					b->setAll(sBullet, e->x, e->y + 100, e->angle, 30);
					entities.push_back(b);
				}
		//*/
/*
		int n = 0, nn = 0;
		for (auto e : entities) {
			n++;
			if (e->name == "Bullet" || e->name == "EnemyBullet" || e->name == "Enemy") {

				for (auto f : entities)
					if (f->name != "Bullet" || f->name != "EnemyBullet") {

						if ((e->name == "Enemy" && f->name == "Enemy") && rand() % 1371 == 0) { // 171 by trial 'n error// Or what worked
							Bullets* b = new Bullets();
							b->setAll(sBullet, e->x, e->y + 100, e->angle, 30);
							b->name = "EnemyBullet";
							entities.push_back(b);
						}
						else if ((e->name == "Bullet" || e->name == "EnemyBullet") && f->name == "Asteroid") {
							if (isCollide(e, f)) { e->life = 0; f->life = 0; }
						}
						else if (e->name == "Bullet" && f->name == "Enemy") {
							if (isCollide(e, f)) { e->life = 0; f->life -= 5; }
						}
						else if (e->name == "Bullet" && f->name == "BigBoss") {
							if (isCollide(e, f)) { e->life = 0; f->life -= 5; }
						}

						nn++;
					}
			}
		}
		cout << n << ":" << nn << "\t";
//*/
		//*
		int cxc = 0, xcx = 0;
		for (auto e : entities) {
			for (auto f : entities) {

				if ((f->name == "Bullet" || f->name == "EnemyBullet" || f->name == "BigBoss") && rand() % 73 == 0) break; else{
					cxc++;

					if ((e->name == "Enemy" && f->name == "Enemy") && rand() % 1371 == 0) { // 171 by trial 'n error// Or what worked
						Bullets* b = new Bullets();
						b->setAll(sBullet, e->x, e->y + 100, e->angle, 30);
						b->name = "EnemyBullet";
						entities.push_back(b);
					}
					else if (e->name == "Bullet" && f->name == "Asteroid") {

						if (isCollide(e, f)) { e->life = 0; f->life -= 10; }
					}
					else if (e->name == "Bullet" && f->name == "Enemy") {
						if (isCollide(e, f)) { e->life = 0; f->life = 0; }
					}
					else if (e->name == "EnemyBullet" && f->name == "We") {
						if (isCollide(e, f)) { e->life = 0; f->life -= 10; }
					}
					else if (e->name == "Bullet" && f->name == "BigBoss") {
						if (isCollide(e, f)) { e->life = 0; f->life -= 5; }

					}
			}
			}
			xcx++;
		}
		cout << xcx << ":" << cxc << "\t";
		//*/
		/*
		else if (e->name == "Enemy" && f->name == "Enemy")
			if (isCollide(e, f)) {
				if (e->dx == f->dx) { e->dy *= -1; f->dy *= -1; }
				else if (e->dy == f->dy) { e->dx *= -1; f->dx *= -1; }

				//*
				if (e->dx < 0 && f->dx < 0 || e->dx >= 0 && f->dx >= 0) { e->dy *= -1; f->dy *= -1; }
				else if (e->dy < 0 && f->dy < 0 || e->dy >= 0 && f->dy >= 0) { e->dx *= -1; f->dx *= -1; }
				else { e->dx *= -1; f->dx *= -1; e->dy *= -1; f->dy *= -1; }
			}//*/
		//else if (e->name == "Enemy" && f->name == "Asteroid") if (isCollide(e, f)) { e->life = 0; f->life = 0; } else;

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

		for (auto c = entities.begin(); c != entities.end();) {
			Entity* e = *c;
			//if (e->name == "Enemy") e->anim.sprite.setRotation(e->angle - 90);
			e->update();
			e->anim.update();
			if (e->life == 0) {
				if(e->name=="We") app.close();
				c = entities.erase(c);
				delete e;
			}
			else c++;
		}

		///draw///
		app.clear();
		app.draw(sBack);
		if (thrust) {
			sFlame.setPosition(-80 * cos(ww->angle * DegToRad) + ww->x, -80 * sin(ww->angle * DegToRad) + ww->y);
			sFlame.setRotation(ww->angle + 90);
			app.draw(sFlame);
		}
		for (auto d : entities) d->draw(app);
		app.display();

	}

	return 0;
}

/* //12/11/2021
sf::Texture Background;
	if (!Background.loadFromFile("OOP6.png"))
		return 78;
	sf::Sprite still(Background);
	still.setPosition(0, 0);
	still.setRotation(45);

	sf::Texture fristPic;
	if (!fristPic.loadFromFile("Boss2.png"))
		return 87;
	sf::Sprite sprite(fristPic);
	sprite.setPosition(Width / 2 - 981/2, 30);

	sf::RenderWindow window(sf::VideoMode(Width, Length), "Scooby Snacks", sf::Style::Default);
	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed) window.close();

			if (evnt.type == evnt.KeyPressed) {
				if (evnt.key.code == sf::Keyboard::Left)
					sprite.move(-10, 0);
				if (evnt.key.code == sf::Keyboard::Right)
					sprite.move(10, 0);
				if (evnt.key.code == sf::Keyboard::Up)
					sprite.move(0, -10);
				if (evnt.key.code == sf::Keyboard::Down)
					sprite.move(0, 10);

			}

		}

		window.clear(sf::Color::Transparent);
		window.draw(still);
		window.draw(sprite);
		window.display();

	}*/
