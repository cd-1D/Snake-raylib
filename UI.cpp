#include "UI.hpp"
#include "raylib.h"
#include <iostream>
void UI::gameover()
{
    DrawText("Game Over!", 250, 250, 30, RED);
}
void UI::pause()
{
    DrawText("Pause.", 230, 240, 30, WHITE);
    DrawText("Press space to continue...", 130, 290, 30, WHITE);
}
void UI::score(int score){
    DrawText(TextFormat("score: %i", score), 20, 20, 30, WHITE);
}