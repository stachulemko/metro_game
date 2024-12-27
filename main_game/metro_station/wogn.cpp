#include "wogn.h"

// Konstruktor klasy Wogn z list¹ inicjalizacyjn¹
Wogn::Wogn()
    : width(100), // Inicjalizacja width
    anti_aircraft_gun(50, 100, 300, 40, 15, 4000, 330,
        "C:\\Users\\KêpkaStanis³aw\\Downloads\\anti_aircraft_gun_transparent.png"),
    bag_with_sand1(100, 4150,472,
        "C:\\Users\\KêpkaStanis³aw\\Downloads\\bag_wtih_sand_trans.png"),
    bag_with_sand2(100, 4100, 472,
        "C:\\Users\\KêpkaStanis³aw\\Downloads\\bag_wtih_sand_trans.png"),
    bag_with_sand3(100, 4047, 472,
        "C:\\Users\\KêpkaStanis³aw\\Downloads\\bag_wtih_sand_trans.png"),
    bag_with_sand4(100, 4055, 465,
        "C:\\Users\\KêpkaStanis³aw\\Downloads\\bag_wtih_sand_trans.png"),
    bag_with_sand5(100, 4100, 465,
        "C:\\Users\\KêpkaStanis³aw\\Downloads\\bag_wtih_sand_trans.png"),
    tent(100, 4500, 365,
        "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\trans_tent.png"),
    tent2(100, 4700, 365,
        "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\trans_tent.png"),
    tent3(100, 4900, 365,
        "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\trans_tent.png"),
    tent4(100, 5100, 365,
        "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\trans_tent.png"),
    tent5(100, 5300, 365,
        "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\trans_tent.png"),
	metro_train(100, 6000, 250,"C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\train_without_back_transparent.png")
{
    // Cia³o konstruktora, jeœli potrzebne
}

void Wogn::update(float offset_x) {
    anti_aircraft_gun.update(offset_x);
    bag_with_sand1.update(offset_x);
    bag_with_sand2.update(offset_x);
    bag_with_sand3.update(offset_x);
    bag_with_sand4.update(offset_x);
    bag_with_sand5.update(offset_x);
	tent.update(offset_x);
	tent2.update(offset_x);
    tent3.update(offset_x);
    tent4.update(offset_x);
    tent5.update(offset_x);
	metro_train.update(offset_x);
};

void Wogn::render(sf::RenderWindow& window) {
    anti_aircraft_gun.render(window);
    bag_with_sand1.render(window);
    bag_with_sand2.render(window);
    bag_with_sand3.render(window);
    bag_with_sand4.render(window);
    bag_with_sand5.render(window);
	tent.render(window);
    tent2.render(window);
    tent3.render(window);
    tent4.render(window);
    tent5.render(window);
	metro_train.render(window);
}
