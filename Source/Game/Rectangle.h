#pragma once

#include "raylib.h"
#include "Shape.h"
#include "Helpers/Vector.h"

class CRectangle : public CShape
{
public:
    CRectangle();
    ~CRectangle();

    void draw() override;

private:
};
