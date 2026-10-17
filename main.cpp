#include <iostream>
#include "raylib.h"
#include "Game.hpp"
#include "food.hpp"

int main()
{
    SetTraceLogLevel(LOG_NONE);
    SetTargetFPS(10);
    InitWindow(600, 600, "Game");
    game game;
    food food;

    while (!WindowShouldClose())
    {
        game.updataSnake();
        food.foodSpawn(game.returnRecHead());
        BeginDrawing();
        ClearBackground(BLACK);
            game.drawSnake();
            food.foodDraw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}