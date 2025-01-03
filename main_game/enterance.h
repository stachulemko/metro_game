#pragma once
#include <SFML/Graphics.hpp>
#include "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\interaction.h"
#include "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\global_pos.h"
using namespace std;
class Enterance {
private:
	bool is_inside = false;
	GlobalPos global_pos;
	Interaction interaction_enter_train;

public:
	Enterance();
	void update(float offset_x);
	void render(sf::RenderWindow& window);
	bool get_is_inside() {
		return is_inside;
	}
};