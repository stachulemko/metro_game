#include "shop.h"
Shop::Shop(string path_shop,string path_rust, string path_weapons, int speed_x) {
    if (texture.loadFromFile(path_shop)) {
        std::cerr << "SHOPPPPPPPPPPPPPPPP BACK" << std::endl;
    }
    if (texture1.loadFromFile(path_rust)) {
        std::cerr <<"RUSSSSSSSSSSSSSSSSSSSSSSSSSST" << std::endl;
    }
    if (texture2.loadFromFile("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\guns.png")) {
        std::cerr << "SHOPPPPPPPPPPPPPPPP BACK" << std::endl;
    }
    this->speed_x = speed_x;
	rust_back.setTexture(texture1);
	//weapons.setTexture(texture2);
    //weapons.setPosition(100, -10);
    //weapons.setScale(5, 5);
    rust_back.setPosition(100, -20);
    Sprite.setTexture(texture);
    Sprite.setPosition(100, -20);
    //weapons.setPosition(100,10);
	Sprite.setScale(0.80, 0.6);
    artem.set_position_sprite_tmp(100, 100);
    shape.setSize(sf::Vector2f(150.f, 150.f));
    shape.setPosition(100, 100);
    //-----------------------------------------------
    set_sprite(b1, texture2,{81,40},74,19,915,100);
	b1.setScale(2, 2);
    set_sprite(b2, texture2, { 168,39 }, 73, 23, 1060, 97);
    b2.setScale(2, 2);
}
void Shop::gun(sf::Sprite & sprite, float cost) {
    if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        sprite.setScale(1.5, 1.5);
    }
    else {
        sprite.setScale(2, 2);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        cout << "klikniet" << endl;
    }
}
void Shop::update() {
    gun(b1, 1000);
    gun(b2, 900);

}
void Shop::render(sf::RenderWindow& window) {
    // Pobieranie pozycji myszy w pikselach wzglêdem okna
    sf::Vector2i pixelMousePos = sf::Mouse::getPosition(window);

    // Mapowanie pozycji pikselowej na wspó³rzêdne œwiata
    mousePos = window.mapPixelToCoords(pixelMousePos);

    // Rysowanie t³a z tekstur¹ "rust"
    window.draw(rust_back);

    // Rysowanie g³ównego sprite'a sklepu
    window.draw(Sprite);

    // Rysowanie przycisku b1
    window.draw(b1);
    window.draw(b2);

    // Zakomentowane linie, które mog³yby rysowaæ inne elementy
    // window.draw(b2);
    // artem.render(window);
    // window.draw(shape);
}

void Shop::set_sprite(sf::Sprite& sprite, sf::Texture& texture, sf::Vector2f point, float next_x, float next_y,float pos_x,float pos_y) {
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(point.x , point.y , next_x, next_y));
    sprite.setPosition(pos_x, pos_y);
    br1.setSize(sf::Vector2f(next_x, next_y));
	br1.setPosition(pos_x, pos_y);
    br1.setScale(2, 2);

}