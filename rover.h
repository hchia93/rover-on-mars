#pragma once
#include "mars.h"

class Rover 
{
    public:
        Rover() {}

        void land(Mars& mars);
        void turnRight(Mars& mars);
        void turnLeft(Mars& mars);
        void basicmove (Mars& mars, char);
        void move (Mars& mars);

        inline const int getDimX() const { return x; };
        inline const int getDimY() const { return y; }
        char ObjAhead(Mars& mars);

    private:
        int x,y;
        char heading;

        //TODO : Store Mars reference here on init. Passing it in every function is tedious.
};
