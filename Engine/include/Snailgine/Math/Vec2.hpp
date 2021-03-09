#pragma once

namespace sn
{
    struct Vec2f
    {
        float X, Y;
    };

    template<typename T>
    class Vector2
    {
        public:
            T x;
            T y;
    };
}