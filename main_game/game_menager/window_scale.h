#pragma once
#include <SFML/Graphics.hpp>
class WindowScale {
private:
	float width;
	float height;
public:
	WindowScale(float width, float height);
	sf::Vector2f get_scale(sf::RenderWindow& window);
};