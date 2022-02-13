#ifndef raylibWrapper_h
#define raylibWrapper_h
#include <raylib.h>
#include "vec2.h"

namespace raylibWrapper {
    void DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color);
    void DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> widthHeight, int lineThick, Color color);
    void DrawCircle(Vec2<int> pos, int radius, Color color);
}



#endif