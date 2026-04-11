#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "prototypes.h"
using namespace sf;
using namespace std;

Player create_player(Vector2f position, Color color) {
	Player p;
	p.body.setSize({15.0f, 80.0f});
	p.body.setFillColor(color);
	p.body.setOutlineColor(Color::Black);
	p.body.setOutlineThickness(2.0f);
	p.body.setPosition(position);

	return p;
}

//scores


//controls
void control(Player& player, Keyboard::Scan up, Keyboard::Scan down, float deltaTime) {
	Vector2f pos = player.body.getPosition();

	if (Keyboard::isKeyPressed(up)) pos.y -= 300.f * deltaTime;
	if (Keyboard::isKeyPressed(down)) pos.y += 300.f * deltaTime;

	player.body.setPosition(pos);
}

