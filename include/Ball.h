#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

class Player;

class Ball {
public:
	Ball(Vector2f position);
	void update(float dt, Player& player1, Player& player2);
	void draw(RenderWindow& window);
	void reset(Vector2f position);
	FloatRect getBounds() const { return ball->getGlobalBounds(); }
	void setScored() { justScored = true; scoreDelay = 0.5f; }

private:
	unique_ptr<RectangleShape> ball;
	Vector2f ballPos;
	Vector2f velocity;
	bool justScored = false;
	float scoreDelay = 0.f;
};