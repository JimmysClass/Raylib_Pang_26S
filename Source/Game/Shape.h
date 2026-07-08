#pragma once

#include "raylib.h"
#include "Helpers/Vector.h"

class CShape
{
public:
    CShape();
    ~CShape();

    void draw();

private:
    vec2 Position;
    float Angle;
    vec2 Scale;

    Color ObjectColor;
};
