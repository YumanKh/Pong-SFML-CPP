#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "prototypes.h"
using namespace sf;
using namespace std;

void draw_credits(RenderWindow& window, Font& font, Sprite& menu_credits) {
	menu_credits.setPosition({ 300, 100 });
	menu_credits.setColor(Color(180, 180, 180, 180));

	Text creator(font, "Game Design & Development", 20);
	creator.setFillColor(Color::White);
	creator.setPosition({ 350, 150 });

	Text creator_name(font, "Yuman", 20);
	creator_name.setFillColor(Color(150, 150, 150));
	creator_name.setPosition({ 460, 190 });


	Text assets(font, "Assets Creators", 20);
	assets.setFillColor(Color::White);
	assets.setPosition({ 410, 270 });

	Text assets_name(font, "Yuman & Gemini - Nano Banana 2", 17);
	assets_name.setFillColor(Color(150, 150, 150));
	assets_name.setPosition({ 345, 310 });

	window.draw(menu_credits);
	window.draw(creator);
	window.draw(creator_name);
	window.draw(assets);
	window.draw(assets_name);
}