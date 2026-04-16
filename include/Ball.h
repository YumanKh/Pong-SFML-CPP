#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

class Player;

class Ball {
public:
	Ball(Vector2f position);
	void update(float dt, Player& player1, Player& player2, bool soundOn);
	void draw(RenderWindow& window);
	void reset(Vector2f position);
	FloatRect getBounds() const { return ball->getGlobalBounds(); }

private:
	unique_ptr<RectangleShape> ball;
	Vector2f ballPos;
	Vector2f velocity;

	unique_ptr<SoundBuffer> hitBuffer;
	unique_ptr<Sound> hitSound;
};