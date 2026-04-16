#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

#include "Button.h"
#include "Player.h"
#include "Ball.h"

enum GameState {
	Menu,
	Settings,
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

	//BUTTONS & TEXTS
	Font font;
	
	//menu buttons
	unique_ptr<Button> play_button;
	unique_ptr<Button> options_button;
	unique_ptr<Button> credits_button;
	unique_ptr<Button> quit_button;

	//settings button
	unique_ptr<Button> on_button;
	unique_ptr<Button> off_button;
	//settings text
	unique_ptr<Button> sound_text;

	//menu textures
	Texture menu_texture;
	unique_ptr<Sprite> menu_sprite;

	Texture menu_texture_2;
	unique_ptr<Sprite> menu_sprite_2;

	Texture menu_wallpaper;
	unique_ptr<Sprite> menuWallpaper_sprite;

	Texture terrain_texture;
	unique_ptr<Sprite> terrain_sprite;

	Texture line_texture;
	unique_ptr<Sprite> line_sprite;

	//players
	unique_ptr<Player> player_1;
	unique_ptr<Player> player_2;
	//ball
	unique_ptr<Ball> ball;

	//sounds
	bool soundOn = true;
	unique_ptr<SoundBuffer> goalBuffer;
	unique_ptr<Sound> goalSound;
	unique_ptr<SoundBuffer> buttonBuffer;
	unique_ptr<Sound> buttonSound;

};