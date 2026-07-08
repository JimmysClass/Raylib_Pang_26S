#include "Shape.h"

CShape::CShape()
{
    Position = { 400, 400 };
}

CShape::~CShape()
{
}

void CShape::draw()
{
    DrawEllipse(  Position.X, Position.Y, Scale.X, Scale.Y, ObjectColor  );
}
