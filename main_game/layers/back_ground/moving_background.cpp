#include "moving_background.h"

MovingBackground::MovingBackground()
    : interaction_near_the_camp_fire(830, 260, -480, -580) {
    std::cout << "MovingBackground default constructor called" << std::endl;
}

MovingBackground::MovingBackground(float main_character_speed, float window_width, float window_height, std::string back_ground_adress, float textureWidth)
    : interaction_near_the_camp_fire(830, 260, -480, -580){
    this->textureWidth = textureWidth;
    this->window_width = window_width;
    this->window_height = window_height;
    if (!backgroundTexture.loadFromFile(back_ground_adress)) {
        std::cout << "Error: Could not load texture" << std::endl;
    }
    backgroundSprite1.setTexture(backgroundTexture);
    backgroundSprite2.setTexture(backgroundTexture);
    backgroundSprite3.setTexture(backgroundTexture);
    // Usuñ wywo³anie MovingBackground();
}

void MovingBackground::update() {
    if (interaction_near_the_camp_fire.get_interaction_flaga() == false) {
        TimeManager1& timeManager = TimeManager1::getInstance();
        back_x_test = backgroudX;
        artem.get_time();
        float deltaTime = timeManager.getDeltaTime();

        if (main_character.get_was_q_pressed() == false) {
            if (main_character.isShiftPressed()) {
                main_character.set_shift_pressed(true);
            }
            if (main_character.movingisKeyPressedD() && backgroudX > -max_pos) {
                artem.set_lastDirection(true);
                step = speed * deltaTime;
                if (backgroudX - step > -max_pos) {
                    backgroundOffsetX -= step;
                    backgroudX -= step;
                }
                if (main_character.isShiftPressed() == true) {
                    artem.right_run();
                    speed = 130.0f;
                }
                else {
                    speed = 70.0f;
                    artem.right_move();
                }
            }
            if (main_character.movingisKeyPressedA() && backgroudX < max_pos) {
                artem.set_lastDirection(false);
                step = speed * deltaTime;
                if (backgroudX + step < max_pos) {
                    backgroundOffsetX += step;
                    backgroudX += step;
                }
                if (main_character.isShiftPressed() == true) {
                    artem.left_run();
                    speed = 130.0f;
                }
                else {
                    speed = 70.0f;
                    artem.left_move();
                }
            }
            if (main_character.noKeyPressed()) {
                if (main_character.is_q_pressed() and granade.get_is_throw() == false) {
                    main_character.set_was_q_pressed(true);
                }
                if (main_character.isLeftMousePressed() and main_character.isRightMousePressed() == false) {
                    if (artem.get_lastDirection() == true) {
                        artem.right_shoting1();
                    }
                    else {
                        artem.left_shoting1();
                    }
                }
                else if (main_character.isLeftMousePressed() == false and main_character.isRightMousePressed() == false and main_character.is_r_pressed() == false) {
                    artem.noneOfThem();
                }
            }
            if (main_character.noKeyPressed()) {
                if (main_character.is_r_pressed()) {
                    if (artem.get_lastDirection() == true) {
                        artem.right_reload();
                    }
                    else {
                        artem.left_reload();
                    }
                }
                if (main_character.get_space_clicked()) {
                    artem.jump();
                }
                artem.jump_update();
                if (main_character.isRightMousePressed() == true) {
                    if (main_character.isLeftMousePressed() == true) {
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
        }
        else if (main_character.get_was_q_pressed() == true and granade.get_is_throw() == false) {
            if (artem.get_lastDirection() == true) {
                granade.set_Last_direction(true);
                artem.right_granade(main_character.get_was_q_pressed_ref(), granade.get_is_throw(), granade.get_clock());
            }
            else {
                granade.set_Last_direction(false);
                artem.left_granade(main_character.get_was_q_pressed_ref(), granade.get_is_throw(), granade.get_clock());
            }
        }
        if (granade.get_is_throw_value() == true) {
            if (granade.get_Last_direction() == true) {
                if (main_character.movingisKeyPressedA() == false and main_character.movingisKeyPressedD() == false) {
                    granade.throw_right(-1, back_x_test);
                }
                else if (main_character.movingisKeyPressedA() == true and main_character.movingisKeyPressedD() == false and main_character.isShiftPressed() == false) {
                    granade.throw_right(230, back_x_test);
                }
                else if (main_character.movingisKeyPressedA() == true and main_character.movingisKeyPressedD() == false and main_character.isShiftPressed() == true) {
                    granade.throw_right(300, back_x_test);
                }
                else if (main_character.movingisKeyPressedA() == false and main_character.movingisKeyPressedD() == true and main_character.isShiftPressed() == false) {
                    granade.throw_right(150, back_x_test);
                }
                else if (main_character.movingisKeyPressedA() == false and main_character.movingisKeyPressedD() == true and main_character.isShiftPressed() == true) {
                    granade.throw_right(130, back_x_test);
                }
                else {
                    granade.throw_right(-1, back_x_test);
                }
            }
            else if (granade.get_Last_direction() == false) {
                if (main_character.movingisKeyPressedA() == false and main_character.movingisKeyPressedD() == false) {
                    granade.throw_left(-1, back_x_test);
                }
                else if (main_character.movingisKeyPressedA() == true and main_character.movingisKeyPressedD() == false and main_character.isShiftPressed() == false) {
                    granade.throw_left(150, back_x_test);
                }
                else if (main_character.movingisKeyPressedA() == true and main_character.movingisKeyPressedD() == false and main_character.isShiftPressed() == true) {
                    granade.throw_left(130, back_x_test);
                }
                else if (main_character.movingisKeyPressedA() == false and main_character.movingisKeyPressedD() == true and main_character.isShiftPressed() == false) {
                    granade.throw_left(230, back_x_test);
                }
                else if (main_character.movingisKeyPressedA() == false and main_character.movingisKeyPressedD() == true and main_character.isShiftPressed() == true) {
                    granade.throw_left(300, back_x_test);
                }
                else {
                    granade.throw_left(-1, back_x_test);
                }
            }
        }
        if (backgroundOffsetX <= -textureWidth) {
            backgroundOffsetX += textureWidth;
        }
        if (backgroundOffsetX >= textureWidth) {
            backgroundOffsetX -= textureWidth;
        }
        std::cout << "deltaTime: " << deltaTime << ", step: " << step << ", backgroudX: " << backgroudX << std::endl;

        backgroundSprite1.setPosition(backgroundOffsetX, 0);
        backgroundSprite2.setPosition(backgroundOffsetX + textureWidth, 0);
        backgroundSprite3.setPosition(backgroundOffsetX - textureWidth, 0);
        wogn.update(back_x_test);
        artem.update();
        piotr.update(back_x_test);
        interaction_near_the_camp_fire.update(back_x_test);
        //interaction_enter_the_train.update(back_x_test);
        interaction_near_the_camp_fire.if_interaction();
        
    }
    else {
        writtings.update();
    }
}

void MovingBackground::render(sf::RenderWindow& window) {
    window.draw(backgroundSprite1);
    window.draw(backgroundSprite2);
    window.draw(backgroundSprite3);
    granade.render(window, back_x_test);
    wogn.render(window);
    artem.render(window);
    piotr.render(window);
    interaction_near_the_camp_fire.render(window);
    //interaction_enter_the_train.render(window);
    writtings.render(window);
    
}
