#include "Interaction.h"

Interaction::Interaction() {
	if (!texture.loadFromFile("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\pixel1.png"
	)) {
		cout << "Error: Could not load texture piotr andrijewicz" << endl;
		//return -1;
	}
	interaction.setTexture(texture);
	interaction.setPosition(0,0);
	interaction.setScale(2.0f, 2.0f);
	shape.setSize(sf::Vector2f(100, 100));
	shape.setFillColor(sf::Color::Red);
}
float Interaction::pos_x(float offset_x, float x) {
	float pos = offset_x + x;
	return pos;
}
sf::Vector2f Interaction::Range(float x, float offset_x, float range) {
	sf::Vector2f range_pos = { pos_x(offset_x,x) - range, pos_x(offset_x,x) + range};
	return range_pos;
}
bool Interaction::InRange(float x1,float x2,float curr_pos) {
	//cout << "------------------------------------------------------------------------------------------------negro ===d=dad" << endl;
	//cout << "x: " << x << " offset_x: " << offset_x << " range: " << range << " curr_pos: " << curr_pos << endl;
	//cout << "------------------------------------------------------------------------------------------------ ===d=dad" << endl;
	if (curr_pos<x1 and curr_pos > x2 ) {
		//cout << "niggerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << endl;
		return true;
	}
	else {
		return false;
	}
}
void Interaction::display_iteraction(float x1,float x2, float offset_x, sf::RenderWindow& window) {
	if (InRange(x1, x2, offset_x)) {
		window.draw(interaction);
	}
}
void Interaction::update(float offset_X ,float x) {
	offset_x_tmp = offset_X;
	interaction.setPosition(offset_X+x, 260);
}
void Interaction::render(sf::RenderWindow& window) {
	display_iteraction( -480,-580,offset_x_tmp, window);
}