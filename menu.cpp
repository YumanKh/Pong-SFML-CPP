#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "prototypes.h"
using namespace sf;
using namespace std;

MenuButtons menu_buttons() {
	MenuButtons buttons;
	
	buttons.play.setSize({ 280.0f, 45.0f });
	buttons.play.setFillColor(Color::Transparent);
	buttons.play.setPosition({ 10, 150 });

	buttons.settings.setSize({ 280.0f, 45.0f });
	buttons.settings.setFillColor(Color::Transparent);
	buttons.settings.setPosition({10, 233});

	buttons.credits.setSize({ 280.0f, 45.0f });
	buttons.credits.setFillColor(Color::Transparent);
	buttons.credits.setPosition({ 10, 316 });

	buttons.quit.setSize({ 280.0f, 45.0f });
	buttons.quit.setFillColor(Color::Transparent);
	buttons.quit.setPosition({ 10, 400 });

	return buttons;
}

void draw_menu(RenderWindow& window, Font& font, Sprite &menu_sprite, MenuButtons& buttons) {
	menu_sprite.setPosition({ 0, 100 });
	menu_sprite.setColor(Color(180, 180, 180, 180));
	
	window.draw(menu_sprite);
	window.draw(buttons.play);
	window.draw(buttons.settings);
	window.draw(buttons.credits);
	window.draw(buttons.quit);
}

void mouseMenu(RenderWindow& window, Font& font, MenuButtons& buttons, Text &play_text, Text &settings_text, Text &credits_text, Text &quit_text, const Event& event) {
	Vector2f pos = Vector2f(Mouse::getPosition(window));

	
	if (const auto* mouseClick = event.getIf<Event::MouseButtonPressed>()) {
		if (buttons.play.getGlobalBounds().contains(pos)) game_state = PLAY;
		if (buttons.settings.getGlobalBounds().contains(pos)) game_state = SETTINGS;
		if (buttons.credits.getGlobalBounds().contains(pos)) game_state = CREDITS;
		if (buttons.quit.getGlobalBounds().contains(pos)) game_state = QUIT;
	}
	

	buttons.play.setFillColor(buttons.play.getGlobalBounds().contains(pos) ? Color(180, 180, 180, 180) : Color::Transparent);
	play_text.setFillColor(buttons.play.getGlobalBounds().contains(pos) ? Color::White : Color(150, 150, 150));
	
	buttons.settings.setFillColor(buttons.settings.getGlobalBounds().contains(pos) ? Color(180, 180, 180, 180) : Color::Transparent);
	settings_text.setFillColor(buttons.settings.getGlobalBounds().contains(pos) ? Color::White : Color(150, 150, 150));

	buttons.credits.setFillColor(buttons.credits.getGlobalBounds().contains(pos) ? Color(180, 180, 180, 180) : Color::Transparent);
	credits_text.setFillColor(buttons.credits.getGlobalBounds().contains(pos) ? Color::White : Color(150, 150, 150));

	buttons.quit.setFillColor(buttons.quit.getGlobalBounds().contains(pos) ? Color(180, 180, 180, 180) : Color::Transparent);
	quit_text.setFillColor(buttons.quit.getGlobalBounds().contains(pos) ? Color::White : Color(150, 150, 150));
}