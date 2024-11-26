#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Main_character_artem {
private:
	float move_speed = 100.0f;
	float run_speed = 200.0f;
	//#################
	float upper_right_difference_x = 29;
	float upper_right_difference_y = 14;
	float next_x = 70;
	float next_y = 150;
	//#################
	float upper_right_difference_x_run = 60;
	float upper_right_difference_y_run = 14;
	float next_x_run = 70;
	float next_y_run = 150;
	//###################
	bool last_direction = true;
	int currentFrame = 0;
	bool facingRight = true;
	//-------------------------------------
	vector<vector<float>> positions_moves = { {63,194}, {201, 194}, {340, 194}, {478, 194} };
	vector<vector<float>> positions_running = { {63,363}, {201, 363}, {340, 363}, {478, 363} };
	vector<vector<float>> positions_shoting1 = { {63,509}, {201, 509}, {340, 509}, {478, 509} };
	vector<vector<float>> move_points ;
	vector<vector<float>> running_points;
	vector<vector<float>> shoting1_points;
	vector<sf::Sprite> moveSprites;
	vector<sf::Sprite> runningSprites;
	vector<sf::Sprite> shotingSpritesShoting1;
	//-------------------------------------
	sf::Vector2f stayed_point;
	sf::Texture all_basic_artem;
	sf::Sprite sprite_stand;
	sf::Sprite sprite_tmp;
	sf::Clock clock;
	sf::Time deltaTime;
	//------------------------------------
	
public:
	Main_character_artem();
	void calculate_position_points(vector<vector<float>> positions, vector<vector<float>>& points, float upper_right_x, float upper_right_y);
	void load_texture(string path, sf::Texture &texture);
	void set_point(sf::Vector2f &point, float x, float y);
	void set_sprites_texture(vector <sf::Sprite>& sprites, sf::Texture& texture, vector<vector<float>> points, float next_x, float next_y, float corrections_x, float corrections_y);
	void set_sprite(sf::Sprite &sprite,sf::Texture &texture,sf::Vector2f point);
	void right_move();
	void left_move();
	void left_run();
	void right_run();
	void noneOfThem();
	void left_shoting1();
	void right_shoting1();
	void render(sf::RenderWindow& window);
	void update();
	void get_time() {
		//cout <<"negro : " << deltaTime.asSeconds() << endl;
	}
	void set_lastDirection(bool flaga) {
		last_direction = flaga;
	}
	bool get_lastDirection() {
		return last_direction;

	}


};