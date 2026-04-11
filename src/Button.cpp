#include "Button.h"

Button::Button(Font& font, const string& label, Vector2f l_position, Vector2f B_position, Vector2f B_size)
	: text(font, label, 35)
{
	shape.setSize(B_size);
	shape.setPosition(B_position);
	shape.setFillColor(Color::Transparent);
	text.setFillColor(Color(150, 150, 150));
	text.setPosition(l_position);
}

void Button::draw(RenderWindow& window) {
	window.draw(shape);
	window.draw(text);
}

void Button::update(RenderWindow& window) {
	Vector2f mousePos = Vector2f(Mouse::getPosition(window));
	shape.setFillColor(isHovered(mousePos) ? Color(180, 180, 180, 180) : Color::Transparent);
	text.setFillColor(isHovered(mousePos) ? Color::White : Color(150, 150, 150));
}

bool Button::isHovered(Vector2f mousePos) {
	return shape.getGlobalBounds().contains(mousePos);
}

bool Button::isClicked(Vector2f mousePos) {
	return isHovered(mousePos) && Mouse::isButtonPressed(Mouse::Button::Left);
}