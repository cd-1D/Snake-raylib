#pragma once
#include "raylib.h"
class game
{
private:
    float SHValue = 20;
    float speed = 20;
    float score = 0.0f;
    Vector2 SizeHead = {20, 20};
    Vector2 Position = {300, 300};
    bool flag = false;
    enum dir
    {
        left,
        right,
        up,
        down
    };
    dir Directory = up;
public:
    void drawSnake();
    void updataSnake();
    Rectangle returnRecHead();   
};