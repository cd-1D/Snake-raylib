#include <iostream>
#include "Game.hpp"
#include "raylib.h"
#include <vector>
#include "food.hpp"

void game::drawSnake(bool is_Ate)
{

    for (Vector2 x : body)
    {
        DrawRectangleV(x, SizeHead, GREEN);
    }
    if (body.size() > element)
    {
        if (is_Ate)
        {
            element++;
            std::cout << element << std::endl;
        }
        else
        {
            body.erase(body.begin());
        }
    }
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
    if (IsKeyPressed(KEY_W))
        Directory = up;
    if (IsKeyPressed(KEY_S))
        Directory = down;
    if (IsKeyPressed(KEY_D))
        Directory = right;
    if (IsKeyPressed(KEY_A))
        Directory = left;
    if (Directory == right && flag)
    {
        Position.x += valueSpeed;
        score = 0;
        flag = false;
        body.push_back(Position);
    }
    if (Directory == left && flag)
    {
        Position.x -= valueSpeed;
        score = 0;
        flag = false;
        body.push_back(Position);
    }
    if (Directory == up && flag)
    {
        Position.y -= valueSpeed;
        score = 0;
        flag = false;
        body.push_back(Position);
    }
    if (Directory == down && flag)
    {
        Position.y += valueSpeed;
        score = 0;
        flag = false;
        body.push_back(Position);
    }

}

Rectangle game::returnRecHead()
{
    Rectangle Rec = {Position.x, Position.y, SizeHead.x, SizeHead.y};
    return Rec;
}