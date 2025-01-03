#include "game_scene1_menager.h"

Game_scene1_menager::Game_scene1_menager(float main_character_speed, float window_width, float window_height, string adress, float textureWidth)
    : main_character(main_character_speed, window_width, window_height, adress, textureWidth),
    main_character_inside_train(200, 800, 600, "C:\\Users\\KêpkaStanis³aw\\Downloads\\pixel_art_subway.png", 1185) {
}

void Game_scene1_menager::update() {
    if (enterance.get_is_inside()) {
		main_character_inside_train.update();
    }
    else {
        main_character.update();
    }
	enterance.update(main_character.get_offset());
}

void Game_scene1_menager::render(sf::RenderWindow& window) {
    if (enterance.get_is_inside()) {
        //cout << "niger niger niger nigernigerniger  nigerv  nigerniger v niger niger v niger v niger niger niger vc value v  " << endll;
        main_character_inside_train.render(window);
    }
    else {
        cout << "the same the smae the same the smae the same the smae the same the smae the same the smae the same the smae the same the smae the same the smae the same the smae the same the smae" << endl;
        main_character.render(window);
    }
    enterance.render(window);
    //enterance.update(main_character.get_offset());
    // main_character_inside_train.render(window);
    
    
     //ain_character.render(window);
	 
    
    //main_character.render(window);
    
    //piotr.render(window);
}
