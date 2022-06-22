/* 1366 x 768 OOP Project
taskkill /F /IM "SpaceInvaders.exe"
*/
#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "OOP_Classes.h"

//#include "Collision.hpp"
using namespace std;
using namespace sf;

bool isCollide(Entity* a, Entity* b) {            
	return (b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y) < (a->radius + b->radius) * (a->radius + b->radius);
}

int main() {

	//RenderWindow app(VideoMode(W, L), "Test", Style::Fullscreen);
	RenderWindow app(VideoMode(W, L), "Test");
	app.setVerticalSyncEnabled(1);
	app.setFramerateLimit(60);
	srand(time(NULL));
	W = app.getSize().x; L = app.getSize().y;


	time_t timeStart = 0;
	time_t bulletclock = 0;
	int bulletTime = 0;
	//float x = W / 2, y = L - 130, dx = 0, dy = 0, angle = -90;// , bulletadd = 0.05f;

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

	Sprite sBack, sFlame(t3);

	//--------------------------------------------------------------------------------------------//
	//--------------------------------------------------------------------------------------------//
	bool wonOrNot = 0;
	levelUP(1);

//for (int level = 1; level <= totalLevels; level++) {
for (int level = 1, Tries=0; level < totalLevels; Tries++) {

	bool game0Over1 = 0;
	int enemyDown = 0;

	//levelUP(level);//*/

	//*
	if (wonOrNot) {
		Tries -= 1;
		enemyDown = 0;
		wonOrNot = 0;
		game0Over1 = 0;
		levelUP(++level);
	}
	//*/

//for (int Tries=0; wonOrNot==0 ; Tries++){ int enemyDown = 0;

	switch (Background1_6) {
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
	ww->setAll(sWe, W / 2, L - 200, 0.0f, 200);
	//ww->anim.sprite.setScale(0.7, 0.7);
	entities.push_back(ww);

//* //-----------Boss 
	
	Animation sBoss;
	switch (BOSS1_6) {
	case 1: sBoss.setAll(B1, 0, 0, 828, 460, 1, 0.2f); break;
	case 2: sBoss.setAll(B2, 0, 0, 828, 497, 1, 0.2f); break;
	case 3: sBoss.setAll(B3, 0, 0, 828, 377, 1, 0.2f); break;
	case 4: sBoss.setAll(B4, 0, 0, 828, 527, 1, 0.2f); break;
	case 5: sBoss.setAll(B5, 0, 0, 828, 273, 1, 0.2f); break;
	case 6: sBoss.setAll(B6, 0, 0, 981, 532, 1, 0.2f); break;
	default: break;
	}

	Boss* bb = new Boss();
	bb->setAll(sBoss, W / 2, -300, 0.0f, 200);
	bb->life = defaultBossLife * ((float)BOSS1_6 * 4 / 5);
	
	//bb->anim.sprite.setScale(1.6, 1.6);
	
	entities.push_back(bb);
	
	//*/
	
//*	//-----------Asteroid


	for (int c = 0; c < asteroidNum; c++) {
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
		a->setAll(sAsteroid, (float)(rand() % W), -(float)(rand() % 500) - 50, rand() % 360, 25.0f);
		float sss = a->life / 17 + Gray0OrPink1 * 0.2; //for 10 life to get 0.3 scale
		//float sss = ((float)(rand() % 50 + 30)) / 100;5-0.3/12-0.8
		a->anim.sprite.setScale(sss, sss);
		entities.push_back(a);
	}
	//*/
	//*	//-----------Enemy
	Animation sEnemy;

	for (int c = 0; c < enemyNum; c++) {
		SpaceCraft* s = new SpaceCraft();

		//cout << arrEnemy[0] << arrEnemy[1] << arrEnemy[2] << arrEnemy[3] << "  ";

		int enimInt = 1;														// |
		for (int c = 0; c < 10; c++) {											// |
			enimInt = rand() % 4 + 1;											// |
			//cout << "\t_-_-" << c << "\t" << enimInt << endl;					// needs to be optimize (heavily)
			if (arrEnemy[enimInt - 1] > 0) { arrEnemy[enimInt - 1]--; break; }	// |
		}																		// |
		//cout << enimInt << "  " << arrEnemy[0] << arrEnemy[1] << arrEnemy[2] << arrEnemy[3] << endl; //	defaultEnemyLife

		switch (enimInt) {
		case 1: sEnemy.setAll(j1, 0, 0, 173, 198, 1, 0.0f); break;
		case 2: sEnemy.setAll(j2, 0, 0, 173, 198, 1, 0.0f); break;
		case 3: sEnemy.setAll(j3, 0, 0, 173, 198, 1, 0.0f); break;
		case 4: sEnemy.setAll(j4, 0, 0, 173, 198, 1, 0.0f); break;
		default: break;
		}

		//s->setAll(sEnemy, W / 9 * c + 20 + 100, 100 + 100, 180, 60); // W/9 <=> 200
		//cout << app.getSize().x << "\t" << (float)(c * app.getSize().x) / enemyNum + 100 + 20 << endl;
		s->setAll(sEnemy, (float)(c* app.getSize().x) / enemyNum + app.getSize().x/18 + app.getSize().x / 90, 100 + 100, 180, 60); //app.getSize().x/18 <=> 100 //app.getSize().x / 90 <=> 20
		//s->setAll(sEnemy, (float)(rand() % (W - 87 - 87) + 87), (float)(rand() % (L - 99 - 99 - 450) + 99), 0, 80);
		s->life = defaultEnemyLife * ((float)enimInt * 4 / 5); // needs imperovment
		entities.push_back(s);
	}
	//*/

	float frame = 0, animationSpeed = 0.27f;
	int frameCount = 20;
	sFlame.setOrigin((float)(30 + (int)frame * 60), 0);

	timeStart = clock();
	while (app.isOpen()) {	//--------------------------------------------------------------------------------------------App Open
		Event eve;
		while (app.pollEvent(eve)) {
			if (eve.type == eve.Closed) app.close();
			/*------------------------Bullets
			if (eve.type == eve.KeyPressed)
				if (eve.key.code == Keyboard::Space) {
					Bullets* b = new Bullets(); // -----------Bullets from us
					b->setAll(sBullet, sin(DegToRad * ww->angle) * 50 + ww->x, -cos(DegToRad * ww->angle) * 50 + ww->y, ww->angle, 30);

					ww->dx -= (0.002f) * (sin(ww->angle * DegToRad)); ww->dy -= (0.002f) * (-cos(ww->angle * DegToRad)); // --------- Recoil of Bullet
					entities.push_back(b);
				}//*/
		}

		///Animation Example///

		frame += animationSpeed;
		frame = (frame > frameCount) * (frame - frameCount) + (frame <= frameCount) * frame;
		sFlame.setTextureRect(IntRect(int(frame) * 60, 0, 60, 60));
		
		if (Keyboard::isKeyPressed(Keyboard::Right))   ww->angle += 2; //ww->x += 10;
		if (Keyboard::isKeyPressed(Keyboard::Left))    ww->angle -= 2; //ww->x -= 10;//
		//if (Keyboard::isKeyPressed(Keyboard::Up))	   ww->y -= 10;
		//if (Keyboard::isKeyPressed(Keyboard::Down))	   ww->y += 10;
		if (Keyboard::isKeyPressed(Keyboard::Down)) { ww->x -= ww->dx; ww->y -= ww->dy; }
		else { ww->x += ww->dx; ww->y += ww->dy; }

		if (Keyboard::isKeyPressed(Keyboard::Up)) thrust = true; else thrust = false;
		
		//------------------------Bullets
		
		if (0.1f + (float)(rand() % 10 / 100) <= (float)((float)(clock() - bulletTime) / CLOCKS_PER_SEC)) {
			if (Keyboard::isKeyPressed(Keyboard::Space)) {

				//*
				Bullets* b = new Bullets; // -----------Bullets from us
				b->setAll(sBullet, ww->x, ww->y, ww->angle, 30);
				ww->dx -= (0.002f) * (sin(ww->angle * DegToRad)); ww->dy -= (0.002f) * (-cos(ww->angle * DegToRad)); // --------- Recoil of Bullet
				entities.push_back(b);
				//*/


				bulletTime = clock();
			}
		}






		/*
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			Bullets* b = new Bullets; // -----------Bullets from us
			b->setAll(sBullet, ww->x, ww->y, ww->angle, 30);
			ww->dx -= (0.002f) * (sin(ww->angle * DegToRad)); ww->dy -= (0.002f) * (-cos(ww->angle * DegToRad)); // --------- Recoil of Bullet
			entities.push_back(b);
		}//*/
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { app.close(); cout << "\n\n\tESC Pressed\n"; }
		//*

		int n = 0, nn = 0;
		for (auto e : entities) {
			n++;
			if (e->name == "Bullet" || e->name == "EnemyBullet") {

				for (auto f : entities)
					if (f->name == "Bullet" || f->name == "EnemyBullet" || (f->name == "We" && e->name == "Bullet") || (e->name == "EnemyBullet" && (f->name == "Enemy" || f->name == "BigBoss"))) continue;
					else {
						if (f->name == "Enemy") {
							if (isCollide(e, f)) { e->life = 0; f->life -= 5; }
						}
						else if (f->name == "Asteroid") { // Bullet & Asteroid
							if (isCollide(e, f)) { e->life = 0; f->life -= 10; }
						}
						else if (f->name == "We") {
							if (isCollide(e, f)) { e->life = 0; f->life -= 10; }
						}
						else if (f->name == "BigBoss") {
							if (isCollide(e, f)) { e->life = 0; f->life -= 5; }
						}
						//cout << e->name << "\t" << f->name << "\n";
						nn++;
					}
			}
			else if (e->name == "Enemy" && rand() % 200 == 0) { // 500 by trial 'n error// Or what worked
				Bullets* b = new Bullets();
				b->setAll(sBullet, e->x, e->y + 100, e->angle, 30);
				b->name = "EnemyBullet";
				entities.push_back(b);
			}
			else if (e->name == "BigBoss" && rand() % 200 == 0) { // 500 by trial 'n error// Or what worked
				int tempAngDisp = rand() % 400;
				for (int c = 0; c < noOfBossBullets; c++) {
					Bullets* bb = new Bullets();
					//cout << e->x + sin(DegToRad * 180 / noOfBossBullets * (c * 25 - 80)) * 30 << "\t" << e->y + -cos(DegToRad * 180 / noOfBossBullets * (c * 25 - 80)) * 180 / noOfBossBullets << endl;
					bb->setAll(sBullet, e->x + sin(DegToRad * 180 / noOfBossBullets * (c * 25 - 80)) * 30, e->y + -cos(DegToRad * 180 / noOfBossBullets * (c * 25 - 80)) * 180 / noOfBossBullets, 242.5 - c * 25.0 + tempAngDisp, 30);
					bb->name = "EnemyBullet";
					entities.push_back(bb);
				}
			}
		}
		//cout << n << "(" << n * n << "): " << nn << endl;

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

	/*
		{ W = app.getSize().x; L = app.getSize().y;
		cout << W << "\t" << L << endl; }//*/

		//float changeW = 0;//////////-------------------------------
		//float changeL = 0;
		//float changeSize = 0;


		//changeW = (float)(app.getSize().x - 1800);
		//changeL = (float)(app.getSize().y - 1000);

		//changeSize = (float)(changeL + changeW) / 2;
		////changeSize *= 0.1f;
		//W = app.getSize().x; L = app.getSize().y;/////---------------

		for (auto c = entities.begin(); c != entities.end();) {
			Entity* e = *c;
			
			if (e->name == "Asteroid" || e->name == "BigBoss") {
				if (e->name == "Asteroid") {
					if (((float)(clock() - timeStart) / CLOCKS_PER_SEC) >= asteroidTime) {
						e->update();
						e->anim.update();
					}
				}
				else if (((float)(clock() - timeStart) / CLOCKS_PER_SEC >= 15) || enemyDown >= bossTime) {
					e->update();
					e->anim.update();
				}
			}
			else {
				e->update();
				e->anim.update();
			}
			//e->anim.sprite.setScale(1 - changeSize, 1 - changeSize);----------
			if (e->life <= 0) {
				if (e->name == "We") { cout << "\n\n\tYou Died !!!\n"; wonOrNot = 0; goto WON_OR_NOT; }
				if (e->name == "Enemy" || e->name == "BigBoss") enemyDown++;

				if (enemyDown >= (enemyNum + 1)) {
					cout << "\n\n\t\"You Won !!!\"\n";
					cout << "\nTotal Time on this Level: " << (float)(clock() - timeStart) / CLOCKS_PER_SEC << endl;
					wonOrNot = 1; goto WON_OR_NOT;
				}
				else wonOrNot = 0;

				c = entities.erase(c);
				delete e;
			}
			else c++;
		}
		///draw///
		app.clear();
		app.draw(sBack);
		if (!menu) {
			if (thrust) {
				sFlame.setPosition(-80 * sin(ww->angle * DegToRad) + ww->x, -80 * -cos(ww->angle * DegToRad) + ww->y);
				sFlame.setRotation(ww->angle);
				app.draw(sFlame);
			}
			for (auto d : entities) d->draw(app);
		}

		app.display();
	}

WON_OR_NOT:

	if (Tries >= TotalLives) { game0Over1 = 1; cout << "Tries: " << Tries << endl; app.close(); break; }

//}	if (game0Over1) break;

}

return 0;
}
