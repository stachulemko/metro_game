#include "granade.h"
Granade::Granade() {
	damage = 100;
	radius = 100;
	speed_x =200.0f; // Prêdkoœæ rzutu w pikselach na sekundê
	speed_y = -120.0f; // Prêdkoœæ pionowa rzutu w pikselach na sekundê
	gravity = 70.0f;
	is_throw = false;
	right_upper_x = 1092;
	right_upper_y = 205;
	next_x = 20;
	next_y = 20;
	//"C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\artem_movmet2.png"
	load_texture("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\artem_movmet2.png", granade_texture);
	set_sprite(granade, granade_texture, next_x, next_y, right_upper_x, right_upper_y);
	granade.setPosition(400, 460);
	load_texture("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\artem_movmet2.png", explosion_texture);
	set_sprite(explosion, explosion_texture, next_x_explosion, next_y_explosion, right_upper_x_explosion, right_upper_y_explosion);
}
void Granade::load_texture(std::string path, sf::Texture& texture) {
	if (!texture.loadFromFile(path)) {
		std::cout << "Error: Could not load granade texture granade" << std::endl;
	}
}
void Granade::set_sprite(sf::Sprite& sprite, sf::Texture& texture,float next_x,float next_y,float right_upper_x,float right_upper_y) {
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(right_upper_x, right_upper_y, next_x, next_y));
	sprite.setOrigin(next_x / 2 - 10, next_y / 2); // Œrodek jako origin
	//sprite.setPosition(400, 460);

}
void Granade::throw_right(float speed_tmp, float offset_x) {
	sf::Time elapsed = clock.restart();
	//cout << "elapsed time: " << elapsed.asSeconds() << endl;
	//cout << "-------------------------------------------" << endl;
	float deltaTime = elapsed.asSeconds();
	//cout << "deltaTime: " << deltaTime << endl;
	//cout << "granade throw right" << granade.getPosition().x << " " << granade.getPosition().y << endl;
	if (speed_tmp != -1) {
		speed_x = speed_tmp;
	}
	granade.move(speed_x * deltaTime, speed_y * deltaTime);
	speed_y += gravity * deltaTime; // Zastosowanie grawitacji

	if (granade.getPosition().y > 470) {
		is_explosion = true;
		explosion_x = granade.getPosition().x;
		explosion_y = 470;
		granade.setPosition(400, 460);
		is_throw = false;
		speed_x = 200.0f;
		speed_y = -100.0f;
	}
}
void Granade::throw_left(float speed_tmp,float offset_x) {
	sf::Time elapsed = clock.restart();
	float deltaTime = elapsed.asSeconds();
	granade.move(-speed_x * deltaTime, speed_y * deltaTime);
	if (speed_tmp != -1) {
		speed_x = speed_tmp;
	}
	speed_y += gravity * deltaTime; // Zastosowanie grawitacji
	if (granade.getPosition().y > 470) {
		is_explosion = true;
		explosion_x = granade.getPosition().x;
		explosion_y = 470;
		granade.setPosition(400, 460);
		is_throw = false;
		speed_x = 200.0f;
		speed_y = -100.0f;
	}
	
}
void Granade::render(	sf::RenderWindow& window, float backgroundOffsetX) {
	if (is_throw == true) {
		window.draw(granade);

	}
	show_explosion(window,backgroundOffsetX);
}
double Granade::get_max_zasieg(float vx,float vy,float g) {
	double zasieg = (2 * vx * vy) / g;
	return zasieg;
}
void Granade::show_explosion(sf::RenderWindow& window, float backgroundOffsetX) {
	//granade_exlosion_deltatime+= clock.restart().asSeconds();
	//cout << "granade_exlosion_deltatime: " << granade_exlosion_deltatime << endl;
	//cout << "-------------------granade explosion-------------------" << endl;
	//cout << "granade explosion: " << greande_explosion << endl;
	//cout << "-------------------granade explosion-------------------" << endl;
	if (is_explosion == true) {
		explosion.setPosition(explosion_x,explosion_y);
		granade_exlosion_deltatime += clock.restart().asSeconds();
		if (granade_exlosion_deltatime >= 0.1f) {
			granade_exlosion_deltatime = 0;
			is_explosion = false;
		}
		else {
			window.draw(explosion);
		}
	}
}