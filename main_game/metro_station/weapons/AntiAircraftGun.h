#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

class AntiAircraftGun {
private:
    sf::Texture texture;
    sf::Sprite anti_aircraft_gun;
    float hp;
    float damage;
    float amount_of_ammo;
    float range;
    float reload;
    float pos_x;
    float pos_y;
    float offset_x_tmp;
public:
    AntiAircraftGun();
    AntiAircraftGun(float hp, float damage, float amount_of_ammo, float range, float reload, float pos_x, float pos_y, string path);
    void update(float offset_x);
    void render(sf::RenderWindow& window);
};

