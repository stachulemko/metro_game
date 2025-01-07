#pragma once
#include "C:\dev\dev_c++\dev_game\metro_game\main_game\interaction.h"
#include <vector>
using namespace std;
class Interactions {
private:
	//interactions
	vector<Interaction>interactions;
public:
	Interactions(vector<Interaction>interactions);
	void add_interaction(Interaction interaction);
	void render();
	void update();

	
};