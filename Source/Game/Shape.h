#pragma once

#include "raylib.h"
#include "Helpers/Vector.h"

class CShape
{
public:
    CShape();
    ~CShape();

    virtual void draw();

protected:
    vec2 Position;
    float Angle = 0;
    vec2 Scale = 50;

    Color ObjectColor = RED;
};
