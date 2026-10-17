
#include "food.hpp"
#include "raylib.h"
#include <iostream>
void food::foodSpawn(Rectangle SizeHead)
{
    if (flagFirstPosition)
    {
        flagFirstPosition = false;
    }else{
        if(CheckCollisionCircleRec(food::ReturnPosFood(), 10 ,SizeHead )){
            std::cout << "Collision! "<< std::endl;
            Position = {float(GetRandomValue(5, 595)), float(GetRandomValue(5, 595))};
        }
    }
}
void food::foodDraw()
{
    DrawCircleV(Position, 10, RED);
}

Vector2 food::ReturnPosFood(){
    return Position;
}