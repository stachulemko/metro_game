#include "read.h"


Read::Read() : conversation_started(false) {
    path_folder_with_conversation = "C:\\dev\\dev_c++\\dev_game\\metro_game\\main_game\\assets\\audio\\conversation_end_of_the_world";
    try {
        if (fs::is_directory(path_folder_with_conversation)) {
            std::cout << "Folder: " << path_folder_with_conversation << " jest folderem." << std::endl;
        }
        else {
            std::cout << "Podana œcie¿ka: " << path_folder_with_conversation << " nie jest folderem." << std::endl;
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "B³¹d: " << e.what() << std::endl;
    }

    for (const auto& entry : fs::directory_iterator(path_folder_with_conversation)) {
        if (fs::is_regular_file(entry)) {
            conversation_paths.push_back(entry.path().string());
        }
    }

    // Sortowanie plików wed³ug numerów w nazwach
    std::sort(conversation_paths.begin(), conversation_paths.end(), compare_paths);
}

bool Read::compare_paths(const std::string& a, const std::string& b) {
    std::regex re("\\d+");
    std::smatch match_a, match_b;

    std::regex_search(a, match_a, re);
    std::regex_search(b, match_b, re);

    int num_a = match_a.empty() ? 0 : std::stoi(match_a.str());
    int num_b = match_b.empty() ? 0 : std::stoi(match_b.str());

    return num_a < num_b;
}

void Read::read_conversation() {
    if (!conversation_started) {
        conversation_started = true;
        std::thread([this]() {
            for (const auto& path : conversation_paths) {
                play_sound(path);
            }
            conversation_started = false;
            }).detach();
    }
}

void Read::play_sound(const std::string& path) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(path)) {
        std::cerr << "Nie uda³o siê za³adowaæ pliku dŸwiêkowego: " << path << std::endl;
        return;
    }

    std::cout << "Za³adowano plik dŸwiêkowy: " << path << std::endl;

    sf::Sound sound(buffer);
    sound.play();
    std::cout << "Odtwarzanie dŸwiêku: " << path << std::endl;

    while (sound.getStatus() == sf::Sound::Playing) {
        sf::sleep(sf::milliseconds(100));
    }

    std::cout << "Zakoñczono odtwarzanie dŸwiêku: " << path << std::endl;
}
