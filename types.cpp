#include "types.h"

char EnumUtil::toSymbol(EDirection direction)
{
    switch(direction)
    {
        case EDirection::North:
            return '^';
        case EDirection::East:
            return '>';
        case EDirection::South:
            return 'v';
        case EDirection::West:
            return '<';
        default:
            return ' ';
    }
}

EDirection EnumUtil::getLeftOf(EDirection direction)
{
    switch(direction)
    {
        case EDirection::North:
            return EDirection::West;
        case EDirection::East:
            return EDirection::North;
        case EDirection::South:
            return EDirection::East;
        case EDirection::West:
            return EDirection::South;
        default:
            return EDirection::None;
    }
}

EDirection EnumUtil::getRightOf(EDirection direction)
{
    switch(direction)
    {
        case EDirection::North:
            return EDirection::East;
        case EDirection::East:
            return EDirection::South;
        case EDirection::South:
            return EDirection::West;
        case EDirection::West:
            return EDirection::North;
        default:
            return EDirection::None;
    }
}

std::vector<Point> EnumUtil::getPointAheadOf(const Point& currentPoint, EDirection direction)
{
    std::vector<Point> points;
    Point p1, p2, p3;
    switch(direction)
    {
        case EDirection::North:
            p1.x = currentPoint.x;
            p1.y = currentPoint.y - 1;
            p2.x = currentPoint.x;
            p2.y = currentPoint.y - 2;
            p3.x = currentPoint.x;
            p3.y = currentPoint.y - 3;
            break;
        case EDirection::East:
            p1.x = currentPoint.x + 1;
            p1.y = currentPoint.y;
            p2.x = currentPoint.x + 2;
            p2.y = currentPoint.y;
            p3.x = currentPoint.x + 3;
            p3.y = currentPoint.y;
            break;
        case EDirection::South:
            p1.x = currentPoint.x;
            p1.y = currentPoint.y + 1;
            p2.x = currentPoint.x;
            p2.y = currentPoint.y + 2;
            p3.x = currentPoint.x;
            p3.y = currentPoint.y + 3;
            break;
        case EDirection::West:
            p1.x = currentPoint.x - 1;
            p1.y = currentPoint.y;
            p2.x = currentPoint.x - 2;
            p2.y = currentPoint.y;
            p3.x = currentPoint.x - 3;
            p3.y = currentPoint.y;
            break;
        default:
            break;
    }
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    return points;
}

std::vector<Point> EnumUtil::getPointAdjacentOf(const Point& currentPoint, EDirection direction)
{
    std::vector<Point> points;
    Point p1, p2, p3;
    switch(direction)
    {
        case EDirection::North:
            p1.x = currentPoint.x;
            p1.y = currentPoint.y - 1; // west 1
            p2.x = currentPoint.x - 1; // north 1
            p2.y = currentPoint.y;
            p3.x = currentPoint.x + 1; // south 1
            p3.y = currentPoint.y;
            break;
        case EDirection::East:
            p1.x = currentPoint.x + 1; // south 1
            p1.y = currentPoint.y;
            p2.x = currentPoint.x;
            p2.y = currentPoint.y + 1; // east
            p3.x = currentPoint.x;
            p3.y = currentPoint.y - 1; // west 1
            break;
        case EDirection::South:
            p1.x = currentPoint.x;
            p1.y = currentPoint.y + 1; // east 1
            p2.x = currentPoint.x - 1; // north 1
            p2.y = currentPoint.y;
            p3.x = currentPoint.x + 1; // south 1
            p3.y = currentPoint.y;
            break;
        case EDirection::West:
            p1.x = currentPoint.x - 1; // north 1
            p1.y = currentPoint.y;
            p2.x = currentPoint.x;
            p2.y = currentPoint.y + 1; // east 1
            p3.x = currentPoint.x;
            p3.y = currentPoint.y - 1; // west 1
            break;
        default:
            break;
    }
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    return points;
}
