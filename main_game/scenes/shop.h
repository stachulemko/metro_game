#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\entietes\\main_character_artem.h"
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\mechanics\moving_main_character.h>
using namespace std;
class Shop {
private:
	sf::Texture texture,texture1,texture2 ;
	sf::Sprite Sprite,rust_back,weapons;
	sf::RectangleShape shape;

	Main_character_artem artem;
	Mechanics_main_character artem_mechanics;
	sf::Clock clock;
	float speed_x;
public:
	Shop();
	Shop(string path_shop, string path_rust, string path_weapons, int speed_x);
	void update();
	void render(sf::RenderWindow& window);
};