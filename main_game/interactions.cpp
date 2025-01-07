#include "interactions.h"
Interactions::Interactions(vector<Interaction>interactions) {
	this->interactions = interactions;
}
void Interactions::add_interaction(Interaction interaction) {
	interactions.push_back(interaction);
}
void Interactions::render() {

}
void Interactions::update() {
	for (auto interaction : interactions) {
		//interaction.update();
	}
}