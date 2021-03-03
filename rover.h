#pragma once
#include "mars.h"
#include "types.h"
#include <vector>

class Rover 
{
    public:
        Rover() {}

        void land(Mars& mars);
        void processInput(char c);
        bool hasTravelled(const int x, const int y) const;

        // REVISIT THIS - REMOVE LATER.
        void move (Mars& mars);
        
    private:
        void turnRight();
        void turnLeft();
        void move();

        int m_x, m_y;

        std::vector<Point> m_Map;
        EDirection m_CurrentFacing;
        Mars* m_MarsReference;
};
