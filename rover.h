#pragma once
#include "mars.h"
#include "types.h"
#include <vector>

class Rover 
{
    public:
        Rover() {}

        void land(Mars& mars);
        void turnRight();
        void turnLeft();
        void move();
        void processInput(char c);

        // REVISIT THIS
        void basicmove (Mars& mars, char);
        void move (Mars& mars);

        inline const int getDimX() const { return m_x; }
        inline const int getDimY() const { return m_y; }

        char ObjAhead(Mars& mars);

        bool hasTravelled(const int x, const int y) const;
    private:
        int m_x, m_y;

        std::vector<Point> m_Map;
        EDirection m_CurrentFacing;
        Mars* m_MarsReference;
};
