#include "raylibWrapper.h"
#include <assert.h>
void raylibWrapper::DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color){
    assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); //drawing outside of screen
    DrawRectangle(pos.GetX(), pos.GetY(), widthHeight.GetX(), widthHeight.GetY(), color);
}

void raylibWrapper::DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> widthHeight, int lineThick, Color color){
    assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); //drawing outside of screen
    assert(lineThick > 0); //line thickness less than 0
    DrawRectangleLinesEx({(float)pos.GetX(), (float)pos.GetY(), (float)widthHeight.GetX(), (float)widthHeight.GetY()}, (float)lineThick, color);
}

void raylibWrapper::DrawCircle(Vec2<int> pos, int radius, Color color)
{
    assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); //drawing outside of screen
    assert(radius > 0); //radius less than 0
    DrawCircle(pos.GetX(), pos.GetY(), radius, color);
}
