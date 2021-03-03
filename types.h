#pragma once

struct Point
{
    int x, y;
    explicit Point(int x, int y) : x(x), y(y) {};
};

enum EDirection : int
{
    North   = 0x01,
    East    = 0x02,
    South   = 0x03,
    West    = 0x04,
    None    = 0x08
};

class EnumUtil
{
public: 
    static char toSymbol(EDirection direction);
    static EDirection getLeftOf(EDirection direction);
    static EDirection getRightOf(EDirection direction);
    //Point getPointAheadOf(EDirection direction, const Point& currentPoint);
};