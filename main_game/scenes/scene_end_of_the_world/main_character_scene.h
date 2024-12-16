#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
using namespace std;
class MainCharacterScene {
private:
	sf::Texture texture;
	sf::Sprite interaction;
	float offset_x_tmp;
	sf::RectangleShape shape;
public:
	MainCharacterScene();
	void MainCharacterSceneCamp_fire_scene();

};