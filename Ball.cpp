#include "Ball.h"
#include "raylibWrapper.h"
#include "raylib.h"

Vec2<int> Ball::getPosition()
{
    return this->position;
}

Vec2<int> Ball::getVelocity()
{
    return this->velocity;
}

void Ball::setPosition(Vec2<int> position)
{
    this->position = position;
}

void Ball::setVelocity(Vec2<int> velocity)
{
    this->velocity = velocity;
}

Ball::Ball(Vec2<int> position, Vec2<int> velocity)
{
    setPosition(position);
    setVelocity(velocity);
}

void Ball::Draw()
{
    raylibWrapper::DrawCircle(position, radius, WHITE);
}

void Ball::Update()
{
    position += velocity;


    //bounce off top and bottom
    if (position.GetY() < 0 + radius)
    {
        setVelocity(Vec2{ velocity.GetX(), -velocity.GetY() });
    } else if (position.GetY() > GetScreenHeight() - radius)
    {
        setVelocity(Vec2{ velocity.GetX(), -velocity.GetY() });
    }
    
}
