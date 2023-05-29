#pragma once

struct Point
{
    Point() = default;

    Point(float x, float y)
        : x(x)
        , y(y)
    {
    }

    bool operator!=(const Point& point) const
    {
        return x != point.x || y != point.y;
    }

    bool operator==(const Point& point) const
    {
        return !(*this != point);
    }

    float x = 0;
    float y = 0;
};