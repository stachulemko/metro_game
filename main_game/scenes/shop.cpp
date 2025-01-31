#include "shop.h"
Shop::Shop(string path_shop,string path_rust, string path_weapons, int speed_x) {
    if (texture.loadFromFile(path_shop)) {
        std::cerr << "SHOPPPPPPPPPPPPPPPP BACK" << std::endl;
    }
    if (texture1.loadFromFile(path_rust)) {
        std::cerr <<"RUSSSSSSSSSSSSSSSSSSSSSSSSSST" << std::endl;
    }
    if (texture2.loadFromFile(path_weapons)) {
        std::cerr << "SHOPPPPPPPPPPPPPPPP BACK" << std::endl;
    }
    this->speed_x = speed_x;
	rust_back.setTexture(texture1);
	weapons.setTexture(texture2);
    weapons.setPosition(100, -10);
    //weapons.setScale(5, 5);
    rust_back.setPosition(100, -20);
    Sprite.setTexture(texture);
    Sprite.setPosition(100, -20);
    //weapons.setPosition(100,10);
	Sprite.setScale(0.80, 0.6);
    artem.set_position_sprite_tmp(100, 100);
    shape.setSize(sf::Vector2f(150.f, 150.f));
    shape.setPosition(100, 100);
}
void Shop::update() {
    float deltaTime = clock.restart().asSeconds();
    if (artem_mechanics.movingisKeyPressedD()) {
        artem.right_move();
        artem.move_spriteMovment(speed_x, deltaTime);
		shape.move(speed_x * deltaTime, 0.0f);
    }
    if (artem_mechanics.movingisKeyPressedA()) {
        artem.left_move();
        artem.move_spriteMovment(-speed_x, deltaTime);
        shape.move(-speed_x * deltaTime, 0.0f);
    }
	cout <<"artem position : " << artem.get_sprite_tmp_position() << endl;
}
void Shop::render(sf::RenderWindow& window) {
    window.draw(rust_back);
    window.draw(Sprite);
    window.draw(weapons);
  
	//artem.render(window);
	//window.draw(shape);
	
}