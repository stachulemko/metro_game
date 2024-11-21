
#include "game.h"
using namespace std;

void Game::update() {
	scene1_menager.update();
}

Game::Game() : scene1_menager(200, 800, 600, "C:\\Users\\KêpkaStanis³aw\\Downloads\\pixel_art_subway.png",1185) {
	// Inicjalizacja okna
	window_scale = WindowScale();
	window.create(sf::VideoMode(800, 600), "Metro Game");
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
		if (event.type == sf::Event::Resized) {
			// Oblicz skalowanie przy zmianie rozmiaru okna
			sf::Vector2f newWindowSize(event.size.width, event.size.height); 
			sf::Texture backgroungTexture = scene1_menager.getBackgroundTexture();
			sf::Vector2f imageSize(
				backgroungTexture.getSize().x,
				backgroungTexture.getSize().y
			);

			sf::Vector2f scaledSize = window_scale.scaleToFit(imageSize, newWindowSize);
			float scale = std::min(
				newWindowSize.x / imageSize.x,
				newWindowSize.y / imageSize.y
			);
			vector<sf::Sprite> sprites = scene1_menager.getBackgroundSprites();
			for (int i = 0; i < sprites.size(); i++) {
				sprites[i].setScale(scale, scale);
			}
			//backgroundSprite.setScale(scale, scale);

			// Opcjonalnie: ustaw widok, aby dopasowaæ okno
			
			sf::View view(sf::FloatRect(0, 0, newWindowSize.x, newWindowSize.y-200));
			view.zoom(0.70f);
			view.move(0, -50);
			window.setView(view);
		}
	}
	//movingBackground.update();
}


