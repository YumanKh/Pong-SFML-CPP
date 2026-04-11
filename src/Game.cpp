#include "Game.h"

Game::Game()
	:window(VideoMode({800, 600}), "YuKman's pong")
	, isRunning(true)
	, gameState(Menu)
{
	window.setFramerateLimit(90);
}

void Game::run() {
	Clock clock;

	while (isRunning) {
		float dt = clock.restart().asSeconds();
		handleEvents();
		update(dt);
		draw();
	}
}

void Game::handleEvents() {
	while (const optional event = window.pollEvent()) {
		if (event->is<Event::Closed>()) isRunning = false;
	}
}

void Game::update(float dt) {

}

void Game::draw() {
	if (gameState == Menu) {
		window.clear(Color::White);
	}

	window.display();
}