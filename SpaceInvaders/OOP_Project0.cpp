/*
taskkill /F /IM OOP_Project.exe
*/
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#define Width 1800
#define Length 1000
#define Rows 10;
#define Cols 18;

int totalShooters = 0;

class Shooter {
    int x;
    int y;
    float health;
    float sheild;
    int lives;
public:
    Shooter() {
        x = ++totalShooters*25;
        y = 100;
        health = 10;
        sheild = 0.0;
        lives = 1;
    }
    Shooter(int X, int Y, float Health, float Sheild, int Lives) {
        x = X;
        y = Y;
        health = Health;
        sheild = Sheild;
        lives = Lives;
    }
    void getInfo() {
        cout << "X:\t" << x << endl;
        cout << "Y:\t" << y << endl;
        cout << "Health: " << health << endl;
        cout << "Sheild: " << sheild << endl;
        cout << "Lives:  " << lives << endl;
        cout << endl;
    }

    int xPosition() {
        return (x * Width) / Cols;
    }
    int yPosition() {
        return (y * Length) / Rows;
    }

    void setX(int X) {
        x = X;
    }
    
    void setY(int Y) {
        y = Y;
    }
    
    void setHealth(float Health) {
        health = Health;
    }
    float getHealth() {
        return health;
    }
    void setSheild(float Sheild) {
        sheild = Sheild;
    }
    float getSheild() {
        return sheild;
    }
    void setLives(int Lives) {
        lives = Lives;
    }
    int getLives() {
        return lives;
    }
};

int main() {

    Shooter Me(9, 8, 100, 0.0, 4);


	sf::Texture Background;
	if (!Background.loadFromFile("Back-1.png"))
		return 78;
	sf::Sprite still(Background);
	still.setPosition(0, 0);

    

	sf::Texture fristPic;
	if (!fristPic.loadFromFile("We-2.png"))
		return 87;
    sf::Sprite sprite(fristPic);
    sprite.setPosition(Me.xPosition()-233/2, Me.yPosition()-198/2);

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
		
        sf::Texture Boss;
        if (!Boss.loadFromFile("Boss-4.png"))
            return 66;
        sf::Sprite mega(Boss);
        mega.setPosition(Width / 2 - 828 / 2, 30);

		window.clear(sf::Color::Transparent);
		window.draw(still);
        window.draw(mega);
		window.draw(sprite);
        window.display();

	}

    system("pause");
}
