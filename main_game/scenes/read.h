#pragma once
#include "iostream"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;
class Read {
private:
    vector<string>conversation_paths;
    string path_folder_with_conversation;
    sf::Sound sound;
public:
    Read();
    void speach_SoundBuffer(sf::SoundBuffer &buffer);
	int number_of_files(string folder_path);
    void read_conversation();
};
