#include "metro_train.h"
MetroTrain::MetroTrain() {

}
MetroTrain::MetroTrain(float hp, float pos_x, float pos_y, string path) {
	this->hp = hp;
	this->pox_x = pos_x;
	this->pos_y = pos_y;
	if (!texture.loadFromFile(path)) {
		cout << "Error loading texture" << endl;
	}
	metroTrain.setTexture(texture);
	metroTrain.setScale(0.7, 0.7);
}
void MetroTrain::update(float offset_x) {
	metroTrain.setPosition(offset_x + pox_x, pos_y);
}
void MetroTrain::render(sf::RenderWindow& window) {
	window.draw(metroTrain);
}