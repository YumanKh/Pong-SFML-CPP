#include "Player.h"

Player::Player(Vector2f position, Keyboard::Scan Up, Keyboard::Scan Down) {
	playerPos = position;
	upKey = Up;
	downKey = Down;

	body = make_unique <RectangleShape>();
	body->setSize({ 10.f, 50.f });
	body->setFillColor(Color::White);
	body->setPosition(playerPos);
}

void Player::scoreUpdater(Vector2f position, Text& score, Vector2f size) {
}

void Player::update(float dt) {
	Vector2f velocity = { 0.f, 0.f };
	if (Keyboard::isKeyPressed(upKey)) velocity.y -= 300;
	if (Keyboard::isKeyPressed(downKey)) velocity.y += 300;
	body->move(velocity * dt);
}

void Player::draw(RenderWindow& window) {
	if (!body) {
		cout << "Body is null" << endl;
	}
	window.draw(*body);
}