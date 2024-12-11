#include "piotr_adriejewicz.h"
Piotr_Adriejewicz::Piotr_Adriejewicz() {
	hp = 100;
	damage = 10;
	speed = 10;
	radius = 10;
    cout << "ASDddsaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
    load_texture("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\piotr_adriejewicz.png", stand_texture);
    cout << "ASDddsaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
	set_point(sprite_point_stand, upper_right_difference_x_stand, uupper_right_difference_y_stand);
	set_sprite(stand, stand_texture, sprite_point_stand, 0, 0, next_x_stand,next_y_stand);
	stand.setPosition(470, 450);
    //square.setSize(sf::Vector2f(50.0f, 50.0f)); // Ustawiamy rozmiar kwadratu
    //square.setFillColor(sf::Color::Green); // Ustawiamy kolor kwadratu
    //square.setPosition(400, 470); // Ustawiamy pozycjê
}
void Piotr_Adriejewicz::calculate_position_points(vector<vector<float>> positions, vector<vector<float>>& points, float upper_right_x, float upper_right_y) {
    for (int i = 0; i < positions.size(); i++) {
        vector<float> temp = { positions[i][0] - upper_right_x, positions[i][1] - upper_right_y };
        points.push_back(temp);
    }

}
void Piotr_Adriejewicz::set_point(sf::Vector2f& point, float x, float y) {
    point.x = x;
    point.y = y;
}
void Piotr_Adriejewicz::load_texture(string path, sf::Texture& texture) {
    if (!texture.loadFromFile(path)) {
        cout << "Error: Could not load texture piotr dassssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss" << endl;
        //return -1;
    }
}
void Piotr_Adriejewicz::set_sprites_texture(vector <sf::Sprite>& sprites, sf::Texture& texture, vector<vector<float>> points, float next_x, float next_y, float corrections_x, float corrections_y) {
    for (int i = 0; i < points.size(); i++) {
        sprites[i].setTexture(texture);
        sprites[i].setTextureRect(sf::IntRect(points[i][0], points[i][1], next_x, next_y));
        sprites[i].setOrigin(next_x / 2 - corrections_x, next_y / 2 - corrections_y); // Ustawiamy punkt odniesienia na œrodek
        sprites[i].setPosition(400, 470);
    }
}
void Piotr_Adriejewicz::set_sprite(sf::Sprite& sprite, sf::Texture& texture, sf::Vector2f point,float upper_right_difference_x,float upper_right_difference_y,float next_x,float next_y) {
    sprite.setTexture(texture);
    cout << "ASDddsaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
	cout << point.x << " " << point.y << endl;
	cout << next_x << " " << next_y << endl;
    cout << "ASDddsaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
    set_point(sprite_point_stand, 45, 17);
    set_point(sprite_point_stand, 45, 17);
    sprite.setTextureRect(sf::IntRect(45,19, 80, 100));

    sprite.setOrigin(next_x / 2 - 10, next_y / 2); // Œrodek jako origin
    //sprite.setPosition(450, 470);
    //sprite.setPosition(400, 470);

}
void Piotr_Adriejewicz::render(sf::RenderWindow& window) {
	window.draw(stand);
    
    //window.draw(square);
}
void Piotr_Adriejewicz::update(float offset_X) {
    x_pos = offset_X;
    stand.setPosition(x_pos + 400, 450);
    stand.move(10, 1);
}