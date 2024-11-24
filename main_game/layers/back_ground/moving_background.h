#pragma once
#include <SFML/Graphics.hpp>
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\mechanics\moving_main_character.h>
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\game_menager\TimeManager1.h>
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\entietes\main_character_artem.h>
#include<iostream>
#include <vector>
#include<string>
using namespace std;
class MovingBackground {
private:
	
	sf::Texture texture;
	//float speed;
	float window_width=800;
	float window_height=600;
	Mechanics_main_character main_character;
	Main_character_artem artem;
	//-------------------------------------------
	//int maxShifts = 6;
	sf::Texture backgroundTexture;
	//const float playerSpeed = 200.0f;
	// Prêdkoœæ ruchu gracza
	const float speed = 100.0f;
	float backgroundOffsetX = 0;
	float backgroudX = 0;
	// Ustal wymiary tekstury t³a
	float textureWidth = 1185;
	int max_pos = 4 * textureWidth;
	float step = 0;
	sf::Sprite backgroundSprite1;
	sf::Sprite backgroundSprite2;
	sf::Sprite backgroundSprite3;
public:
	MovingBackground(float main_character_speed, float window_width, float window_height, string adress, float textureWidth);
	void update();
	void render(sf::RenderWindow& window);
	sf::Texture getTexture() { return texture; }
	vector<sf::Sprite> getSprites() {
		vector<sf::Sprite> sprites;
		sprites.push_back(backgroundSprite1);
		sprites.push_back(backgroundSprite2);
		sprites.push_back(backgroundSprite3);
		return sprites;
	}
};