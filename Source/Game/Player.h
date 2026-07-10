#pragma once

#include "raylib.h"
#include "GameObject.h"
#include "Helpers/Vector.h"

class Sprite2D;

class CPlayer : public CGameObject
{
public:
    CPlayer(vec2 pos);
    ~CPlayer();

    void update() override;
    void draw() override;

    void setMovementDir(float value) { MovementDir = value; }

private:
    Texture2D Texture;
    Sprite2D* Sprite;

    float MovementDir = 0;
    float Speed = 10;
};
