#pragma once
#include "OOP_Animation.h"
#include "OOP_Entity.h"
#include "OOP_Asteroids.h"
#include "OOP_Bullets.h"
#include "OOP_SpaceCraft.h"
#include "OOP_Boss.h"
#include "OOP_We.h"


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