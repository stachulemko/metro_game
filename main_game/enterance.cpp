#include "enterance.h"

Enterance::Enterance(/* odpowiednie argumenty dla GlobalPos */)
    : global_pos(/* odpowiednie argumenty dla konstruktora GlobalPos */)
     {
}

void Enterance::update(float offset_x) {
    if (interaction_enter_train.if_ineraction(-3900, -4500)) {
        is_inside = true;
    }
    else {
        is_inside = false;
    }
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	cout << global_pos.get_global_pos_x() << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    interaction_enter_train.update(offset_x, -3900, 300);
}

void Enterance::render(sf::RenderWindow& window) {
    interaction_enter_train.render(window, -3900, -4500);
}


