#include "granade.h"
Granade::Granade() {
	damage = 100;
	radius = 100;
	speed_x =100.0f; // Prêdkoœæ rzutu w pikselach na sekundê
	speed_y = -50.0f; // Prêdkoœæ pionowa rzutu w pikselach na sekundê
	gravity = 50.0f;
	is_throw = false;
	right_upper_x = 1092;
	right_upper_y = 205;
	next_x = 20;
	next_y = 20;
	//set_sprite(granade, granade_texture, next_x, next_y, right_upper_x, right_upper_y);
	granade.setSize(sf::Vector2f(20.0f, 20.0f));
	granade.setFillColor(sf::Color::Green);
	granade.setOrigin(granade.getSize().x / 2, granade.getSize().y / 2); // Œrodek jako origin
	granade.setPosition(300, 450);
}
void Granade::load_texture(std::string path, sf::Texture& texture) {
	if (!texture.loadFromFile("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\artem_movmet2.png")) {
		std::cout << "Error: Could not load granade texture granade" << std::endl;
	}
}
void Granade::set_sprite(sf::Sprite& sprite, sf::Texture& texture,float next_x,float next_y,float right_upper_x,float right_upper_y) {
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(right_upper_x, right_upper_y, next_x, next_y));
	sprite.setOrigin(next_x / 2 - 10, next_y / 2); // Œrodek jako origin
	sprite.setPosition(400, 460);

}
void Granade::throw_right() {
	sf::Time elapsed = clock.restart();
	//cout << "elapsed time: " << elapsed.asSeconds() << endl;
	//cout << "-------------------------------------------" << endl;
	float deltaTime = elapsed.asSeconds();
	cout << "deltaTime: " << deltaTime << endl;
	cout << "granade throw right" << granade.getPosition().x << " " << granade.getPosition().y << endl;
	granade.move(speed_x * deltaTime, speed_y * deltaTime);
	speed_y += gravity * deltaTime; // Zastosowanie grawitacji

	if (granade.getPosition().y > 470) {
		granade.setPosition(400, 460);
		is_throw = false;
		speed_x = 200.0f;
		speed_y = -100.0f;
	}
}
void Granade::throw_left() {
	sf::Time elapsed = clock.restart();
	float deltaTime = elapsed.asSeconds();
	 
	granade.move(-speed_x * deltaTime, speed_y * deltaTime);
	speed_y += gravity * deltaTime; // Zastosowanie grawitacji

	if (granade.getPosition().y > 470) {
		granade.setPosition(400, 460);
		is_throw = false;
		speed_x = 200.0f;
		speed_y = -100.0f;
	}
	
}
void Granade::render(sf::RenderWindow& window) {
	if (is_throw == true) {
		window.draw(granade);
	}
	
}