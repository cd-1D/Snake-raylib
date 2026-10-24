#pragma once
#include "raylib.h"
class food
{
private:
    Vector2 Position = {float(GetRandomValue(5, 595)), float(GetRandomValue(5, 595))};
    bool flagFirstPosition = true;
    bool is_ate = false;
public:
    int score = 0;
    Vector2 ReturnPosFood();
    bool foodSpawn(Rectangle SizeHead);
    void foodDraw();
    bool returnIsAte();
    int getscore();
};

