#pragma once
#include "raylib.h"
class food{
    private:
        Vector2 Position = {float(GetRandomValue(5, 595)), float(GetRandomValue(5, 595))};
        bool flagFirstPosition = true;
    public:
        Vector2 ReturnPosFood();
        void foodSpawn(Rectangle SizeHead);
        void foodDraw();
};

