#pragma once
#include <SFML/Graphics.hpp>
#include "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\layers\\back_ground\\moving_background.h"
class GlobalPos {
private:
	MovingBackground moving_bac;
	float pos_x;
	float pos_y;
public:
	GlobalPos() {

	}
	float get_global_pos_x() {
		return moving_bac.get_offset();
	}
	
};