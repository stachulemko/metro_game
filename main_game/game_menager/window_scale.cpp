#include "window_scale.h"
WindowScale::WindowScale(float width, float height) {
	this->width = width;
	this->height = height;
}
sf::Vector2f WindowScale::get_scale(sf::RenderWindow& window) {

	float scaleX = (float)window.getSize().x / width;
	float scaleY = (float)window.getSize().y / height;
	sf::Vector2f scale = { scaleX, scaleY };
	return scale;
}