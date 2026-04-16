#include "Game.h"

Game::Game()
	:window(VideoMode({1000, 600}), "YuKman's pong")
	, isRunning(true)
	, gameState(Menu)
{
	//framerateLimit
	window.setFramerateLimit(90);

	//loading textures
	//buttons table
	if (!menu_texture.loadFromFile("assets/MenuSprite.png")) cout << "Error loading menu sprite." << endl;
	menu_sprite = make_unique<Sprite>(menu_texture);
	menu_sprite->setPosition({ 0, 100 });
	menu_sprite->setColor(Color(180, 180, 180, 180));

	//menu wallpaper
	if (!menu_wallpaper.loadFromFile("assets/MenuWallpaper.jpg")) cout << "Error loading wallpaper." << endl;
	menuWallpaper_sprite = make_unique<Sprite>(menu_wallpaper);
	float scale_x = 1000.0f / menu_wallpaper.getSize().x;
	float scale_y = 600.0f / menu_wallpaper.getSize().y;
	menuWallpaper_sprite->setScale({ scale_x, scale_y });
	menuWallpaper_sprite->setPosition({ 0, 0});

	//terrain textures
	if (!terrain_texture.loadFromFile("assets/TerrainSprite.png")) cout << "Error loading terrain." << endl;
	terrain_sprite = make_unique<Sprite>(terrain_texture);
	terrain_sprite->setScale({ 25.f, 18.75f });
	float posX = (1000.f - terrain_sprite->getGlobalBounds().size.x) / 2.f;
	terrain_sprite->setPosition({ posX, 0.f });

	if (!line_texture.loadFromFile("assets/TerrainLine.png")) cout << "Error loading terrain." << endl;
	line_sprite = make_unique<Sprite>(line_texture);
	line_sprite->setScale({ 18.75f , 18.75f });
	line_sprite->setScale({ 18.75f, 18.75f });
	float linePosX = (1000.f - line_sprite->getGlobalBounds().size.x) / 2.f + (line_sprite->getGlobalBounds().size.x / 2.f) - (18.75f / 2.f);
	line_sprite->setPosition({ linePosX, 0.f });

	//font loading
	if (!font.openFromFile("assets/BlackGameFont.ttf")) cout << "Error loading font." << endl;

	//buttons
	play_button = make_unique<Button>(font, "PLAY", Vector2f{ 30, 150 }, Vector2f{ 10, 150 }, Vector2f{ 280.0f, 45.0f });
	options_button = make_unique<Button>(font, "OPTIONS", Vector2f{ 30, 233 }, Vector2f{ 10, 233 }, Vector2f{ 280.0f, 45.0f });
	credits_button = make_unique<Button>(font, "CREDITS", Vector2f{ 30, 316 }, Vector2f{ 10, 316 }, Vector2f{ 280.0f, 45.0f });
	quit_button = make_unique<Button>(font, "QUIT", Vector2f{ 30, 400 }, Vector2f{ 10, 400 }, Vector2f{ 280.0f, 45.0f });

	//players
	player_1 = make_unique<Player>(Vector2f(840.f, 250.f), Keyboard::Scan::Up, Keyboard::Scan::Down);
	player_2 = make_unique<Player>(Vector2f(150.f, 250.f), Keyboard::Scan::W, Keyboard::Scan::S);

	//ball
	ball = make_unique<Ball>(Vector2f({ 495.f, 295.f }));

	//goals
	player_1->goalHit(font, Vector2f(890.f, 187.5f), Vector2f(750.f, 20.f), *ball);
	player_2->goalHit(font, Vector2f(60.f, 187.5f), Vector2f(200.f, 20.f), *ball);

	//sound effects
	goalBuffer = make_unique<SoundBuffer>();
	if (!goalBuffer->loadFromFile("assets/goal.ogg")) cout << "Error loading sound." << endl;
	goalSound = make_unique<Sound>(*goalBuffer);
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
				if (play_button->isClicked(Vector2f(Mouse::getPosition(window)))) gameState = Playing;
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
	
	if (gameState == Playing) {
		player_1->update(dt);
		player_2->update(dt);
		ball->update(dt, *player_1, *player_2);
		if (ball->getBounds().findIntersection(player_1->getGoalBounds())) {
			goalSound->play();
			player_2->addScore();
			ball->reset(Vector2f(495.f, 295.f));
		}
		else if (ball->getBounds().findIntersection(player_2->getGoalBounds())) {
			goalSound->play();
			player_1->addScore();
			ball->reset(Vector2f(495.f, 295.f));
		}
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

	if (gameState == Playing) {
		window.clear(Color::Black);
		window.draw(*line_sprite);
		window.draw(*terrain_sprite);
		player_1->draw(window);
		player_2->draw(window);
		ball->draw(window);
		
		
	}

	window.display();
}