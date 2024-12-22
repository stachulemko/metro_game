#include "main_game/game.h"
#include "main_game/game_menager/TimeManager1.h"
//#include <windows.h>
using namespace std; 
//TimeManager* TimeManager::instance = nullptr;
int main()
{
    //cout << "niger" << endl;
    //system("chcp 65001");
    Game game;
    //cout << "niger2" << endl;
    sf::View view;
    //while (isRunning)
    TimeManager1& timeManager = TimeManager1::getInstance();
    while (game.getWindow().isOpen())
    {
        timeManager.update();
        game.processEvents();
        game.update();
        game.render();
    }

    //End of application
    return 0;
}