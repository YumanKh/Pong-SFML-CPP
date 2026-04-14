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

void Player::goalHit(Font& font, Vector2f position, Vector2f scorePosition, Ball& ball){
	goalPos = position;
	int scr = 0;
	score = make_unique<Text>(font, to_string(scr), 35);
	score->setPosition(scorePosition);

	goal = make_unique<RectangleShape>();
	goal->setSize({ 50.f, 250.f });
	goal->setFillColor(Color::Red);
	goal->setPosition(goalPos);
}

void Player::update(float dt) {
	Vector2f velocity = { 0.f, 0.f };
	if (Keyboard::isKeyPressed(upKey)) velocity.y -= 300;
	if (Keyboard::isKeyPressed(downKey)) velocity.y += 300;

	body->move(velocity * dt);

	if (body->getPosition().y <= 18.75f)
		body->setPosition({ body->getPosition().x, 18.75f });
	if (body->getPosition().y >= 531.25)
		body->setPosition({ body->getPosition().x, 531.25 });
}

void Player::addScore() {
	playerScore++;
	score->setString(to_string(playerScore));
}

void Player::draw(RenderWindow& window) {
	window.draw(*body);
	window.draw(*score);
	window.draw(*goal);
}