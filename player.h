#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Player() {
		texture.loadFromFile("bunny2_ready");
		sprite.setTexture(texture);
		
	}
	void update() {}
		void draw(sf::RenderWindow & window) {
			window.draw(sprite);
		}	
};
