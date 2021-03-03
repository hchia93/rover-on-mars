#ifndef ROVER_H
#define ROVER_H
#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //for time() in srand( time(NULL) );
#include <windows.h> // for Sleep()
#include "mars.h"
using namespace std;

class Rover 
{
    private:
        int x,y;
        char heading;
    public:
        Rover()
        {
        }
        void land(Mars& mars);
        void turnRight(Mars& mars);
        void turnLeft(Mars& mars);
        void basicmove (Mars& mars, char);
        void move (Mars& mars);
        int getDimX() const;
        int getDimY() const;
        char ObjAhead(Mars);
};
#endif
