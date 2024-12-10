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
	float gravity ;
	bool is_throw ;
	float explosion_x;
	float explosion_y;
	sf::Clock clock;
	bool Last_direction;
	//sf::Time deltaTime;
	// granade texture set
	//float speed_y_tmp;
	float right_upper_x;
	float right_upper_y;
	float next_x;
	float next_y;
	//-------------------------------------
	float right_upper_x_explosion=1117;
	float right_upper_y_explosion=221;
	float next_x_explosion=136;
	float next_y_explosion =75;
	//-------------------------------------
	bool is_explosion=false;
	float greande_explosion=0;
	sf::Sprite granade;
	sf::Sprite explosion;
	sf::Texture granade_texture;
	sf::Texture explosion_texture;

	float granade_exlosion_deltatime;
	//sf::RectangleShape granade;
	//
public:
	Granade();
	void load_texture(std::string path, sf::Texture& texture);
	void set_sprite(sf::Sprite& sprite, sf::Texture& texture, float next_x, float next_y, float right_upper_x, float right_upper_y);
	void throw_right(float speed_tmp, float offset_x);
	void throw_left(float speed_tmp, float offset_x);
	void render(sf::RenderWindow& window);
	bool& get_is_throw() { return is_throw; }
	bool get_is_throw_value()  { return is_throw; }
	sf::Clock& get_clock() { return clock; }
	void set_Last_direction(bool flaga) {
		Last_direction = flaga;
	}
	bool get_Last_direction() {
		return Last_direction;
	}
	double get_max_zasieg(float vx, float vy, float g);
	void show_explosion(sf::RenderWindow& window);
};