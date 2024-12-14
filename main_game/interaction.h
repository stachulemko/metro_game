#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
class Interaction {
private:
	sf::Texture texture;
	sf::Sprite interaction;
	float offset_x_tmp;
	sf::RectangleShape shape;
public:
	Interaction();
	float pos_x(float offset_x, float x);
	sf::Vector2f Range(float x, float offset_x, float range);
	bool InRange(float x1, float x2, float curr_pos);
	void display_iteraction(float x1, float x2, float offset_x, sf::RenderWindow& window);
	void update(float offset_X, float x);
	void render(sf::RenderWindow& window);

};