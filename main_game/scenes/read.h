#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <filesystem>
#include <thread>
#include <regex>
#include <algorithm>

namespace fs = std::filesystem;

class Read {
public:
    Read();
    void read_conversation();
    void play_sound(const std::string& path);
	bool get_conversation_started() { return conversation_started; }

private:
    std::string path_folder_with_conversation;
    std::vector<std::string> conversation_paths;
    bool conversation_started;
    static bool compare_paths(const std::string& a, const std::string& b);

};