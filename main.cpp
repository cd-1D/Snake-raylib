#include <iostream>
#include "raylib.h"
#include "Snake.hpp"
#include "food.hpp"
#include "UI.hpp"
int main()
{   
    bool pause = false;
    SetTraceLogLevel(LOG_NONE);
    SetTargetFPS(10);
    InitWindow(600, 600, "Game");
    Snake snake;
    food food;
    UI ui;
    while (!WindowShouldClose())
    {   
        if(IsKeyPressed(KEY_SPACE) && pause == false){
            pause = true;
        }else if (IsKeyPressed(KEY_SPACE))
        {
            pause = false;
        }
        
        snake.updataSnake(pause);
        bool is_Ate = food.foodSpawn(snake.returnRecHead());
        BeginDrawing();
        snake.checkcollision();
        ClearBackground(BLACK);
            snake.drawSnake(is_Ate);
            food.foodDraw();
            if(pause){
                ui.pause();
            }
            ui.score(food.getscore());
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}