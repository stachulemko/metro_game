#pragma once
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\layers\back_ground\moving_background.h>
#include <string>
class Game_scene1_menager {
private:
	MovingBackground main_character;
	//Piotr_Adriejewicz piotr;
public:
	Game_scene1_menager(float main_character_speed, float window_width, float window_height, std::string adress, float textureWidth);
	void update();
	void render(sf::RenderWindow& window);
	vector<sf::Sprite>getBackgroundSprites() {
		return main_character.getSprites();
	}
	sf::Texture getBackgroundTexture() {
		return main_character.getTexture();
	}

};
