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
    if (main_character.isShiftPressed()) {
		main_character.set_shift_pressed(true);
    }
    //------------------------------------------------------------------
    if (main_character.movingisKeyPressedD() && backgroudX > -max_pos) {
        //cout << "deltaTime: " << deltaTime << endl;
        //cout << "playerspeed" << speed << endl;
        artem.set_lastDirection(true);
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
        if (main_character.isShiftPressed()==true) {
			artem.right_run();
            speed = 130.0f;
        }
        else {
			speed = 70.0f;
            artem.right_move();
        }
		
    }
    //------------------------------------------------------------------
    if (main_character.movingisKeyPressedA() && backgroudX < max_pos) {
        artem.set_lastDirection(false);
        step = speed * deltaTime;
        if (backgroudX + step < max_pos) {
            backgroundOffsetX += step;
            backgroudX += step;
        }
        else {
            cout << "block" << endl;
        }
        cout << backgroudX << endl;
        if (main_character.isShiftPressed()==true) {
			cout << "shiftshiftshiftshiftshiftshiftshiftshiftshiftshift" << endl;
			artem.left_run();
            speed = 130.0f;
        }
        else {
            speed = 70.0f;
            artem.left_move();
        }
		
    }
    //------------------------------------------------------------------
	if (main_character.noKeyPressed()) {
        if (main_character.isLeftMousePressed() and main_character.isRightMousePressed() == false) {
            if (artem.get_lastDirection() == true) {
                artem.right_shoting1();
            }
            else {
                artem.left_shoting1();
            }

        }
        else if (main_character.isLeftMousePressed() == false and  main_character.isRightMousePressed() == false) {
            cout << "fuck fuck fuck" << endl;
            artem.noneOfThem();
        }
	}
    if (main_character.noKeyPressed()) {
        if (main_character.isRightMousePressed() == true) {
            if (main_character.isLeftMousePressed() == true) {
                cout << "gowno" << endl;
                if (artem.get_lastDirection() == true) {
                    artem.right_shoting2();
                }
                else {
                    artem.left_shoting2();
                }
            }
			else {
				artem.stand_run_shoting2();
			}
        }
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
