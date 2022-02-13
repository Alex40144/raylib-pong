#include "Paddle.h"
#include "raylibWrapper.h"

Paddle::Paddle(Vec2<int> position, int upkey, int downkey)
{
    setPosition(position);
    this->upkey = upkey;
    this->downkey = downkey;
}

Vec2<int> Paddle::getPosition()
{
    return this->position;
}

Vec2<int> Paddle::getWidthHeight()
{
    return this->widthHeight;
}


void Paddle::setPosition(Vec2<int> position)
{
    this->position = position;
}

void Paddle::setVelocity(int velocity)
{
    this->velocity = velocity;
}

void Paddle::Draw()
{
	raylibWrapper::DrawRectangle(position, widthHeight, WHITE);
}

void Paddle::Update()
{
    if (IsKeyDown(upkey))
    {
        position = { position.GetX(), position.GetY() - velocity };

        //lock paddle to screen
        if (position.GetY() < 0)
        {
            position = { position.GetX(), 0 };
        } else if (position.GetY() > GetScreenHeight() - widthHeight.GetY())
        {
            position = { position.GetX(), GetScreenHeight() - widthHeight.GetY() };
        }
    }
    else if (IsKeyDown(downkey))
    {
        position = { position.GetX(), position.GetY() + velocity };

        //lock paddle to screen
        if (position.GetY() < 0)
        {
            position = { position.GetX(), 0 };
        }
        else if (position.GetY() > GetScreenHeight() - widthHeight.GetY())
        {
            position = { position.GetX(), GetScreenHeight() - widthHeight.GetY() };
        }
    }
}
