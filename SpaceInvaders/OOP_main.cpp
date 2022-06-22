//#include <iostream>
//#include <list>
//#include <SFML/Graphics.hpp>
//using namespace std;
//using namespace sf;
//const int W = 1800, H = 1000;
//float DegToRad = 0.017453f;
//
//int main() {
//
//	RenderWindow app(VideoMode(W, H), "Dune");
//	app.setFramerateLimit(60);
//
//	Texture t1, t2, t3, t4, t5, t6;
//	t1.loadFromFile("Back-1.png");
//	t2.loadFromFile("We-2.png");
//	t3.loadFromFile("Flame-1.png");
//	t4.loadFromFile("Gery-3-Animation.png");
//	t5.loadFromFile("Bullet-Yellow.png");
//	t6.loadFromFile("Jet-4.png");
//
//	Sprite sBack(t1), sWe(t2), sFlame(t3);
//	sWe.setOrigin(116.5, 99);
//	sWe.setPosition(W / 2, H - 120);
//
//	float Frame = 0, animSpeed = 0.4, animCount = 20;
//
//
//	float x = W / 2, y = H - 150, dx = 0, dy = 0, angle = -90, speed = 0;
//	int maxSpeed = 15;
//	bool thrust = 0;
//
//
//	while (app.isOpen()) {
// 
//		Event eve;
//		while (app.pollEvent(eve)) {
//			if (eve.type == eve.Closed) app.close();
//
//		}
//		/*
//		if (Keyboard::isKeyPressed(Keyboard::Right))  x += 7;
//		if (Keyboard::isKeyPressed(Keyboard::Left))   x -= 7;
//		if (Keyboard::isKeyPressed(Keyboard::Up))     y -= 7;
//		if (Keyboard::isKeyPressed(Keyboard::Down))   y += 7;//*/
//		//*
//		if (Keyboard::isKeyPressed(Keyboard::Right))  angle += 3;
//		if (Keyboard::isKeyPressed(Keyboard::Left))   angle -= 3;
//		if (Keyboard::isKeyPressed(Keyboard::Up))     thrust = 1; else thrust = 0;//*/
//
//		///Flame Animation E.g.
//		Frame += animSpeed;
//		Frame = (Frame >= animCount) * (Frame - animCount) + (Frame < animCount) * Frame;
//		sFlame.setTextureRect(IntRect((int)Frame * 60, 0, 60, 60));
//
//		///Shpi Movement///
//		//*
//		if (thrust) {
//			dx += cos(angle * DegToRad) * 0.3f;
//			dy += sin(angle * DegToRad) * 0.3f;
//		}
//		else { dx *= 0.99f; dy *= 0.99f; }
//
//		speed = sqrt(dx * dx + dy * dy);
//
//		if (speed > maxSpeed) {
//			dx *= maxSpeed / speed;
//			dy *= maxSpeed / speed;
//		}
//
//		//dx *= (speed > maxSpeed) * (maxSpeed / speed) + (speed <= maxSpeed);
//		//dy *= (speed > maxSpeed) * (maxSpeed / speed) + (speed <= maxSpeed);
//		x += dx; y += dy;//*/
//
//		//x = (x > W) * 0 + (x < 0) * W + (0 <= x && x <= W) * x;
//		//y = (y > H) * 0 + (y < 0) * H + (0 <= y && y <= H) * y;
//
//		if (x > W) x = 0; if (x < 0) x = W;
//		if (y > H) y = 0; if (y < 0) y = H;
//
//		sWe.setPosition(x, y);
//		sWe.setRotation(angle + 90);
//		//sFlame.setPosition(-116.5 * cos(angle * DegToRad) + x, -99 * sin(angle * DegToRad) + y);
//		//sFlame.setPosition(x,y);
//		
//
//
//		app.clear();
//		app.draw(sBack);
//		app.draw(sWe);
//		if (1) {
//			sFlame.setPosition(-80 * cos(angle * DegToRad) + x, -80 * sin(angle * DegToRad) + y);
//			sFlame.setRotation(angle + 90);
//			app.draw(sFlame);
//		}
//		app.display();
//	}
//
//
//
//
//
//
//
//	return 0;
//}
//
//
