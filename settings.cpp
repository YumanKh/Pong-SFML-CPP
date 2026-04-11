#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "prototypes.h"
using namespace sf;
using namespace std;

SettingsButtons settings_buttons() {
	SettingsButtons s_buttons;

	s_buttons.on.setSize({ 65.0f, 40.0f });
	s_buttons.on.setFillColor(Color::Transparent);
	s_buttons.on.setPosition({ 380, 225 });

	s_buttons.off.setSize({ 65.0f, 40.0f });
	s_buttons.off.setFillColor(Color::Transparent);
	s_buttons.off.setPosition({ 555, 225 });

	s_buttons.fps30.setSize({ 65.0f, 40.0f });
	s_buttons.fps30.setFillColor(Color::Transparent);
	s_buttons.fps30.setPosition({ 380, 375 });

	s_buttons.fps60.setSize({ 64.0f, 40.0f });
	s_buttons.fps60.setFillColor(Color::Transparent);
	s_buttons.fps60.setPosition({ 555, 375 });

	return s_buttons;
}

void draw_settings(RenderWindow& window, Font& font, Sprite& menu_settings, SettingsButtons &s_buttons) {
	menu_settings.setPosition({ 300, 100 });
	menu_settings.setColor(Color(180, 180, 180, 180));

	window.draw(menu_settings);
	window.draw(s_buttons.on);
	window.draw(s_buttons.off);
	window.draw(s_buttons.fps30);
	window.draw(s_buttons.fps60);
}

void mouseSettings(RenderWindow& window, Font& font, SettingsButtons& s_buttons, Text& on_text, Text& off_text, Text& fps30_text, Text& fps60_text, const Event& event, int &volume_setting, int &frame_setting) {
	Vector2f pos = Vector2f(Mouse::getPosition(window));


	if (const auto* mouseClick = event.getIf<Event::MouseButtonPressed>()) {
		if (s_buttons.on.getGlobalBounds().contains(pos)) { cout << "VOLUME_ON" << endl; volume_setting = 0; }
		if (s_buttons.off.getGlobalBounds().contains(pos)) { cout << "VOLUME_OFF" << endl; volume_setting = 1; }
		if (s_buttons.fps30.getGlobalBounds().contains(pos)) { window.setFramerateLimit(30); frame_setting = 1; }
		if (s_buttons.fps60.getGlobalBounds().contains(pos)) { window.setFramerateLimit(60); frame_setting = 0; }
	}


	s_buttons.on.setFillColor(volume_setting == 0 ? Color(150, 150, 150) : s_buttons.on.getGlobalBounds().contains(pos) ? Color(150, 150, 150) : Color::Transparent);
	on_text.setFillColor(s_buttons.on.getGlobalBounds().contains(pos) || volume_setting == 0 ? Color::White : Color(150, 150, 150));

	s_buttons.off.setFillColor(volume_setting == 1 ? Color(150, 150, 150) : s_buttons.off.getGlobalBounds().contains(pos) ? Color(150, 150, 150) : Color::Transparent);
	off_text.setFillColor(s_buttons.off.getGlobalBounds().contains(pos) || volume_setting == 1 ? Color::White : Color(150, 150, 150));

	s_buttons.fps30.setFillColor(frame_setting == 1 ? Color(150, 150, 150) : s_buttons.fps30.getGlobalBounds().contains(pos) ? Color(150, 150, 150) : Color::Transparent);
	fps30_text.setFillColor(s_buttons.fps30.getGlobalBounds().contains(pos) || frame_setting == 1 ? Color::White : Color(150, 150, 150));

	s_buttons.fps60.setFillColor(frame_setting == 0 ? Color(150, 150, 150) : s_buttons.fps60.getGlobalBounds().contains(pos) ? Color(150, 150, 150) : Color::Transparent);
	fps60_text.setFillColor(s_buttons.fps60.getGlobalBounds().contains(pos) || frame_setting == 0 ? Color::White : Color(150, 150, 150));
}
