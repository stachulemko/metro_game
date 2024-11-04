#pragma once
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\layres\back_ground\moving_background.h>
#include <string>
class Game_scene1_menager {
private:
	MovingBackground main_character;
public:
	Game_scene1_menager(float main_character_speed, float window_width, float window_height, std::string adress);
	void update();
	void render(sf::RenderWindow& window);
};
