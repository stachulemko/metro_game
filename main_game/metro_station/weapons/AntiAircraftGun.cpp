#include "AntiAircraftGun.h"

AntiAircraftGun::AntiAircraftGun() : hp(100), damage(10), amount_of_ammo(30), range(500), reload(2) {
}

AntiAircraftGun::AntiAircraftGun(float hp, float damage, float amount_of_ammo, float range, float reload, float pos_x, float pos_y, std::string path)
    : hp(hp), damage(damage), amount_of_ammo(amount_of_ammo), range(range), reload(reload), pos_x(pos_x), pos_y(pos_y) {
    if (!texture.loadFromFile(path)) {
        std::cerr << "Nie mo¿na za³adowaæ t³a 1!" << std::endl;
        //return -1;
    }
    anti_aircraft_gun.setTexture(texture);
	anti_aircraft_gun.setScale(0.7f, 0.7f);
	//anti_aircraft_gun.setPosition(pos_x, pos_y);
}

void AntiAircraftGun::update(float offset_x) {
    offset_x_tmp = offset_x;
    anti_aircraft_gun.setPosition(pos_x + offset_x_tmp, pos_y);
}

void AntiAircraftGun::render(sf::RenderWindow& window) {
    window.draw(anti_aircraft_gun);
}

