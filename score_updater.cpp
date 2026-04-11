#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "prototypes.h"
using namespace sf;
using namespace std;

Score_Hitbox create_score_hitbox(Vector2f position) {
	Score_Hitbox sh;
	sh.score_body.setSize({ 10.0f, 600.0f });
	sh.score_body.setFillColor(Color::Transparent);
	sh.score_body.setOutlineColor(Color::Transparent);
	sh.score_body.setOutlineThickness(1.0f);
	sh.score_body.setPosition(position);
	return sh;
}

Score_Display create_score_display(Font& font, Vector2f position, Ball &ball, Score_Hitbox &score_hitbox) {
	static int score = 0;
	Score_Display s = {Text(font, "00", 50)};
	s.score_text.setFillColor(Color::Black);
	s.score_text.setPosition(position);

	return s;
}

void update_score(Score_Display &score_display, Ball &ball, Score_Hitbox &score_hitbox) {
	score_display.score_text.setString(to_string(score_hitbox.score));
}