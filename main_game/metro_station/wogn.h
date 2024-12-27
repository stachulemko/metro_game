#pragma once
#include "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\metro_station\\weapons\\AntiAircraftGun.h"
#include "C:\dev\dev_c++\dev_game\metro_game\main_game\metro_station\defence\bagWithSand.h"
#include "C:\dev\dev_c++\dev_game\metro_game\main_game\metro_station\defence\tent.h"
#include "C:\dev\dev_c++\dev_game\metro_game\main_game\metro_station\defence\metro_train.h"
class Wogn {
private:
    float width;
    Tent tent,tent2,tent3,tent4,tent5;
    AntiAircraftGun anti_aircraft_gun;
	BagWithSand bag_with_sand1,bag_with_sand2,bag_with_sand3,bag_with_sand4, bag_with_sand5;
	MetroTrain metro_train;

public:
    Wogn(); // Konstruktor
    void update(float offset_x);
    void render(sf::RenderWindow& window);
};
