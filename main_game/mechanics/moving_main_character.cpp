	#include "moving_main_character.h"
bool Mechanics_main_character::movingisKeyPressedD() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
		return true;
	}
	else {
		return false;
	}
}
bool  Mechanics_main_character::movingisKeyPressedA() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		return true;
	}
	else {
		return false;
	}
}
bool Mechanics_main_character::noKeyPressed() {
	for (int key = sf::Keyboard::A; key <= sf::Keyboard::KeyCount; ++key) {
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key))) {
			return false; 
		}
	}
	return true; 
}