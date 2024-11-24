#include "scene1_end_of_the_world_background.h"
bool Scene1_end_of_the_world_background::IsRightArrrowClicked(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		return true;
	}
	else {
		return false;
	}
}