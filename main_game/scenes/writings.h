#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <sstream>


namespace fs = std::filesystem;
using namespace std;
class Writtings {
public:
    Writtings();
    void conversation_text();
    void update();
    void render(sf::RenderWindow& window);
    vector<string> get_writtings();

private:
    string folder_path;
    sf::Font font;
    sf::Text text;
    sf::Clock clock;
    sf::Time deltaTime = sf::seconds(3);
    vector<string> vec;
    vector<string> speaches; // Dodajemy zmienn¹ cz³onkowsk¹ speaches
    size_t iterator = 0;
    size_t iterator_path = 0;
    bool is_draw = false;

    int extractLastNumber(const fs::path& filePath);
    vector<string> wrapText(string napis, string name);
};
