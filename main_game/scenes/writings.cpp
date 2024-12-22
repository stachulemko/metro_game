#include "writings.h"
#include <fstream>
#include <algorithm>
#include <mutex>

// Konstruktor
Writtings::Writtings() {
    folder_path = "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\converstion_camp_fire";
    if (!font.loadFromFile("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\negro.otf")) {
        std::cerr << "Nie mo¿na wczytaæ czcionki!" << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(200, 250);

    // Odczyt nazw plików z folderu
    if (fs::exists(folder_path) && fs::is_directory(folder_path)) {
        for (const auto& entry : fs::directory_iterator(folder_path)) {
            if (fs::is_regular_file(entry)) {
                vec.push_back(entry.path().filename().string());
            }
        }
    }
    else {
        std::cerr << "Podana œcie¿ka nie istnieje lub nie jest folderem!" << std::endl;
    }

    // Sortowanie plików wed³ug numerów w nazwach
    std::sort(vec.begin(), vec.end(), [this](const string& a, const string& b) {
        return extractLastNumber(a) < extractLastNumber(b);
        });
}

// Funkcja do wyci¹gania ostatniej liczby z nazwy pliku
int Writtings::extractLastNumber(const fs::path& filePath) {
    std::string fileName = filePath.stem().string();
    size_t pos = fileName.find_last_of("0123456789");
    if (pos != std::string::npos) {
        return std::stoi(fileName.substr(pos));
    }
    return 0;
}

// Funkcja dziel¹ca tekst na fragmenty
vector<string> Writtings::wrapText(string napis, string name) {
    vector<string> speaches;
    string wrapped_text = name + " : ";
    string tmp = "";
    int word_count = 0;
    std::istringstream iss(napis);
    string word;
    while (iss >> word) {
        if (word_count == 10) {  // Po 10 s³owach dodajemy now¹ liniê
            speaches.push_back(wrapped_text);
            wrapped_text = name + " : ";
            word_count = 0;
        }
        wrapped_text += word + " ";
        word_count++;
    }
    if (!wrapped_text.empty()) {
        speaches.push_back(wrapped_text);
    }
    return speaches;
}

// G³ówna funkcja przetwarzania konwersacji
void Writtings::conversation_text() {
    if (iterator_path < vec.size()) {  // Sprawdzanie, czy s¹ jeszcze pliki do przetworzenia
        string new_path = folder_path + "\\" + vec[iterator_path];
        speaches.clear(); // Czyszczenie wektora speaches przed wczytaniem nowego pliku

        // Odczyt pliku
        if (fs::exists(new_path)) {
            std::ifstream file(new_path);
            if (file.is_open()) {
                std::ostringstream oss;
                oss << file.rdbuf() << '\0';
                std::string content = oss.str();
				cout << content << endl;


                // Wyci¹gniêcie nazwy bohatera (z nazwy pliku)
                string name = vec[iterator_path].substr(0, vec[iterator_path].find_last_of('.'));
                speaches = wrapText(content, name);
            }
            else {
                std::cerr << "Nie uda³o siê otworzyæ pliku!" << std::endl;
            }
        }

        // Wyœwietlenie zawartoœci
        /*
        if (!speaches.empty()) {
            for (const auto& speech : speaches) {
                std::cout << speech << std::endl;
            }
        }
        */

        iterator_path++;  // PrzejdŸ do nastêpnego pliku
    }
}

void Writtings::update() {
    if (!vec.empty() && iterator_path <= vec.size()) {
        deltaTime = clock.getElapsedTime();
		cout << deltaTime.asSeconds() << endl;
        if (deltaTime.asSeconds() >= 4) {  // Odstêp czasowy 6 sekund
            clock.restart();

            // Pobranie aktualnego tekstu do wyœwietlenia
            if (iterator < speaches.size()) {
                text.setString(speaches[iterator]);
                iterator++;
            }
            else {  // PrzejdŸ do nastêpnego pliku, jeœli skoñczono aktualny
                iterator = 0;
                conversation_text();
            }
            //is_draw = true;
        }
    }
}

// Funkcja render
void Writtings::render(sf::RenderWindow& window) {
    window.draw(text);

    
}
