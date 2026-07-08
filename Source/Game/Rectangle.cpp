#include "Rectangle.h"

CRectangle::CRectangle()
{
    Position = { 600, 400 };
}

CRectangle::~CRectangle()
{
}

void CRectangle::draw()
{
    DrawRectangle( Position.X, Position.Y, Scale.X, Scale.Y, ObjectColor );
}
