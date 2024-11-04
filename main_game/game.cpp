#pragma once
#include "game.h"
using namespace std;

void Game::update() {
	scene1_menager.update();
}

Game::Game() : scene1_menager(200, 800, 600, "C:\\Users\\KêpkaStanis³aw\\Downloads\\pixel_art_subway.png") {
	// Inicjalizacja okna
	window.create(sf::VideoMode(800, 600), "Game Window");
}
void Game::render() {
	window.clear();
	scene1_menager.render(window);
	window.display();
}
void Game::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
	//movingBackground.update();
}


