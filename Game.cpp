
#include "Game.hpp"
#include "raylib.h"
#include <vector>
void game::drawSnake()
{
    std::vector<Vector2> body;
    body.push_back(Position);
    DrawRectangleV(Position, SizeHead, GREEN);
}
void game::updataSnake()
{
    
    float TimeOut = 0.3f;
    float DT = GetFrameTime();
    score += DT;
    if (TimeOut <= score)
    {
        flag = true;
    }
    float valueSpeed = speed;
    if(IsKeyPressed(KEY_W)) Directory = up;
    if(IsKeyPressed(KEY_S)) Directory = down;
    if(IsKeyPressed(KEY_D)) Directory = right;
    if(IsKeyPressed(KEY_A)) Directory = left;
    if (Directory == right && flag)
    {
        Position.x += valueSpeed;
        score = 0;
        flag = false;
    }
    if (Directory == left && flag)
    {
        Position.x -= valueSpeed;
        score = 0;
        flag = false;
    }
    if (Directory == up && flag)
    {
        Position.y -= valueSpeed;
        score = 0;
        flag = false;
    }
    if (Directory == down && flag)
    {
        Position.y += valueSpeed;
        score = 0;
        flag = false;
    }
}
Rectangle game::returnRecHead(){
    Rectangle Rec = {Position.x, Position.y, SizeHead.x, SizeHead.y};
    return Rec;
}