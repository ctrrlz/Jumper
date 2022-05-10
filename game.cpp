#include "game.h"

Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Jumper"),
	p1(0, WINDOW_HEIGHT - 55.f, WINDOW_WIDTH, 55.f)
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
	p1.update();
}
void Game::draw() {
	window.clear();
	player.draw(window);
	p1.draw(window);
	window.display();
}
void Game::check_collisions() {
	if (player.getHitBox().intersects(p1.getHitBox())) {
		player.setIsJumping(false);
		player.restSpeed();
		sf::Vector2f pos = p1.getPosition();
		sf::Vector2f player_new_pos = sf::Vector2f(player.getPosition().x,pos.y-player.getHitBox().height-1.f);
		player.setPosition(player_new_pos);
	}
}
