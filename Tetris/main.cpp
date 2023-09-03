#include "Game.h"
#include "Settings.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    Game1 game{ settings::screenWidth,
              settings::screenHeight,
              settings::fps,
              "Tetris Raylib" };

    while (!game.GameShouldClose())
    {
        game.Tick();
    }
    return 0;
}
