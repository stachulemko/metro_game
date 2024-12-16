#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <utility>
#include <string>
using namespace std;
class  Piotr_Adriejewicz_Scene {
private:
	sf::Texture texture;
	sf::Sprite interaction;
	float offset_x_tmp;
	sf::RectangleShape shape;
public:
	Piotr_Adriejewicz_Scene();
	void Piotr_Adriejewicz_SceneCamp_fire_scene();
};