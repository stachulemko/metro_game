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
	float show_position_x=0;
	float show_position_y=0;
	float interaction_pos_x1=0;
	float interaction_pos_x2=0;
	sf::RectangleShape shape;
	Read read;
	//Dialogue dialogue;
public:
	//Interaction();
	Interaction(float show_position_x, float show_position_y, float interaction_pos_x1, float interaction_pos_x2);
	float pos_x(float offset_x, float x);
	sf::Vector2f Range(float x, float offset_x, float range);
	bool InRange(float x1, float x2, float curr_pos);
	void display_iteraction(float x1, float x2, float offset_x, sf::RenderWindow& window);
	void update(float offset_X);
	void render(sf::RenderWindow& window);
	void if_ineraction();
	bool if_ineraction(float pos_x1,float pos_x2);
	bool get_interaction_flaga();
	bool get_IsInteraction() {
		return IsInteraction;
	}
	void set_interaction_flaga(bool flaga) {
		IsInteraction = flaga;
	}
	float get_offset_x_tmp() {
		return offset_x_tmp;
	}
	float get_interaction_pos_x() {
		return interaction.getPosition().x;
	}
};