#pragma once
#include <vector>

struct Point
{
    int x, y;
    explicit Point(int x, int y) : x(x), y(y) {};
    explicit Point() : x(0), y(0) {};

    bool operator==(const Point& p) { return x == p.x && y == p.y; }
    bool operator==(Point& p) { return x == p.x && y == p.y; }
};

enum class EDirection : int
{
    North,
    East,
    South,
    West,
    None
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