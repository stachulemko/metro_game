#include "window_scale.h"
WindowScale::WindowScale(float width, float height) {
	this->width = width;
	this->height = height;
}
WindowScale::WindowScale() {

}
sf::Vector2f WindowScale::get_scale(sf::RenderWindow& window) {

	float scaleX = (float)window.getSize().x / width;
	float scaleY = (float)window.getSize().y / height;
	sf::Vector2f scale = { scaleX, scaleY };
	return scale;
}
sf::Vector2f WindowScale::scaleToFit(const sf::Vector2f& imageSize, const sf::Vector2f& windowSize) {
    float scale = std::min(windowSize.x / imageSize.x, windowSize.y / imageSize.y);
    return sf::Vector2f(imageSize.x * scale, imageSize.y * scale);
}

/*
void WindowScale::_updateViewPos() {
    // Ustaw sta³e wymiary widoku (dopasowane do t³a)
    const sf::Vector2f fixedSize(1080.f, 958.f);

    // Tworzymy widok o sta³ych wymiarach
    _view.setSize(fixedSize);

    // Centrujemy widok na œrodku ekranu lub na graczu
    _view.setCenter(_player.getPosition().x, fixedSize.y / 2);

    // Dopasowanie widoku, aby nie wychodzi³ poza granice t³a
    if (_view.getCenter().x < fixedSize.x / 2) {
        _view.setCenter(fixedSize.x / 2, _view.getCenter().y);
    }
    else if (_view.getCenter().x > _background.getTextureRect().width - (fixedSize.x / 2)) {
        _view.setCenter(_background.getTextureRect().width - (fixedSize.x / 2), _view.getCenter().y);
    }

    // Zastosuj widok do okna
    _window.setView(_view);

    // Aktualizacja tekstów (jeœli potrzebne)
    _updateTextPos();

}
*/