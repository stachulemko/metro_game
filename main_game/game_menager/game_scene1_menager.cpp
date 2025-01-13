#include "game_scene1_menager.h"

Game_scene1_menager::Game_scene1_menager(float main_character_speed, float window_width, float window_height, string adress, float textureWidth)
    : main_character(main_character_speed, window_width, window_height, adress, textureWidth),
     interaction_enter_the_train(5900,260,-5480,-5580),
     inside_train(200, 800, 600, "C:\\Users\\KêpkaStanis³aw\\Downloads\\pixel_art_subway.png", 1185){
}

void Game_scene1_menager::update() {
    if (interaction_enter_the_train.get_is_inside() == true) {
       
    }
    else {
        main_character.update();
    }
    interaction_enter_the_train.update(main_character.get_offset());
    interaction_enter_the_train.if_interaction_flag();
	//enterance.update(main_character.get_offset());
}

void Game_scene1_menager::render(sf::RenderWindow& window) {
    //enterance.render(window);
    if (interaction_enter_the_train.get_is_inside() == true) {

    }
    else {
        main_character.render(window);
    }
    
	interaction_enter_the_train.render(window);
    
    //enterance.render(window);
    //enterance.update(main_character.get_offset());
    // main_character_inside_train.render(window);
    
    
     //ain_character.render(window);
	 
    
    //main_character.render(window);
    
    //piotr.render(window);
}
