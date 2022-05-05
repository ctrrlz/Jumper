#include "game.h"

Game::Game() :
	window(sf::VideoMode(800, 600), "Test")
{
	window.setVerticalSyncEnabled(true);
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
void Game::update() {
	player.update();
}
void Game::draw() {
	window.clear();
	player.draw(window);
	window.display();
}
void Game::check_collisions() {}
