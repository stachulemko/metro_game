#pragma once
#include <SFML/Graphics.hpp>
class WindowScale {
private:
	float width;
	float height;
	
public:
	WindowScale(float width, float height);
	WindowScale();
	//void _updateViewPos();
	sf::Vector2f get_scale(sf::RenderWindow& window);
	sf::Vector2f scaleToFit(const sf::Vector2f& imageSize, const sf::Vector2f& windowSize);
};