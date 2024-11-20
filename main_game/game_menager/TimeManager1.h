
#pragma once
#include <SFML/System.hpp>

class TimeManager1 {
private:
    TimeManager1();
    sf::Clock clock;
    float deltaTime;

public:
    static TimeManager1& getInstance();
    void update();
    float getDeltaTime() const;

    // Blokowanie kopiowania i przypisywania
    TimeManager1(const TimeManager1&) = delete;
    TimeManager1& operator=(const TimeManager1&) = delete;
};

