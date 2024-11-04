#include <SFML/Graphics.hpp>
#include <iostream>
#include <C:\dev\dev_c++\dev_game\metro_game\main_game\game_menager\game_scene1_menager.h>
using namespace std;
class Game {
private:
	sf::RenderWindow window;
	Game_scene1_menager scene1_menager;
public:
	Game();
	void processEvents();
	void update();
	void render();
	sf::RenderWindow& getWindow() { return window; }
};
