#include "Ball.h"
#include "Player.h"

Ball::Ball(Vector2f position) {
	ballPos = position;

	srand(time(0));
	int dirX = (rand() % 2 == 0) ? 1 : -1;
	int dirY = (rand() % 2 == 0) ? 1 : -1;

	velocity = { 300.f * dirX, 300.f * dirY };

	ball = make_unique<RectangleShape>();
	ball->setSize({ 10.f, 10.f });
	ball->setFillColor(Color::White);
	ball->setPosition(position);

	hitBuffer = make_unique<SoundBuffer>();
	if (!hitBuffer->loadFromFile("assets/ball.ogg")) cout << "Error loading sound." << endl;
	hitSound = make_unique<Sound>(*hitBuffer);
}

void Ball::update(float dt, Player& player1, Player& player2) {
	ball->move(velocity * dt);

	//player collision
	if (ball->getGlobalBounds().findIntersection(player1.getBounds())) {
		velocity.x *= -1;
		hitSound->play();
			
	}
	if (ball->getGlobalBounds().findIntersection(player2.getBounds())) {
		velocity.x *= -1;
		hitSound->play();
	}

	//walls collision (goal walls)
	if (ball->getPosition().x <= 125.f && ball->getPosition().y <= 187.5f)
		velocity.x *= -1;
	if (ball->getPosition().x <= 125.f && ball->getPosition().y >= 412.5f)
		velocity.x *= -1;
	if (ball->getPosition().x >= 865.f && ball->getPosition().y <= 187.5f)
		velocity.x *= -1;
	if (ball->getPosition().x >= 865.f && ball->getPosition().y >= 412.5f)
		velocity.x *= -1;

	//walls collision (top and bottom walls)
	if (ball->getPosition().y <= 18.75f) velocity.y *= -1;
	if (ball->getPosition().y >= 571.25) velocity.y *= -1;
}

void Ball::reset(Vector2f position) {
	ball->setPosition(position);
}

void Ball::draw(RenderWindow& window) {
	window.draw(*ball);
}