#include "main_character_artem.h"
Main_character_artem::Main_character_artem() {
    moveSprites.resize(4);
    calculate_position_points();
    set_point(stayed_point, 337, 27);
    load_texture("C:\\dev\\dev_c++\\dev_game\\TestGame2\\all6.png", all_basic_artem);
	set_sprites_texture(moveSprites, all_basic_artem, position_points, next_x, next_y);
	set_sprite(sprite_stand, all_basic_artem, stayed_point);
}
void Main_character_artem::calculate_position_points() {
    for (int i = 0; i < positions_moves.size(); i++) {
        vector<float> temp = { positions_moves[i][0] - upper_right_difference_x, positions_moves[i][1] - upper_right_difference_y };
        position_points.push_back(temp);
    }

}
void Main_character_artem::set_point(sf::Vector2f &point, float x, float y) {
    stayed_point.x = x;
    stayed_point.y = y;
}
void Main_character_artem::load_texture(string path,sf::Texture &texture) {
    if (!texture.loadFromFile(path)) {
        cout << "Error: Could not load texture" << endl;
        //return -1;
    }
}
void Main_character_artem::set_sprites_texture(vector <sf::Sprite>& sprites, sf::Texture &texture, vector<vector<float>> points, float next_x, float next_y) {
    for (int i = 0; i < points.size(); i++) {
        sprites[i].setTexture(texture);
        sprites[i].setTextureRect(sf::IntRect(points[i][0], points[i][1], next_x, next_y));
        sprites[i].setOrigin(next_x / 2 - 10, next_y / 2); // Ustawiamy punkt odniesienia na œrodek
    }
}
void Main_character_artem::set_sprite(sf::Sprite &sprite,sf::Texture &texture, sf::Vector2f point) {
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(point.x - upper_right_difference_x, point.y - upper_right_difference_y, next_x, next_y));
    sprite.setOrigin(next_x / 2 - 10, next_y / 2); // Œrodek jako origin
	
}
void Main_character_artem::right_move() {
    deltaTime = clock.getElapsedTime();
    if (deltaTime.asSeconds() > 0.17) {
        if (currentFrame == 4) {
            currentFrame = 0;
        }
        sprite_tmp = moveSprites[currentFrame];
        sprite_tmp.setScale(1, 1); // Patrzy w prawo
        facingRight = true;
        clock.restart();
        currentFrame += 1;
    }
    //cout << "moveSprites ---------- " << moveSprites.size() << endl;
}
void Main_character_artem::left_move() {
    deltaTime = clock.getElapsedTime();
    if (deltaTime.asSeconds() > 0.14) {
        if (currentFrame == 4) {
            currentFrame = 0;
        }
        sprite_tmp = moveSprites[currentFrame];
        sprite_tmp.setScale(-1, 1); // Obrót w poziomie (odbicie)
        facingRight = false;
        clock.restart();
        currentFrame += 1;
    }
}
void Main_character_artem::noneOfThem() {
    sprite_tmp = sprite_stand;
    sprite_tmp.setScale(facingRight ? 1 : -1, 1); // Utrzymanie kierunku

}



void Main_character_artem::render(sf::RenderWindow& window) {
	window.draw(sprite_tmp);
}
void Main_character_artem::update() {
	sprite_tmp.setPosition(400, 470);
    //cout << "Pozycja postaci: (" << sprite_tmp.getPosition().x << ", " << sprite_tmp.getPosition().y << ")" << endl;
}