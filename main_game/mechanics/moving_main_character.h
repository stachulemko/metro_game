#pragma once
#include <SFML/Graphics.hpp>
class  Mechanics_main_character {
private:
	bool shift_pressed = false;
	bool was_q_pressed = false;
public:
	bool movingisKeyPressedD();
	bool movingisKeyPressedA();
	bool isShiftPressed();
	bool noKeyPressed();
	bool isLeftMousePressed();
	bool isRightMousePressed();
	bool get_shift_pressed() { return shift_pressed; }
	void set_shift_pressed(bool shift_pressed) { this->shift_pressed = shift_pressed; }
	bool get_space_clicked();
	bool is_r_pressed();
	bool is_q_pressed();
	bool get_was_q_pressed() { return was_q_pressed; }
	void set_was_q_pressed(bool was_q_pressed) { this->was_q_pressed = was_q_pressed; }
	bool& get_was_q_pressed_ref() { return was_q_pressed; }
};