#pragma once
#include <SFML/Graphics.hpp>
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\mechanics\moving_main_character.h>
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\game_menager\TimeManager1.h>
#include<iostream>
#include<string>
using namespace std;
class MovingBackground {
private:
	
	sf::Texture texture;
	sf::Sprite sprite;
	//float speed;
	float window_width=800;
	float window_height=600;
	Mechanics_main_character main_character;
	//-------------------------------------------
	//int maxShifts = 6;
	sf::Texture backgroundTexture;
	//const float playerSpeed = 200.0f;
	// Prêdkoœæ ruchu gracza
	const float speed = 200.0f;
	float backgroundOffsetX = 0;
	float backgroudX = 0;
	
	int max_counter = 2;
	// Ustal wymiary tekstury t³a
	float textureWidth = 1185;
	int max_pos = 2 * textureWidth;
	float step = 0;
	sf::Sprite backgroundSprite1;
	sf::Sprite backgroundSprite2;
	sf::Sprite backgroundSprite3;
public:
	MovingBackground(float main_character_speed, float window_width, float window_height, string adress, float textureWidth);
	void update();
	void render(sf::RenderWindow& window);
};