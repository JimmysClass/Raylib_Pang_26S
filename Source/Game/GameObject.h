#pragma once

#include "raylib.h"
#include "Helpers/Vector.h"

class CGameObject
{
public:
    CGameObject();
    ~CGameObject();

    virtual void update() = 0;
    virtual void draw() = 0;

    vec2 getPosition() { return Position; }
    void setPosition(vec2 pos) { Position = pos; }

protected:
    vec2 Position;
    float Angle = 0;
    vec2 Scale = 1;

    Color ObjectColor = RED;
};
