#include "read.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <filesystem>

namespace fs = std::filesystem;

Read::Read() {
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
    speach_SoundBuffer();
}

void Read::speach_SoundBuffer() {
    int licznik = 0;
    int file_count = number_of_files(path_folder_with_conversation);
    while (licznik <= file_count) {
        int min = 1000;
        std::string tmp_filePath = "";
        for (const auto& entry : fs::directory_iterator(path_folder_with_conversation)) {
            if (fs::is_regular_file(entry)) {
                std::string nameFile = entry.path().filename().string();
                if (nameFile[nameFile.size() - 1] < min) {
                    min = nameFile[nameFile.size() - 1];
                    tmp_filePath = entry.path().string();
                }
            }
        }
        licznik++;
        conversation_paths.push_back(tmp_filePath);
    }
}

int Read::number_of_files(std::string folder_path) {
    int fileCount = 0;
    for (const auto& entry : fs::directory_iterator(folder_path)) {
        if (fs::is_regular_file(entry)) {
            fileCount++;
        }
    }
    return fileCount;
}

void Read::read_conversation() {
   // cout << "0000000000000000000000000000000000000000000000000000000000000" << endl;
	//cout << conversation_paths.size() << endl;
    //cout << "0000000000000000000000000000000000000000000000000000000000000" << endl;
    for (const auto& path : conversation_paths) {
        // Za³aduj plik WAV do sf::SoundBuffer
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(path)) {
            std::cerr << "Nie uda³o siê za³adowaæ pliku dŸwiêkowego: " << path << std::endl;
            continue;
        }

        std::cout << "Za³adowano plik dŸwiêkowy: " << path << std::endl;

        // Utwórz dŸwiêk
        sf::Sound sound(buffer);

        // SprawdŸ, czy dŸwiêk jest gotowy do odtwarzania
        if (sound.getStatus() == sf::Sound::Stopped) {
            std::cout << "DŸwiêk jest gotowy do odtwarzania: " << path << std::endl;
        }
        else {
            std::cerr << "DŸwiêk nie jest gotowy do odtwarzania: " << path << std::endl;
            continue;
        }

        // Odtwórz dŸwiêk
        sound.play();
        std::cout << "Odtwarzanie dŸwiêku: " << path << std::endl;

        // Czekaj, a¿ dŸwiêk siê skoñczy odtwarzaæ przed przejœciem do nastêpnego pliku
        while (sound.getStatus() == sf::Sound::Playing) {
            std::cout << "DŸwiêk jest odtwarzany: " << path << std::endl;
            sf::sleep(sf::milliseconds(100));
        }

        std::cout << "Zakoñczono odtwarzanie dŸwiêku: " << path << std::endl;
    }
}
