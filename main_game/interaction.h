#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
class Interaction {
private:
	sf::Texture texture;
	sf::Sprite interaction;
public:
	Interaction();
	float pos_x(float offset_x, float x);
	sf::Vector2f Range(float x, float offset_x, float range);
	bool InRange(float x, float offset_x, float range, float curr_pos);
	void display_iteraction(float x, float offset_x, float range, float curr_pos, sf::RenderWindow& window);
	void update(float offset_X);
	void render(sf::RenderWindow& window);

};