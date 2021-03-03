#pragma once
#include <vector>

struct Point
{
    int x, y;
    explicit Point(int x, int y) : x(x), y(y) {};
    explicit Point() : x(0), y(0) {};
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
    static std::vector<Point> getPointAheadOf(const Point& currentPoint, EDirection direction);
    static std::vector<Point> getPointAdjacentOf(const Point& currentPoint, EDirection direction);
};