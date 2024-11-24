#include "moving_background.h"

MovingBackground::MovingBackground(float main_character_speed, float window_width, float window_height, string back_ground_adress, float textureWidth) {
    this->textureWidth = textureWidth;
    //speed = main_character_speed;
    this->window_width = window_width;
    this->window_height = window_height;
    if (!backgroundTexture.loadFromFile(back_ground_adress)) {
        cout << "Error: Could not load texture" << endl;
    }
    backgroundSprite1.setTexture(backgroundTexture);
    backgroundSprite2.setTexture(backgroundTexture);
    backgroundSprite3.setTexture(backgroundTexture);
    //textureWidth = backgroundTexture.getSize().x;
    //max_pos = 2 * textureWidth;
}

void MovingBackground::update() {
    //cout << backgroundOffsetX << endl;
	TimeManager1& timeManager = TimeManager1::getInstance();
    //cout <<"niger ::" << texture.getSize().x << texture.getSize().y << endl;
    artem.get_time();
    float deltaTime = timeManager.getDeltaTime();
    if (main_character.movingisKeyPressedRight() && backgroudX > -max_pos) {
        //cout << "deltaTime: " << deltaTime << endl;
        //cout << "playerspeed" << speed << endl;
        step = speed * deltaTime;
        if (backgroudX - step > -max_pos) {
            backgroundOffsetX -= step;
            backgroudX -= step;
            //cout << "step" << step << endl;
            //cout << "backgroudX" << backgroudX << endl;
        }
		else {
			cout << "block" << endl;
		}
		artem.right_move();
    }
    if (main_character.movingisKeyPressedLeft() && backgroudX < max_pos) {
        step = speed * deltaTime;
        if (backgroudX + step < max_pos) {
            backgroundOffsetX += step;
            backgroudX += step;
        }
        else {
            cout << "block" << endl;
        }
        cout << backgroudX << endl;
		artem.left_move();
    }
	if (main_character.noKeyPressed()) {
		artem.noneOfThem();
	}
	//cout <<"delta time" << deltaTime << endl;
    if (backgroundOffsetX <= -textureWidth) {
        backgroundOffsetX += textureWidth;
    }
    if (backgroundOffsetX >= textureWidth) {
        backgroundOffsetX -= textureWidth;
    }
   std::cout << "deltaTime: " << deltaTime << ", step: " << step << ", backgroudX: " << backgroudX << std::endl;

    //window.clear();
    backgroundSprite1.setPosition(backgroundOffsetX, 0);
    backgroundSprite2.setPosition(backgroundOffsetX + textureWidth, 0);
    backgroundSprite3.setPosition(backgroundOffsetX - textureWidth, 0);
    artem.update();
    
}

void MovingBackground::render(sf::RenderWindow& window) {
    window.draw(backgroundSprite1);
    window.draw(backgroundSprite2);
    window.draw(backgroundSprite3);
    artem.render(window);
}
