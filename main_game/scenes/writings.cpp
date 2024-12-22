#include "writings.h"
#include <fstream>
#include <algorithm>
#include <mutex>

// Konstruktor
Writtings::Writtings() {
    folder_path = "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\converstion_camp_fire";
    if (!font.loadFromFile("C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\negro.otf")) {
        std::cerr << "Nie mo�na wczyta� czcionki!" << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(200, 250);

    // Odczyt nazw plik�w z folderu
    if (fs::exists(folder_path) && fs::is_directory(folder_path)) {
        for (const auto& entry : fs::directory_iterator(folder_path)) {
            if (fs::is_regular_file(entry)) {
                vec.push_back(entry.path().filename().string());
            }
        }
    }
    else {
        std::cerr << "Podana �cie�ka nie istnieje lub nie jest folderem!" << std::endl;
    }

    // Sortowanie plik�w wed�ug numer�w w nazwach
    std::sort(vec.begin(), vec.end(), [this](const string& a, const string& b) {
        return extractLastNumber(a) < extractLastNumber(b);
        });
}

// Funkcja do wyci�gania ostatniej liczby z nazwy pliku
int Writtings::extractLastNumber(const fs::path& filePath) {
    std::string fileName = filePath.stem().string();
    size_t pos = fileName.find_last_of("0123456789");
    if (pos != std::string::npos) {
        return std::stoi(fileName.substr(pos));
    }
    return 0;
}

// Funkcja dziel�ca tekst na fragmenty
vector<string> Writtings::wrapText(string napis, string name) {
    vector<string> speaches;
    string wrapped_text = name + " : ";
    string tmp = "";
    int word_count = 0;
    std::istringstream iss(napis);
    string word;
    while (iss >> word) {
        if (word_count == 10) {  // Po 10 s�owach dodajemy now� lini�
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

// G��wna funkcja przetwarzania konwersacji
void Writtings::conversation_text() {
    if (iterator_path < vec.size()) {  // Sprawdzanie, czy s� jeszcze pliki do przetworzenia
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


                // Wyci�gni�cie nazwy bohatera (z nazwy pliku)
                string name = vec[iterator_path].substr(0, vec[iterator_path].find_last_of('.'));
                speaches = wrapText(content, name);
            }
            else {
                std::cerr << "Nie uda�o si� otworzy� pliku!" << std::endl;
            }
        }

        // Wy�wietlenie zawarto�ci
        /*
        if (!speaches.empty()) {
            for (const auto& speech : speaches) {
                std::cout << speech << std::endl;
            }
        }
        */

        iterator_path++;  // Przejd� do nast�pnego pliku
    }
}

void Writtings::update() {
    if (!vec.empty() && iterator_path <= vec.size()) {
        deltaTime = clock.getElapsedTime();
		cout << deltaTime.asSeconds() << endl;
        if (deltaTime.asSeconds() >= 4) {  // Odst�p czasowy 6 sekund
            clock.restart();

            // Pobranie aktualnego tekstu do wy�wietlenia
            if (iterator < speaches.size()) {
                text.setString(speaches[iterator]);
                iterator++;
            }
            else {  // Przejd� do nast�pnego pliku, je�li sko�czono aktualny
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
