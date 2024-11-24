#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Main_character_artem {
private:
	float move_speed = 100.0f;
	float run_speed = 200.0f;
	float upper_right_difference_x = 29;
	float upper_right_difference_y = 14;
	float next_x = 70;
	float next_y = 150;
	int currentFrame = 0;
	bool facingRight = true;
	vector<vector<float>> positions_moves = { {63,194}, {201, 194}, {340, 194}, {478, 194} };
	vector<vector<float>> position_points;
	sf::Vector2f stayed_point;
	sf::Texture all_basic_artem;
	vector<sf::Sprite> moveSprites;
	sf::Sprite sprite_stand;
	sf::Sprite sprite_tmp;
	sf::Clock clock;
	sf::Time deltaTime;
	
public:
	Main_character_artem();
	void calculate_position_points();
	void load_texture(string path, sf::Texture &texture);
	void set_point(sf::Vector2f &point, float x, float y);
	void set_sprites_texture(vector <sf::Sprite>& sprites, sf::Texture &texture, vector<vector<float>> points, float next_x, float next_y);
	void set_sprite(sf::Sprite &sprite,sf::Texture &texture,sf::Vector2f point);
	void right_move();
	void left_move();
	void noneOfThem();
	void render(sf::RenderWindow& window);
	void update();
	void get_time() {
		cout <<"negro : " << deltaTime.asSeconds() << endl;
	}


};