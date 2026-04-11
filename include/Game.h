#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

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
};