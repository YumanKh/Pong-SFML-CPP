#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

#include "Player.h"

class Ball {
public:
	Ball(Vector2f position);
	void update(float dt, Player& player1, Player& player2);
	void draw(RenderWindow& window);

private:
	unique_ptr<RectangleShape> ball;
	Vector2f ballPos;
	Vector2f velocity;
};