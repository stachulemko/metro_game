#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
class BagWithSand {
private:
	float hp;
	float pox_x;
	float pos_y;
	sf::Texture texture;
	sf::Sprite bagWithSand;

public:
	BagWithSand(); // Konstruktor
	BagWithSand(float hp, float pos_x, float pos_y, string path); // Konstruktor
	void update(float offset_x);
	void render(sf::RenderWindow& window);
};