#include "main_character_artem.h"
Main_character_artem::Main_character_artem() {
    //----------------------------------
    sprite_tmp.setPosition(400, 470);
    moveSprites.resize(4);
    calculate_position_points(positions_moves,move_points,upper_right_difference_x,upper_right_difference_y);
    load_texture("C:\\dev\\dev_c++\\dev_game\\TestGame2\\all6.png", all_basic_artem);
    set_sprites_texture(moveSprites, all_basic_artem, move_points, next_x, next_y,10,0);
    //---------------------------------
    set_point(stayed_point, 337, 27);
	set_sprite(sprite_stand, all_basic_artem, stayed_point);
    //---------------------------------
    runningSprites.resize(4);
    calculate_position_points(positions_running, running_points,upper_right_difference_x_run,upper_right_difference_y_run);
    set_sprites_texture(runningSprites, all_basic_artem, running_points, next_x_run, next_y_run,0,10);
    //---------------------------------
    shotingSpritesShoting1.resize(4);
	calculate_position_points(positions_shoting1, shoting1_points, upper_right_difference_x, upper_right_difference_y);
    
	set_sprites_texture(shotingSpritesShoting1, all_basic_artem, shoting1_points, next_x, next_y, 10, 0);
    //---------------------------------
	shotingSpritesShoting2.resize(4);
    cout << "============================" << endl;
	calculate_position_points(positions_shoting2, shoting2_points, upper_right_difference_x, upper_right_difference_y);
    for (int i = 0; i < shoting2_points.size(); i++) {
		cout << shoting2_points[i][0] << " " << shoting2_points[i][1] << endl;
    }
	cout << "============================" << endl;
	set_sprites_texture(shotingSpritesShoting2, all_basic_artem, shoting2_points, next_x_shot2, next_y_shot2, 40, 0);
    //---------------------------------
    set_point(shoting2_point,59 ,661);
	set_sprite(sprite_shoting_2, all_basic_artem, shoting2_point);
	//---------------------------------
	//cout << "moveSprites ---------- " << moveSprites.size() << endl;
	//cout << "runningSprites ---------- " << runningSprites.size() << endl;
	//cout << "shotingSpritesShoting1 ---------- " << shotingSpritesShoting1.size() << endl;
	//cout << "shotingSpritesShoting2 ---------- " << shotingSpritesShoting2.size() << endl;
	//cout << "moveSprites ---------- " << moveSprites.size() << endl;
	//cout << "runningSprites ---------- " << runningSprites.size() << endl;
	//cout << "shotingSpritesShoting1 ---------- " << shotingSpritesShoting1.size() << endl;
	//cout << "shotingSpritesShoting2 ---------- " << shotingSpritesShoting2.size() << endl;
	//cout << "moveSprites ---------- " << moveSprites.size() << endl;
	//cout << "runningSprites ---------- " << runningSprites.size() << endl;
	//cout << "shotingSpritesShoting1 ---------- " << shotingSpritesShoting1.size() << endl;
	//cout << "shotingSpritesShoting2 ---------- " << shotingSpritesShoting2.size() << endl;
	//cout << "moveSprites ---------- " << moveSprites.size() << endl;
	//cout << "runningSprites ---------- " << runningSprites.size() << endl;
	//cout << "shotingSpritesShoting1 ---------- " << shotingSpritesShoting1.size() << endl;
	//cout << "shotingSpritesShoting2 ---------- " << shotingSpritesShoting2.size() << endl;
	//cout << "moveSprites ---------- " << moveSprites.size() << endl;
	//cout << "runningSprites ---------- " << runningSprites.size() << endl;
	//cout << "shotingSpritesShoting1 ---------- " << shotingSpritesShoting1.size() << endl;
	//cout << "shotingSpritesShoting2 ---------- " << shotingSpritesShoting2.size() << endl;
	//cout << "moveSprites ---------- " << moveSprites.size() << endl;
	//cout << "runningSprites ---------- " << runningSprites.size() << endl;
	//cout << "shotingSpritesSh
}
void Main_character_artem::calculate_position_points(vector<vector<float>> positions, vector<vector<float>> &points,float upper_right_x,float upper_right_y ) {
    for (int i = 0; i < positions.size(); i++) {
        vector<float> temp = { positions[i][0] - upper_right_x, positions[i][1] - upper_right_y };
        points.push_back(temp);
    }

}
void Main_character_artem::set_point(sf::Vector2f &point, float x, float y) {
    point.x = x;
    point.y = y;
}
void Main_character_artem::load_texture(string path,sf::Texture &texture) {
    if (!texture.loadFromFile(path)) {
        cout << "Error: Could not load texture" << endl;
        //return -1;
    }
}
void Main_character_artem::set_sprites_texture(vector <sf::Sprite>& sprites, sf::Texture &texture, vector<vector<float>> points, float next_x, float next_y,float corrections_x,float corrections_y) {
    for (int i = 0; i < points.size(); i++) {
        sprites[i].setTexture(texture);
        sprites[i].setTextureRect(sf::IntRect(points[i][0], points[i][1], next_x, next_y));
        sprites[i].setOrigin(next_x / 2 - corrections_x, next_y / 2 - corrections_y); // Ustawiamy punkt odniesienia na œrodek
        sprites[i].setPosition(400, 470);
    }
}
void Main_character_artem::set_sprite(sf::Sprite &sprite,sf::Texture &texture, sf::Vector2f point) {
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(point.x - upper_right_difference_x, point.y - upper_right_difference_y, next_x, next_y));
    sprite.setOrigin(next_x / 2 - 10, next_y / 2); // Œrodek jako origin
    sprite.setPosition(400, 470);
	
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
void Main_character_artem::left_run() {
    deltaTime = clock.getElapsedTime();
    if (deltaTime.asSeconds() > 0.12) {
        if (currentFrame == 4) {
            currentFrame = 0;
        }
        sprite_tmp = runningSprites[currentFrame];
        sprite_tmp.setScale(-1, 1); // Obrót w poziomie (odbicie)
        facingRight = false;
        clock.restart();
        currentFrame += 1;
    }
}
void Main_character_artem::right_run() {
    deltaTime = clock.getElapsedTime();
    if (deltaTime.asSeconds() > 0.12) {
        if (currentFrame == 4) {
            currentFrame = 0;
        }
        sprite_tmp = runningSprites[currentFrame];
        sprite_tmp.setScale(1, 1); // Patrzy w prawo
        facingRight = true;
        clock.restart();
        currentFrame += 1;
    }
    //cout << "moveSprites ---------- " << moveSprites.size() << endl;
}

void Main_character_artem::render(sf::RenderWindow& window) {
	window.draw(sprite_tmp);
}
void Main_character_artem::update() {
	
    cout << "Pozycja postaci: (" << sprite_tmp.getPosition().x << ", " << sprite_tmp.getPosition().y << ")" << endl;
}
void Main_character_artem::left_shoting1() {
    deltaTime = clock.getElapsedTime();
    if (deltaTime.asSeconds() > 0.03) {
        if (currentFrame == 4) {
            currentFrame = 0;
        }
        sprite_tmp = shotingSpritesShoting1[currentFrame];
        sprite_tmp.setScale(-1, 1); // Obrót w poziomie (odbicie)
        facingRight = false;
        clock.restart();
        currentFrame += 1;
    }
}
void Main_character_artem::right_shoting1() {
    deltaTime = clock.getElapsedTime();
    if (deltaTime.asSeconds() > 0.03) {
        if (currentFrame == 4) {
            currentFrame = 0;
        }
        sprite_tmp = shotingSpritesShoting1[currentFrame];
        sprite_tmp.setScale(1, 1); // Patrzy w prawo
        facingRight = true;
        clock.restart();
        currentFrame += 1;
    }

}
void Main_character_artem::right_shoting2() {
    deltaTime = clock.getElapsedTime();
    if (deltaTime.asSeconds() > 0.04) {
        if (currentFrame == 4) {
            currentFrame = 0;
        }
        sprite_tmp = shotingSpritesShoting2[currentFrame];
        sprite_tmp.setScale(1, 1); // Obrót w poziomie (odbicie)
        facingRight = true;
        clock.restart();
        currentFrame += 1;
    }
}
void Main_character_artem::left_shoting2() {
    deltaTime = clock.getElapsedTime();
    if (deltaTime.asSeconds() > 0.04) {
        if (currentFrame == 4) {
            currentFrame = 0;
        }
        sprite_tmp = shotingSpritesShoting2[currentFrame];
        sprite_tmp.setScale(-1, 1); // Patrzy w prawo
        facingRight = false;
        clock.restart();
        currentFrame += 1;
    }
}
void Main_character_artem::stand_run_shoting2() {
    sprite_tmp = sprite_shoting_2;
    sprite_tmp.setScale(facingRight ? 1 : -1, 1); 
}