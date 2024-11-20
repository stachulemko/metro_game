#include "TimeManager1.h"

TimeManager1::TimeManager1() : deltaTime(0.f) {}

TimeManager1& TimeManager1::getInstance() {
    static TimeManager1 instance;
    return instance;
}

void TimeManager1::update() {
    deltaTime = clock.restart().asSeconds();
}

float TimeManager1::getDeltaTime() const {
    return deltaTime;
}
