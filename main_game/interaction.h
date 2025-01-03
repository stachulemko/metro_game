#pragma once
#include <SFML/Graphics.hpp>
#include "C:\dev\dev_c++\dev_game\metro_game\main_game\scenes\writings.h"
//#include "C:\dev\dev_c++\dev_game\metro_game\main_game\scenes\dialogue.h"

#include<iostream>
#include "C:\dev\dev_c++\dev_game\metro_game\main_game\scenes\read.h"
using namespace std;
class Interaction {
private:
	sf::Texture texture;
	sf::Sprite interaction;
	//Writtings writtings;
	bool IsInteraction = false;
	//bool interaction_flaga = false;
	float offset_x_tmp;
	sf::RectangleShape shape;
	Read read;
	//Dialogue dialogue;
public:
	Interaction();
	float pos_x(float offset_x, float x);
	sf::Vector2f Range(float x, float offset_x, float range);
	bool InRange(float x1, float x2, float curr_pos);
	void display_iteraction(float x1, float x2, float offset_x, sf::RenderWindow& window);
	void update(float offset_X, float x,float y);
	void render(sf::RenderWindow& window, float x1, float x2);
	void if_ineraction();
	bool if_ineraction(float pos_x1,float pos_x2);
	bool get_interaction_flaga();
	bool get_IsInteraction() {
		return IsInteraction;
	}
	void set_interaction_flaga(bool flaga) {
		IsInteraction = flaga;
	}

};