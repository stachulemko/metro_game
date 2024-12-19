#include "read.h"
Read::Read() {
	path_folder_with_conversation = "C:\dev\dev_c++\dev_game\metro_game\main_game\assets\audio\conversation_end_of_the_world";
	if (!fs::exists(path_folder_with_conversation)) {
		std::cerr << "Folder nie istnieje!" << std::endl;
		//return -1;
	}
	if (!fs::is_directory(path_folder_with_conversation)) {
		std::cerr << "Podana �cie�ka nie jest folderem!" << std::endl;
		//return -1;
	}

}
void Read::speach_SoundBuffer(sf::SoundBuffer& buffer) {

	int licznik = 0;
	int file_count = number_of_files(path_folder_with_conversation);
	while (licznik <= file_count) {
		int min = 1000;
		string tmp_filePath = "";
		for (const auto& entry : fs::directory_iterator(path_folder_with_conversation)) {
			if (fs::is_regular_file(entry)) {
				string nameFile = entry.path().filename().string(); // Konwersja na std::string
				if (nameFile[nameFile.size() - 1] < min) {
					min = nameFile[nameFile.size() - 1];
					tmp_filePath = entry.path().string();
				}
				//if()
				//::cout << "Plik: " <<  << std::endl;
			}
		}
		licznik++;
		conversation_paths.push_back(tmp_filePath);
	}
}
int Read::number_of_files(string folder_path) {
	int fileCount = 0;
	for (const auto& entry : fs::directory_iterator(folder_path)) {
		if (fs::is_regular_file(entry)) {
			fileCount++;
		}
	}
	return fileCount;
}
void Read::read_conversation() {
	for (const auto& path : conversation_paths) {
		// Za�aduj plik WAV do sf::SoundBuffer
		sf::SoundBuffer buffer;
		if (!buffer.loadFromFile(path)) {
			std::cerr << "Nie uda�o si� za�adowa� pliku d�wi�kowego: " << path << std::endl;
			continue;
		}

		// Utw�rz d�wi�k
		sf::Sound sound(buffer);

		// Odtw�rz d�wi�k
		sound.play();

		// Czekaj, a� d�wi�k si� sko�czy odtwarza� przed przej�ciem do nast�pnego pliku
		while (sound.getStatus() == sf::Sound::Playing) {
			sf::sleep(sf::milliseconds(100));
		}
	}
}
