#include "Player.h"
#include "Helpers/Sprite2D.h"

CPlayer::CPlayer(vec2 pos)
{
    Position = pos;

    Texture = LoadTexture( "Data/Textures/SoccerBall.png" );
    Sprite = new Sprite2D( Texture );
}

CPlayer::~CPlayer()
{
    delete Sprite;
    UnloadTexture( Texture );
}

void CPlayer::update()
{
    Position.X += MovementDir * Speed;
}

void CPlayer::draw()
{
    Sprite->draw( Position, Angle, Scale );
}
