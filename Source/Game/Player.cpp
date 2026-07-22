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

void CPlayer::onKey(int keyCode, KeyState keyState)
{
    if (keyState == KeyState::Pressed)
    {
        if (keyCode == KEY_LEFT || keyCode == KEY_A)
        {
            MovementDir--;
        }
        if (keyCode == KEY_RIGHT || keyCode == KEY_D)
        {
            MovementDir++;
        }
    }

    if (keyState == KeyState::Released)
    {
        if (keyCode == KEY_LEFT || keyCode == KEY_A)
        {
            MovementDir++;
        }
        if (keyCode == KEY_RIGHT || keyCode == KEY_D)
        {
            MovementDir--;
        }
    }
}

void CPlayer::update(float deltaTime)
{
    vec2 dir = { MovementDir, 0 };
    dir.normalize();

    Position += dir * Speed * deltaTime;
}

void CPlayer::draw()
{
    Sprite->draw( Position, Angle, Scale );
}
