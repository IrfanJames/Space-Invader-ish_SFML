#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

int W = 1800;
int L = 1000;
float DegToRad = 0.017453f;

bool menu = 0;

const int TotalLives = 2;	// Tries
int maxSpeed = 10;	// max speed of our jet
bool thrust = 0;	// will our jet have accleration-1 or not-0
int asteroidNum = 30;	// to be global
int enemyNum = 8;	// to be global
int arrEnemy[4] = { 1,1,2,4 };	// how much of each type of enemy jets

bool Gray0OrPink1 = 1;	// Color of Asteroids
int Background1_6 = 2;	//bg 1-6
int BOSS1_6 = 1;		//boss 1-6

float defaultEnemyLife = 10.0f;
float defaultBossLife = 77.0f;
const int totalLevels = 6;

int noOfBossBullets = 5;
int asteroidTime = 10;	// Seconds after which asterois will come
int bossTime = enemyNum - (rand() % 3 + 1);

void levelUP(int Level) {

	switch (Level) {
	case 1:
		arrEnemy[0] = 8; arrEnemy[1] = 0; arrEnemy[2] = 0; arrEnemy[3] = 0;
		Gray0OrPink1 = 0;
		Background1_6 = 1;
		BOSS1_6 = 1;
		asteroidTime = rand() % 4 + 11;
		bossTime = enemyNum - (rand() % 3 + 1);
		noOfBossBullets = 4;
		break;
	case 2:
		arrEnemy[0] = 4; arrEnemy[1] = 4; arrEnemy[2] = 0; arrEnemy[3] = 0;
		Gray0OrPink1 = 1;
		Background1_6 = 2;
		BOSS1_6 = 2;
		asteroidTime = rand() % 5 + 11;
		bossTime = enemyNum - (rand() % 3 + 1);
		noOfBossBullets = 5;
		break;
	case 3:
		arrEnemy[0] = 1; arrEnemy[1] = 5; arrEnemy[2] = 2; arrEnemy[3] = 0;
		Gray0OrPink1 = 0;
		Background1_6 = 3;
		BOSS1_6 = 3;
		asteroidTime = rand() % 3 + 19;
		bossTime = enemyNum - (rand() % 3 + 1);
		noOfBossBullets = 5;
		break;
	case 4:
		arrEnemy[0] = 0; arrEnemy[1] = 3; arrEnemy[2] = 4; arrEnemy[3] = 1;
		Gray0OrPink1 = 0;
		Background1_6 = 4;
		BOSS1_6 = 4;
		asteroidTime = rand() % 4 + 13;
		bossTime = enemyNum - (rand() % 3 + 1);
		noOfBossBullets = 6;
		break;
	case 5:
		arrEnemy[0] = 0; arrEnemy[1] = 2; arrEnemy[2] = 3; arrEnemy[3] = 3;
		Gray0OrPink1 = 1;
		Background1_6 = 5;
		BOSS1_6 = 5;
		asteroidTime = rand() % 4 + 12;
		bossTime = enemyNum - (rand() % 3 + 1);
		noOfBossBullets = 7;
		break;
	case 6:
		arrEnemy[0] = 0; arrEnemy[1] = 0; arrEnemy[2] = 2; arrEnemy[3] = 6;
		Gray0OrPink1 = 1;
		Background1_6 = 6;
		BOSS1_6 = 6;
		asteroidTime = rand() % 5 + 10;
		noOfBossBullets = 8;
		break;
	default :
		arrEnemy[0] = 1; arrEnemy[1] = 1; arrEnemy[2] = 2; arrEnemy[3] = 4;
		Gray0OrPink1 = 0;
		Background1_6 = 1;
		BOSS1_6 = 1;
		asteroidTime = rand() % 3 + 9;
		noOfBossBullets = 5;
		break;
	}


}


class Animation {
public:
	float frame, speed;
	Sprite sprite;
	std::vector<IntRect> frames;
	Animation() { frame = 0; speed = 2; }///2 is by random///

	Animation(Texture& t, int X, int Y, int Width, int Length, int Count, float Speed) {
		frame = 0;
		speed = Speed;

		for (int c = 0; c < Count; c++) {
			frames.push_back(IntRect(X + c * Width, Y, Width, Length));
		}

		sprite.setTexture(t);
		sprite.setOrigin((float)(Width / 2), (float)(Length / 2));
		sprite.setTextureRect(frames[0]);

	}

	void setAll(Texture& t, int X, int Y, int Width, int Length, int Count, float Speed) {
		frame = 0;
		speed = Speed;

		for (int c = 0; c < Count; c++) {
			frames.push_back(IntRect(X + c * Width, Y, Width, Length));
		}

		sprite.setTexture(t);
		sprite.setOrigin((float)(Width / 2), (float)(Length / 2));
		sprite.setTextureRect(frames[0]);

	}

	void update() {
		frame += speed;
		int n = frames.size();
		frame = (frame >= n) * (frame - n) + (frame < n) * frame;
		if (n > 0) sprite.setTextureRect(frames[(int)frame]);
	}

};
