#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Granade {
private:
	

	  
	int damage;
	int radius;
	float speed_x;
	float speed_y;
	float speed_x_tmp;
	float speed_y_tmp;
	float gravity ;
	bool is_throw ;
	sf::Clock clock;
	//sf::Time deltaTime;
	// granade texture set
	//float speed_y_tmp;
	float right_upper_x;
	float right_upper_y;
	float next_x;
	float next_y;
	//sf::Sprite granade;
	sf::Texture granade_texture;
	sf::RectangleShape granade;
	//
public:
	Granade();
	void load_texture(std::string path, sf::Texture& texture);
	void set_sprite(sf::Sprite& sprite, sf::Texture& texture, float next_x, float next_y, float right_upper_x, float right_upper_y);
	void throw_right();
	void throw_left();
	void render(sf::RenderWindow& window);
	bool& get_is_throw() { return is_throw; }
	bool get_is_throw_value()  { return is_throw; }
	sf::Clock& get_clock() { return clock; }

};