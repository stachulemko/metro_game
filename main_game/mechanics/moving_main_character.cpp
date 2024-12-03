	#include "moving_main_character.h"
bool Mechanics_main_character::movingisKeyPressedD() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
		return true;
	}
	else {
		return false;
	}
}
bool  Mechanics_main_character::movingisKeyPressedA() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		return true;
	}
	else {
		return false;
	}
}
bool Mechanics_main_character::noKeyPressed() {
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		return true;
	}
	else {
		return false;
	}
}

bool Mechanics_main_character::isShiftPressed() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
		return true;
	}
	else {
		return false;
	}
}
bool Mechanics_main_character::isLeftMousePressed() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		return true;
	}
	else {
		return false;
	}
}
bool Mechanics_main_character::isRightMousePressed() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		return true;
	}
	else {
		return false;
	}
}
bool Mechanics_main_character::get_space_clicked() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		return true;
	}
	else {
		return false;
	}
}
bool Mechanics_main_character::is_r_pressed() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		return true;
	}
	else {
		return false;
	}
	
}
