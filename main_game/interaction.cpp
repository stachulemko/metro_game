#include "Interaction.h"
#include <thread>
#include <mutex>

std::mutex mtx;
/*
Interaction::Interaction() {
    cout << "konstruktor domyslny interaction" << endl;
    if (!texture.loadFromFile("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\pixel1.png")) {
        
        std::cout << "Error: Could not load texture piotr andrijewicz" << std::endl;
       
    }
    //cout << "" << endl;
    interaction.setTexture(texture);
    interaction.setPosition(0, 0);
    interaction.setScale(2.0f, 2.0f);
    shape.setSize(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Red);
    //this->show_position_x = 830;
    //this->show_position_y = 260;
    //this->interaction_pos_x1 = -480;
    //this->interaction_pos_x2 = -580;
}
*/
Interaction::Interaction(float show_position_x, float show_position_y, float interaction_pos_x1, float interaction_pos_x2) {
    std::cout << "konstruktor prametryczny interaction" << std::endl;
    this->show_position_x = show_position_x;
    this->show_position_y = show_position_y;
    this->interaction_pos_x1 = interaction_pos_x1;
    this->interaction_pos_x2 = interaction_pos_x2;

    // Inicjalizacja tekstury i sprite
    if (!texture.loadFromFile("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\pixel1.png")) {
        std::cout << "Error: Could not load texture for interaction" << std::endl;
    }
    interaction.setTexture(texture);
    interaction.setPosition(show_position_x, show_position_y);
    interaction.setScale(2.0f, 2.0f);

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << this->show_position_x << std::endl;
    std::cout << this->show_position_y << std::endl;
    std::cout << this->interaction_pos_x1 << std::endl;
    std::cout << this->interaction_pos_x2 << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
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
        cout << "truetruetruetruetruetruetruetruetruetruetruetruetruetruetruetruetruetruetruetruetruevv" << endl;
    }
    else {
        //cout << "false" << endl;
        return false;
    }
}

void Interaction::display_iteraction(float x1, float x2, float offset_x, sf::RenderWindow& window) {
    if (InRange(x1, x2, offset_x) && get_interaction_flaga() == false) {
        window.draw(interaction);
		cout << "Interaction" << endl;
        IsInteraction = true;
    }
	else {
		IsInteraction = false;
	}
}

void Interaction::update(float offset_X) {
    offset_x_tmp = offset_X;
	cout << "show_position_x :" << show_position_x << "show_position_y :" << show_position_y << endl;
    interaction.setPosition(offset_X + show_position_x, show_position_y);
	//cout << interaction.getPosition().x << endl;
}
// -480 -580
void Interaction::render(sf::RenderWindow& window) {
	cout <<"interaction_pos_x1 : " << interaction_pos_x1 <<"interaction_pos_x2 : " << interaction_pos_x2 << endl;
    display_iteraction(interaction_pos_x1, interaction_pos_x2, offset_x_tmp, window);
    //std::lock_guard<std::mutex> lock(mtx);
    //writtings.render(window);
}

void Interaction::if_ineraction() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        if (InRange(interaction_pos_x1, interaction_pos_x2, offset_x_tmp)) {
            read.read_conversation();
            //std::thread conversation_thread(&Writtings::conversation_text, &writtings);
            //conversation_thread.detach();
        }
    }
}
bool Interaction::if_ineraction(float pos_x1, float pos_x2) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        if (InRange(pos_x1, pos_x2, offset_x_tmp)) {
			return true;
            //read.read_conversation();
            //std::thread conversation_thread(&Writtings::conversation_text, &writtings);
            //conversation_thread.detach();
        }
    }
	return false;
}

bool Interaction::get_interaction_flaga() {
    return read.get_conversation_started();
}
