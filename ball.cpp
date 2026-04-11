#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "prototypes.h"
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;

Ball create_ball() {
	Ball b;
	b.body.setRadius(10);
	b.body.setFillColor(Color(128, 0, 128));
	b.body.setOutlineColor(Color::Black);
	b.body.setOutlineThickness(2.0f);
	b.body.setPosition({ 490.f, 290.f });

	return b;
}

void ball_movement(Ball &ball, float deltaTime, Player &player_1, Player &player_2, Score_Hitbox &hb1, Score_Hitbox &hb2) {
	static int probs_x = (rand() % 2);
	static float y_angle = (rand() % 11);
	static float direction_x = (probs_x == 0) ? 1.0f : -1.f;
	static float direction_y = 1.0f;

	Vector2f pos = ball.body.getPosition();
	pos.x += (300.0f * direction_x) * (deltaTime * 1.15);
	pos.y += ((25.0f * y_angle) * direction_y) * deltaTime;
	probs_x = 2;
	ball.body.setPosition(pos);
	
	if (ball.body.getGlobalBounds().findIntersection(player_1.body.getGlobalBounds())) {
		direction_x = direction_x * -1.0f;
		direction_y = direction_y * (rand() % 2 == 0) ? - 1.0f : 1.0f;
	}
	else if (ball.body.getGlobalBounds().findIntersection(player_2.body.getGlobalBounds())) {
		direction_x = direction_x * -1.0f;
		direction_y = direction_y * (rand() % 2 == 0) ? -1.0f : 1.0f;
	}

	if (ball.body.getGlobalBounds().findIntersection(hb1.score_body.getGlobalBounds())) {
		hb1.score++;
		ball.body.setPosition({ 490.f, 290.f });
		direction_x = 1.0f;
		probs_x = rand() % 2;
	}
	else if (ball.body.getGlobalBounds().findIntersection(hb2.score_body.getGlobalBounds())) {
		hb2.score++;
		ball.body.setPosition({ 490.f, 290.f });
		direction_x = -1.0f;
		probs_x = rand() % 2;
	}
	if (ball.body.getPosition().y <= 0 || ball.body.getPosition().y >= 580) direction_y = direction_y * -1.0f;
	
}