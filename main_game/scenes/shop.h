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
	sf::Sprite b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
	sf::RectangleShape br1, br2, br3, br4, br5, br6, br7, br8, br9, br10;
	sf::RectangleShape shape;
	//sf::Vector2i mousePos;
	sf::Vector2f mousePos;
	sf::Vector2f worldPos;
	Main_character_artem artem;
	Mechanics_main_character artem_mechanics;
	sf::Clock clock;
	float speed_x;
public:
	Shop();
	Shop(string path_shop, string path_rust, string path_weapons, int speed_x);
	void update();
	void render(sf::RenderWindow& window);
	void set_sprite(sf::Sprite& sprite, sf::Texture& texture, sf::Vector2f point, float next_x, float next_y, float pos_x, float pos_y);
	void gun(sf::Sprite& shape, float cost);
};