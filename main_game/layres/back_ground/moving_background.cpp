#include "moving_background.h"

MovingBackground::MovingBackground(float main_character_speed, float window_width, float window_height, string back_ground_adress) {
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
    float deltaTime = clock.restart().asSeconds();
    //cout << backgroundOffsetX << endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && backgroudX > -max_pos) {
        step = speed * deltaTime;
        if (backgroudX - step > -max_pos) {
            backgroundOffsetX -= step;
            backgroudX -= step;
        }
        else {
            cout << "block" << endl;
        }
        cout << backgroudX << endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && backgroudX < max_pos) {
        step = speed * deltaTime;
        if (backgroudX + step < max_pos) {
            backgroundOffsetX += step;
            backgroudX += step;
        }
        else {
            cout << "block" << endl;
        }
        cout << backgroudX << endl;
    }
	cout <<"delta time" << deltaTime << endl;
    if (backgroundOffsetX <= -textureWidth) {
        backgroundOffsetX += textureWidth;
    }
    if (backgroundOffsetX >= textureWidth) {
        backgroundOffsetX -= textureWidth;
    }
    //window.clear();
    backgroundSprite1.setPosition(backgroundOffsetX, 0);
    backgroundSprite2.setPosition(backgroundOffsetX + textureWidth, 0);
    backgroundSprite3.setPosition(backgroundOffsetX - textureWidth, 0);
}

void MovingBackground::render(sf::RenderWindow& window) {
    window.draw(backgroundSprite1);
    window.draw(backgroundSprite2);
    window.draw(backgroundSprite3);
}
