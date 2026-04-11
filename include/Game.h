#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#include "Button.h"

enum GameState {
	Menu,
	Playing,
};


class Game {
public:
	Game();
	void run();

private:
	void handleEvents();
	void update(float dt);
	void draw();

	bool isRunning;
	RenderWindow window;
	GameState gameState;

	//buttons
	Font font;

	unique_ptr<Button> play_button;
	unique_ptr<Button> options_button;
	unique_ptr<Button> credits_button;
	unique_ptr<Button> quit_button;

	//menu textures
	Texture menu_texture;
	unique_ptr<Sprite> menu_sprite;
};