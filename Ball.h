#ifndef Ball_h
#define Ball_h

#include "vec2.h"

class Ball
{
public:
    Ball(Vec2<int> position, Vec2<int> velocity);
    Vec2<int> getPosition();
    Vec2<int> getVelocity();
    void setPosition(Vec2<int> position);
    void setVelocity(Vec2<int> velocity);
    void Draw();
    void Update();
private:
    Vec2<int> position = {0,0};
    Vec2<int> velocity = {0,0};
    int radius = 15;
};

#endif