#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
class MetroTrain {
private:
	float hp;
	float pox_x;
	float pos_y;
	sf::Texture texture;
	sf::Sprite metroTrain;

public:
	MetroTrain(); // Konstruktor
	MetroTrain(float hp, float pos_x, float pos_y, string path); // Konstruktor
	void update(float offset_x);
	void render(sf::RenderWindow& window);
};