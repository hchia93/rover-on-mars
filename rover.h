#pragma once#
#include "mars.h"

class Rover 
{
    private:
        int x,y;
        char heading;
    public:
        Rover() {}
        void land(Mars& mars);
        void turnRight(Mars& mars);
        void turnLeft(Mars& mars);
        void basicmove (Mars& mars, char);
        void move (Mars& mars);
        int getDimX() const;
        int getDimY() const;
        char ObjAhead(Mars);
};
