#pragma once
#include "raylib.h"
#include <vector>
class Snake
{
private:
    float SHValue = 20;
    float speed = 20;
    float score = 0.0f;
    Vector2 SizeHead = {20, 20};
    Vector2 Position = {300, 300};
    std::vector<Vector2> body {Position};
    bool flag = false;
    enum dir
    {
        left,
        right,
        up,
        down,
        stop
    };
    dir Directory = up;
    int element = 3;
public:
    void drawSnake(bool is_Ate);
    void updataSnake(bool pause);
    void checkcollision();
    Rectangle returnRecHead();   
};