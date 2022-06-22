///* 1366 x 768
//taskkill /F /IM SFML.exe
//*/
//
//#include <iostream>
//#include <list>
//#include <SFML/Graphics.hpp>
//using namespace std;
//using namespace sf;
//
//const int W = 1800;
//const int L = 1000;
//float DegToRad = 0.017453f;
//
//class Animation {
//public:
//	float frame, speed;
//	Sprite sprite;
//	std::vector<IntRect> frames;
//	Animation() { frame = 0; speed = 2; }///2 is by random///
//
//	Animation(Texture& t, int X, int Y, int Width, int Length, int Count, float Speed) {
//		frame = 0;
//		speed = Speed;
//
//		for (int c = 0; c < Count; c++) {
//			frames.push_back(IntRect(X + c * Width, Y, Width, Length));
//		}
//
//		sprite.setTexture(t);
//		sprite.setOrigin((float)(Width / 2), (float)(Length / 2));
//		sprite.setTextureRect(frames[0]);
//
//	}
//
//	void update() {
//		frame += speed;
//		int n = frames.size();
//		frame = (frame >= n) * (frame - n) + (frame < n) * frame;
//		if (n > 0) sprite.setTextureRect(frames[(int)frame]);
//	}
//
//};
//
//class Entity {
//public:
//	float x, y, dx, dy, radius, angle;
//	bool life;
//	string name;
//	Animation anim;
//
//	Entity() { life = 1; x = 1.0f; y = 1.0f; dx = 0.1f; dy = 0.1f; angle = 0.0f; radius = 1.0f; }
//
//	void setAll(Animation& a, float X, float Y, float Angle = 0.0f, float Radius = 1.0f) {
//		x = X; y = Y; angle = Angle; radius = Radius;
//		anim = a;
//	}
//
//	virtual void update() {};
//	//virtual void hit() {};
//
//	void draw(RenderWindow& app) {
//		anim.sprite.setPosition(x, y);
//		anim.sprite.setRotation(angle + 90);
//		app.draw(anim.sprite);
//	}
//
//};
//
//class Asteroids :public Entity {
//public:
//	Asteroids() {
//		dx = (float)(rand() % 3 - 1);
//		dy = (float)(rand() % 3 + 1);
//		name = "Asteroid";
//	}
//
//	void update() {
//		x += dx; y += dy;
//		if (y < 0)
//		{
//			x = (x > W) * 0 + (x <= 0) * W + (0 <= x && x <= W) * x;
//			//y = (y > L) * 0 + (y <= 0) * L + (0 <= y && y <= L) * y;
//		}
//		else if (x > (W + 85) || x<0 || y>(L + 85) || y < -550) life = 0;
//
//	}
//
//};
//
//class Bullets : public Entity {
//public:
//	Bullets() {
//		name = "Bullet";
//	}
//	void update() {
//		dx = cos(angle * DegToRad) * 6;
//		dy = sin(angle * DegToRad) * 6;
//
//		x += dx; y += dy;
//		if (x > W || x<0 || y>L || y < 0) life = 0;
//	}
//};
//
//class SpaceCraft : public Entity {
//public:
//	bool automatic;
//	float health;
//	SpaceCraft() {
//		life = 1; x = 0.1f; y = 0.1f; radius = 1; angle = -90; name = "Enemy"; automatic = 1;// health = 20;
//		dx = (float)(rand() % 8 - 4);
//		if (dx == 0)
//			if (rand() % 2 == 1) dx++; else dx--;
//		dy = (float)(rand() % 2 - 2);
//		if (dy == 0)
//			if (rand() % 2 == 1) dy++; else dy--;
//		if (dx == 0 || dy == 0) cout << "Zero Alert !!!\n";
//	}
//	friend Entity;
//	void hit(float Damage) { health -= Damage; }
//	void update() {
//
//		dx *= (x >= (W - 87) || x <= 87) * -1 + (87 < x && x < (W - 87)) * 1; //87 is half-width  of jet
//		dy *= (y >= (L - 99 - 444) || y <= 99) * -1 + (99 < y && y < (L - 99 - 444)) * 1; //99 is half-height of jet //can't go beyond 
//
//		x += dx; y += dy;
//
//		/*x = (x > W) * 0 + (x <= 0) * W + (0 <= x && x <= W) * x;
//		y = (y > L) * 0 + (y <= 0) * L + (0 <= y && y <= L) * y;*/
//		/*x += (x > W || x <= 0) * -dx + (0 <= x && x <= W) * dx;
//		y += (y > L || y <= 0) * -dy + (0 <= y && y <= L) * dy;*/
//	}
//};
//
//bool isCollide(Entity* a, Entity* b) {
//	return (b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y) < (a->radius + b->radius) * (a->radius + b->radius);
//}
//
//
//int main() {
//
//	int maxSpeed = 10;
//	float x = W / 2, y = L - 130, dx = 0, dy = 0, angle = -90;
//	bool thrust = 0;
//	srand(time(NULL));
//
//	RenderWindow app(VideoMode(W, L), "Test");
//	app.setFramerateLimit(60);
//
//	Texture t1, t2, t3, t4, t5, t6;
//	t1.loadFromFile("Background/Back-1.png");
//	t2.loadFromFile("Jet/We-2.png");
//	t3.loadFromFile("Flame-1.png");
//	t4.loadFromFile("Asteroids/Gery-3-Animation.png");
//	t5.loadFromFile("Bullet-Yellow.png");
//	t6.loadFromFile("Jet/Jet-4.png");
//
//
//	Sprite sBack(t1), sWe(t2), sFlame(t3);
//	sWe.setOrigin(116.5, 99);
//
//	Animation sAsteroid(t4, 0, 0, 154, 154, 16, 0.2f);
//	Animation sBullet(t5, 0, 0, 30, 63, 1, 0.1f);
//	Animation sEnemy(t6, 0, 0, 198, 173, 1, 0.1f);
//
//	list<Entity*> entities;
//	/*for (int c = 0; c < 50; c++) {
//		Asteroids* a = new Asteroids();
//		a->setAll(sAsteroid, (float)(rand() % W), -(float)(rand() % 500), rand() % 360, 25.0f);
//		float sss = ((float)(rand() % 50 + 40)) / 100;
//		a->anim.sprite.setScale(sss, sss);
//		entities.push_back(a);
//	}*/
//
//	for (int c = 0; c < 8; c++) {
//		SpaceCraft* s = new SpaceCraft();
//		s->setAll(sEnemy, (float)(rand() % (W - 87 - 87) + 87), (float)(rand() % (L - 99 - 99 - 450) + 99), 0, 20);
//		entities.push_back(s);
//	}
//
//	float frame = 0, animationSpeed = 0.27f;
//	int frameCount = 20;
//	sFlame.setOrigin((float)(30 + (int)frame * 60), 0);
//
//
//	while (app.isOpen()) {
//		Event eve;
//		while (app.pollEvent(eve)) {
//			if (eve.type == eve.Closed) app.close();
//			//*
//			if (eve.type == eve.KeyPressed)
//				if (eve.key.code == Keyboard::Space) {
//					Bullets* b = new Bullets();
//					b->setAll(sBullet, x, y, angle, 30);
//					entities.push_back(b);
//				}//*/
//		}
//
//		///Animation Example///
//
//		frame += animationSpeed;
//		frame = (frame > frameCount) * (frame - frameCount) + (frame <= frameCount) * frame;
//		sFlame.setTextureRect(IntRect(int(frame) * 60, 0, 60, 60));
//
//		if (Keyboard::isKeyPressed(Keyboard::Right))   /*x += 10;*/angle += 1.5;
//		if (Keyboard::isKeyPressed(Keyboard::Left))    /*x -= 10;*/angle -= 1.5;
//		//if (Keyboard::isKeyPressed(Keyboard::Up))	   y -= 10;
//		if (Keyboard::isKeyPressed(Keyboard::Down))    y += 10;
//		if (Keyboard::isKeyPressed(Keyboard::Up)) thrust = true; else thrust = false;
//		/*
//		if (Keyboard::isKeyPressed(Keyboard::Space)) {
//			Bullets* b = new Bullets;
//			b->setAll(sBullet, x, y, angle, 30);
//			entities.push_back(b);
//		}//*/
//
//		for (auto e : entities)
//			for (auto f : entities)
//				if (e->name == "Asteroid" && f->name == "Bullet")
//					if (isCollide(e, f)) { e->life = 0; f->life = 0; }
//					else;
//				else if (e->name == "Enemy" && f->name == "Bullet")
//					if (isCollide(e, f)) { e->life = 0; f->life = 0; }
//					else;
//				else if (e->name == "Asteroid" && f->name == "Enemy")
//					if (isCollide(e, f)) { e->life = 0; f->life = 0; }
//					else;
//		//else if (e->name == "Enemy" && f->name == "Asteroid") if (isCollide(e, f)) { e->life = 0; f->life = 0; } else;
//
/////spaceship movement///
//
//		if (thrust)
//		{
//			dx += cos(angle * DegToRad) * 0.5f;
//			dy += sin(angle * DegToRad) * 0.5f;
//		}
//		else {
//			dx *= 0.99f;
//			dy *= 0.99f;
//		}
//		float speed = sqrt(dx * dx + dy * dy);
//
//		if (speed > maxSpeed) {
//			dx *= maxSpeed / speed;
//			dy *= maxSpeed / speed;
//		}
//
//		x += dx; y += dy;
//
//		//x = (x > W) * 0 + (x <= 0) * W + (0 <= x && x <= W) * x;
//		//y = (y > L) * 0 + (y <= 0) * L + (0 <= y && y <= L) * y;
//
//		if (x > W) x = 0; if (x < 0) x = W;
//		if (y > L) y = 0; if (y < 0) y = L;
//		sWe.setPosition(x, y);
//		sWe.setRotation(angle + 90);
//
//		for (auto c = entities.begin(); c != entities.end();) {
//			Entity* e = *c;
//			//if (e->name == "Enemy") e->anim.sprite.setRotation(e->angle - 90);
//			e->update();
//			e->anim.update();
//
//			if (e->life == 0) {
//				c = entities.erase(c);
//				delete e;
//			}
//			else c++;
//		}
//
//		///draw///
//		app.clear();
//		app.draw(sBack);
//		if (thrust) {
//			sFlame.setPosition(-80 * cos(angle * DegToRad) + x, -80 * sin(angle * DegToRad) + y);
//			sFlame.setRotation(angle + 90);
//			app.draw(sFlame);
//		}
//		for (auto d : entities) d->draw(app);
//		app.draw(sWe);
//		app.display();
//
//	}
//
//	return 0;
//}