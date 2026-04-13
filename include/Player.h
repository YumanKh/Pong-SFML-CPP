#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Player {
public:
	Player(Vector2f position, Keyboard::Scan Up, Keyboard::Scan Down);
	void scoreUpdater(Text& score, Vector2f position, Vector2f size);
	void update(float dt);
	void draw(RenderWindow& window);

private:
	unique_ptr<RectangleShape> body;
	unique_ptr<RectangleShape> score_updater;
	unique_ptr<Text> score;

	Keyboard::Scan upKey;
	Keyboard::Scan downKey;
	Vector2f playerPos;
};