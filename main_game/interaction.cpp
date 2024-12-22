#include "Interaction.h"
#include <thread>
#include <mutex>

std::mutex mtx;

Interaction::Interaction() {
    if (!texture.loadFromFile("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\pixel1.png")) {
        std::cout << "Error: Could not load texture piotr andrijewicz" << std::endl;
    }
    interaction.setTexture(texture);
    interaction.setPosition(0, 0);
    interaction.setScale(2.0f, 2.0f);
    shape.setSize(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Red);
}

float Interaction::pos_x(float offset_x, float x) {
    float pos = offset_x + x;
    return pos;
}

sf::Vector2f Interaction::Range(float x, float offset_x, float range) {
    sf::Vector2f range_pos = { pos_x(offset_x, x) - range, pos_x(offset_x, x) + range };
    return range_pos;
}

bool Interaction::InRange(float x1, float x2, float curr_pos) {
    if (curr_pos < x1 && curr_pos > x2) {
        return true;
    }
    else {
        return false;
    }
}

void Interaction::display_iteraction(float x1, float x2, float offset_x, sf::RenderWindow& window) {
    if (InRange(x1, x2, offset_x) && get_interaction_flaga() == false) {
        window.draw(interaction);
    }
}

void Interaction::update(float offset_X, float x) {
    offset_x_tmp = offset_X;
    interaction.setPosition(offset_X + x, 260);
}

void Interaction::render(sf::RenderWindow& window) {
    display_iteraction(-480, -580, offset_x_tmp, window);
    //std::lock_guard<std::mutex> lock(mtx);
    //writtings.render(window);
}

void Interaction::if_ineraction() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        if (InRange(-480, -580, offset_x_tmp)) {
            read.read_conversation();
            //std::thread conversation_thread(&Writtings::conversation_text, &writtings);
            //conversation_thread.detach();
        }
    }
}

bool Interaction::get_interaction_flaga() {
    return read.get_conversation_started();
}
