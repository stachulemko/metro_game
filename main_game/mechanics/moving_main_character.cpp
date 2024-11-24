	#include "moving_main_character.h"
bool Mechanics_main_character::movingisKeyPressedRight() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
		return true;
	}
	else {
		return false;
	}
}
bool  Mechanics_main_character::movingisKeyPressedLeft() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		return true;
	}
	else {
		return false;
	}
}