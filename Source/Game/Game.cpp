#include "raylib.h"
#include <random>
#include <float.h>

#include "Game.h"
#include "Ball.h"
#include "Player.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Helpers/MathFuncs.h"
#include "Helpers/Sprite2D.h"

CGame::CGame()
{
    std::random_device rd;
    srand( rd() );

    Textures["SoccerBall"] = LoadTexture( "Data/Textures/SoccerBall.png" );

    // Create a ball.
    Ball = new CBall(this);

    Player = new CPlayer( { GetScreenWidth()/2.0f, GetScreenHeight()-50.0f } );

    reset();
}

CGame::~CGame()
{
    delete Ball;
    delete Player;

    for( auto texturePair : Textures )
    {
        UnloadTexture( texturePair.second );
    }
}

void CGame::reset()
{
    Ball->reset();
    Ball->setActive( true );
    Ball->setPosition( { GetScreenWidth()/2.0f + rand() % 100 - 50, GetScreenHeight()/2.0f + rand() % 20 - 10 } );
    Ball->setVelocity( {randFloat(-200, 200), randFloat(-200, 200)} );
}

void CGame::update(float deltaTime)
{
    Ball->update( deltaTime );
    Player->update();
}

void CGame::draw()
{
    ClearBackground( WHITE );

    char buffer[64];
    snprintf( buffer, sizeof(buffer), "Ball Pos: %0.0f, %0.0f", Ball->getPosition().X, Ball->getPosition().Y );
    DrawText( buffer, 600, 5, 20, DARKGRAY );

    if( Ball->isActive() )
    {
        Ball->draw();
    }

    Player->draw();

    //CShape shape;
    //shape.draw();

    //CRectangle rect;
    //rect.draw();

    CShape* shapes[2];
    shapes[0] = new CRectangle();
    shapes[1] = new CShape();
    shapes[0]->draw();
    shapes[1]->draw();
}

void CGame::onKey(int keyCode, KeyState keyState)
{
    if( keyCode == 'R' && keyState == KeyState::Pressed )
    {
        reset();
    }

    // Send key events to the ball.
    if( Ball->isActive() )
    {
        Ball->onKey( keyCode, keyState );
    }

    if (keyState == KeyState::Pressed)
    {
        if (keyCode == KEY_LEFT)
        {
            Player->setMovementDir(-1);
        }
    }
}


void CGame::onMouseButton(int button, KeyState keyState)
{
}

void CGame::onMouseMove(float x, float y)
{
}

Texture2D CGame::getTexture(const char* textureName) const
{
    auto it = Textures.find( textureName );
    if( it != Textures.end() )
    {
        return it->second;
    }

    // Return an empty texture if not found.
    assert( false );
    return Texture2D();
}
