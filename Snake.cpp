#include <iostream>
#include "Snake.hpp"
#include "UI.hpp"
#include "raylib.h"
#include <vector>

void Snake::drawSnake(bool is_Ate)
{   
    DrawRectangleV(Position, SizeHead, BLUE);

    for (Vector2 x : body)
    {
        DrawRectangleV(x, SizeHead, GREEN);
        flag = false;
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
    std::cout << body.size() << std::endl;
}
void Snake::updataSnake(bool pause)
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
    if (Directory == right && flag && !pause)
    {
        Position.x += valueSpeed;
        score = 0;
        flag = false;
        body.push_back(Position);
    }
    if (Directory == left && flag && !pause)
    {
        Position.x -= valueSpeed;
        score = 0;
        flag = false;
        body.push_back(Position);
    }
    if (Directory == up && flag && !pause)
    {
        Position.y -= valueSpeed;
        score = 0;
        flag = false;
        body.push_back(Position);
    }
    if (Directory == down && flag && !pause)
    {
        Position.y += valueSpeed;
        score = 0;
        flag = false;
        body.push_back(Position);
    }
}

Rectangle Snake::returnRecHead()
{
    Rectangle Rec = {Position.x, Position.y, SizeHead.x, SizeHead.y};
    return Rec;
}
void Snake::checkcollision(){
    UI ui;
    if(Position.x >= 600 || Position.y >= 600 || Position.x < 0 || Position.y < 0){
        ui.gameover(); 
        Directory = stop;
    }
    for(int i = 0 ; i < body.size() - 1; i++){
        if(Position.x == body[i].x && Position.y == body[i].y){
            ui.gameover();
            Directory = stop;
        }
    }
    std::cout << Position.x << " " << Position.y << std::endl;
}