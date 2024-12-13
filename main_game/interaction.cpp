#include "Interaction.h"

Interaction::Interaction() {
	if (!texture.loadFromFile("")) {
		cout << "Error: Could not load texture piotr andrijewicz" << endl;
		//return -1;
	}
	interaction.setTexture(texture);
	interaction.setPosition(0,0);
}
float Interaction::pos_x(float offset_x, float x) {
	float pos = offset_x + x;
}
sf::Vector2f Interaction::Range(float x, float offset_x, float range) {
	sf::Vector2f range_pos = { pos_x(offset_x,x) - range, pos_x(offset_x,x) + range};
	return range_pos;
}
bool Interaction::InRange(float x, float offset_x, float range,float curr_pos) {
	if (curr_pos<Range(x, offset_x, range).x or Range(x, offset_x, range).y> curr_pos) {
		return true;
	}
	else {
		return false;
	}
}
void Interaction::display_iteraction(float x, float offset_x, float range, float curr_pos, sf::RenderWindow& window) {
	if (InRange(x, offset_x, range, curr_pos)) {
		window.draw(interaction);
	}
}
void Interaction::update(float offset_X) {
	//interaction.setPosition(offset_X+, 0);
}
void Interaction::render(sf::RenderWindow& window) {
	
}