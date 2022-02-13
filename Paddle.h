#pragma once
#ifndef Paddle_h
#define Paddle_h

#include "vec2.h"

class Paddle
{
public:
    Paddle(Vec2<int> position, int upkey, int downkey);
    Vec2<int> getPosition();
    Vec2<int> getWidthHeight();
    void setPosition(Vec2<int> position);
    void setVelocity(int velocity);
    void Draw();
    void Update();
    int score = 0;
private:
    Vec2<int> position = { 0,0 };
    int velocity = 5;
    Vec2<int> widthHeight = { 25, 80 };
    int upkey = 0;
    int downkey = 0;
};

#endif