#include "Game.h"

Game::Game()
	:window(VideoMode({1000, 600}), "YuKman's pong")
	, isRunning(true)
	, gameState(Menu)
{
	//framerateLimit
	window.setFramerateLimit(90);

	//loading textures
	if (!menu_texture.loadFromFile("assets/MenuSprite.png")) cout << "Error loading menu sprite." << endl;
	menu_sprite = make_unique<Sprite>(menu_texture);
	menu_sprite->setPosition({ 0, 100 });
	menu_sprite->setColor(Color(180, 180, 180, 180));

	if (!menu_wallpaper.loadFromFile("assets/MenuWallpaper.jpg")) cout << "Error loading wallpaper." << endl;
	menuWallpaper_sprite = make_unique<Sprite>(menu_wallpaper);
	float scale_x = 1000.0f / menu_wallpaper.getSize().x;
	float scale_y = 600.0f / menu_wallpaper.getSize().y;
	menuWallpaper_sprite->setScale({ scale_x, scale_y });
	menuWallpaper_sprite->setPosition({ 0, 0});

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
				if (play_button->isClicked(Vector2f(Mouse::getPosition(window)))) cout << "Play Test" << endl;
				else if (options_button->isClicked(Vector2f(Mouse::getPosition(window)))) cout << "Options Test" << endl;
				else if (credits_button->isClicked(Vector2f(Mouse::getPosition(window)))) cout << "Credits Test" << endl;
				else if (quit_button->isClicked(Vector2f(Mouse::getPosition(window)))) isRunning = false;
				
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
		window.draw(*menuWallpaper_sprite);
		window.draw(*menu_sprite);
		play_button->draw(window);
		options_button->draw(window);
		credits_button->draw(window);
		quit_button->draw(window);
	}

	window.display();
}