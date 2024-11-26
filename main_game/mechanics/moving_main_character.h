#pragma once
#include <SFML/Graphics.hpp>
class  Mechanics_main_character {
private:
	bool shift_pressed = false;
public:
	bool movingisKeyPressedD();
	bool movingisKeyPressedA();
	bool isShiftPressed();
	bool noKeyPressed();
	bool isrightMousePressed();
	bool get_shift_pressed() { return shift_pressed; }
	void set_shift_pressed(bool shift_pressed) { this->shift_pressed = shift_pressed; }
};