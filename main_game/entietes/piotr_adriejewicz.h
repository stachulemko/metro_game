#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Piotr_Adriejewicz {
private:
	int hp;
	int damage;
	int speed;
	int radius;
	float next_x_stand=80 ;
	float next_y_stand = 100;
	float x_pos;
	float y_pos=450;
	float uupper_right_difference_y_stand=45;
	float upper_right_difference_x_stand=19;
	float move_speed = 5.0f;
	sf::RectangleShape square;
	sf::Sprite stand;
	sf::Texture stand_texture;
	sf::Vector2f sprite_point_stand;
public:
	Piotr_Adriejewicz();
	void calculate_position_points(vector<vector<float>> positions, vector<vector<float>>& points, float upper_right_x, float upper_right_y);
	void load_texture(string path, sf::Texture& texture);
	void set_point(sf::Vector2f& point, float x, float y);
	void set_sprites_texture(vector <sf::Sprite>& sprites, sf::Texture& texture, vector<vector<float>> points, float next_x, float next_y, float corrections_x, float corrections_y);
	void set_sprite(sf::Sprite& sprite, sf::Texture& texture, sf::Vector2f point, float upper_right_difference_x, float upper_right_difference_y, float next_x, float next_y);
	void render(sf::RenderWindow& window);
	void update(float offset_X);
};