#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#include "Ball.h"

class Player {
public:
	Player(Vector2f position, Keyboard::Scan Up, Keyboard::Scan Down);
	void goalHit(Font& font, Vector2f position, Vector2f scorePosition, Ball& ball);
	void update(float dt);
	void draw(RenderWindow& window);
	void addScore();
	FloatRect getBounds() const { return body->getGlobalBounds(); }
	FloatRect getGoalBounds() const { return goal->getGlobalBounds(); }

private:
	unique_ptr<RectangleShape> body;
	unique_ptr<RectangleShape> goal;
	unique_ptr<Text> score;

	Keyboard::Scan upKey;
	Keyboard::Scan downKey;
	Vector2f playerPos;
	Vector2f goalPos;
	int playerScore = 1;
};