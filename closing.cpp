#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "prototypes.h"
using namespace sf;
using namespace std;

QuitButtons quit_buttons() {
	QuitButtons q_buttons;

	q_buttons.deny.setSize({ 300.0f, 45.0f });
	q_buttons.deny.setFillColor(Color::Transparent);
	q_buttons.deny.setPosition({ 350, 215 });

	q_buttons.confirm.setSize({ 300.0f, 45.0f });
	q_buttons.confirm.setFillColor(Color::Transparent);
	q_buttons.confirm.setPosition({ 350, 360 });

	return q_buttons;
}


void draw_closing(RenderWindow& window, Font& font, Sprite& menu_quit, QuitButtons& q_buttons) {
	menu_quit.setPosition({ 300, 100 });
	menu_quit.setColor(Color(180, 180, 180, 180));

	window.draw(menu_quit);
	window.draw(q_buttons.confirm);
	window.draw(q_buttons.deny);
}

void mouseMenu(RenderWindow& window, Font& font, QuitButtons& q_buttons, Text& deny_text, Text& confirm_text, const Event& event) {
	Vector2f pos = Vector2f(Mouse::getPosition(window));

	if (const auto* mouseClick = event.getIf<Event::MouseButtonPressed>()) {
		if (q_buttons.deny.getGlobalBounds().contains(pos)) game_state = MENU;
		if (q_buttons.confirm.getGlobalBounds().contains(pos)) window.close();
	}

	q_buttons.confirm.setFillColor(q_buttons.confirm.getGlobalBounds().contains(pos) ? Color(180, 180, 180, 180) : Color::Transparent);
	confirm_text.setFillColor(q_buttons.confirm.getGlobalBounds().contains(pos) ? Color::White : Color(150, 150, 150));

	q_buttons.deny.setFillColor(q_buttons.deny.getGlobalBounds().contains(pos) ? Color(180, 180, 180, 180) : Color::Transparent);
	deny_text.setFillColor(q_buttons.deny.getGlobalBounds().contains(pos) ? Color::White : Color(150, 150, 150));
}


void closing(RenderWindow& window, const Event& event) {
	if (event.is<Event::Closed>()) window.close();

	if (const auto* keyPressed = event.getIf<Event::KeyPressed>()) {
		if (keyPressed->scancode == Keyboard::Scan::Escape) {
			if (game_state == PLAY) game_state = MENU;
			else if (game_state == CREDITS) game_state = MENU;
			else if (game_state == SETTINGS) game_state = MENU;
			else if (game_state == QUIT) game_state = MENU;
			else if (game_state == MENU) game_state = QUIT;
		}
	}
}