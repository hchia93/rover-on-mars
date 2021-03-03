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
    // Simplier line but complex solution -> deduce this to circular bitshifting.
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
    // Simplier line but complex solution -> deduce this to circular bitshifting.
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
