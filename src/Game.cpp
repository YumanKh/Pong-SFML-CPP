#include "Game.h"

Game::Game()
	:window(VideoMode({1000, 600}), "YuKman's pong")
	, isRunning(true)
	, gameState(Menu)
{
	//framerateLimit
	window.setFramerateLimit(90);

	//loading textures
	menu_texture.loadFromFile("assets/MenuSprite.png");
	menu_sprite = make_unique<Sprite>(menu_texture);
	menu_sprite->setPosition({ 0, 100 });
	menu_sprite->setColor(Color(180, 180, 180, 180));

	//font loading
	if (!font.openFromFile("assets/BlackGameFont.ttf")) cout << "Error loading font." << endl;

	//buttons
	play_button = make_unique<Button>(font, "PLAY", Vector2f{ 30, 150 }, Vector2f{ 10, 150 }, Vector2f{ 280.0f, 45.0f });
	options_button = make_unique<Button>(font, "OPTIONS", Vector2f{ 30, 233 }, Vector2f{ 10, 233 }, Vector2f{ 280.0f, 45.0f });
	credits_button = make_unique<Button>(font, "CREDITS", Vector2f{ 30, 316 }, Vector2f{ 10, 316 }, Vector2f{ 280.0f, 45.0f });
	quit_button = make_unique<Button>(font, "QUIT", Vector2f{ 30, 400 }, Vector2f{ 10, 400 }, Vector2f{ 280.0f, 45.0f });

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
		if (gameState == Menu) {
			if (event->is<Event::MouseButtonPressed>()) {
				if (play_button->isClicked(Vector2f(Mouse::getPosition(window)))) {
					cout << "Play Test" << endl;
				}
			}
		}
	}
}

void Game::update(float dt) {
	if (gameState == Menu) {
		play_button->update(window);
		options_button->update(window);
		credits_button->update(window);
		quit_button->update(window);
	}
	

}

void Game::draw() {
	if (gameState == Menu) {
		window.clear(Color::White);
		window.draw(*menu_sprite);
		play_button->draw(window);
		options_button->draw(window);
		credits_button->draw(window);
		quit_button->draw(window);
	}

	window.display();
}