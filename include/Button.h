#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Button {
public:
	Button(Font& font, const string& label, Vector2f l_position, Vector2f B_position, Vector2f B_size);

	bool isHovered(Vector2f mousePos);
	bool isClicked(Vector2f mousePos);
	void update(RenderWindow& window);
	void draw(RenderWindow& window);
	
private:
	//Font font;
	Text text;
	RectangleShape shape;
};