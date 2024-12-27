#include "tent.h"
Tent::Tent() {

}
Tent::Tent(float hp, float pos_x, float pos_y, string path) {
	this->hp = hp;
	this->pox_x = pos_x;
	this->pos_y = pos_y;
	if (!texture.loadFromFile(path)) {
		cout << "Error loading texture" << endl;
	}
	bagWithSand.setTexture(texture);
	bagWithSand.setScale(0.5, 0.5);
}
void Tent::update(float offset_x) {
	bagWithSand.setPosition(offset_x + pox_x, pos_y);
}
void Tent::render(sf::RenderWindow& window) {
	window.draw(bagWithSand);
}
