#pragma once
#include <SFML/Graphics.hpp>
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\mechanics\moving_main_character.h>
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\game_menager\TimeManager1.h>
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\entietes\main_character_artem.h>
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\entietes\weapons\granade.h>
#include "C:\dev\dev_c++\dev_game\metro_game\main_game\entietes\piotr_adriejewicz.h"
#include "C:\dev\dev_c++\dev_game\metro_game\main_game\interaction.h"
#include "C:\dev\dev_c++\dev_game\metro_game\main_game\scenes\writings.h"
#include "C:\dev\dev_c++\dev_game\metro_game\main_game\metro_station\wogn.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MovingBackground {
private:
    Wogn wogn;
    Writtings writtings; // Dodano brakuj¹cy œrednik
    //Interaction interaction_enter_the_train;
    Interaction interaction_near_the_camp_fire;
    Piotr_Adriejewicz piotr;
    sf::Texture texture;
    float window_width = 800;
    float window_height = 600;
    Mechanics_main_character main_character;
    Main_character_artem artem;
    Granade granade;
    sf::Texture backgroundTexture;
    float speed = 70.0f;
    float backgroundOffsetX = 0;
    float back_x_test = 0;
    float backgroudX = 0;
    float textureWidth = 1185;
    float max_pos = 10 * textureWidth; // Zmieniono typ na float
    float step = 0;
    sf::Sprite backgroundSprite1;
    sf::Sprite backgroundSprite2;
    sf::Sprite backgroundSprite3;
public:
    MovingBackground();
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
    float get_offset() {
        return back_x_test;
    }
};

