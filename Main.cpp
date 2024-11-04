#include "main_game/game.h"
using namespace std; 
int main()
{
    Game game;
       
    //while (isRunning)
    while (game.getWindow().isOpen())
    {
        game.processEvents();
        game.update();
        game.render();
    }

    //End of application
    return 0;
}