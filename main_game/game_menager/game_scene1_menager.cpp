#include "game_scene1_menager.h"

Game_scene1_menager::Game_scene1_menager(float main_character_speed, float window_width, float window_height, string adress, float textureWidth)
    : main_character(main_character_speed, window_width, window_height, adress, textureWidth) {
}

void Game_scene1_menager::update() {
    //main_character.
    main_character.update();
}

void Game_scene1_menager::render(sf::RenderWindow& window) {
    main_character.render(window);
}
