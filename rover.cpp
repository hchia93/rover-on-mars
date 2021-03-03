#include "rover.h"
#include "mars.h"
#include "types.h"
#include <cstdlib>
#include <cmath>
#include <vector>

void Rover::land(Mars& mars)
{
    m_MarsReference = &mars;

    // Resolve random of 0 - 3 into 2^N form to get 0x01,0x02,0x04,0x08, then resolve into enum
    // Reason is the the same enum will be use to reveal front-adjacent cell (3 cell) without calling 1 function per direction.
    const int startingFacing =  std::rand() % 4;
    m_CurrentFacing = static_cast<EDirection>(std::pow(2, startingFacing));

    m_x = std::rand() % mars.getDimX() + 1;
    m_y = std::rand() % mars.getDimY() + 1;
    
    // Reroll until it is valid
    while(!m_MarsReference->isInsideMap(m_x, m_y))
    {
        m_x = std::rand() % mars.getDimX() + 1;
        m_y = std::rand() % mars.getDimY() + 1;
    }

    
    m_MarsReference->setRoverInfo(Point(m_x, m_y), m_CurrentFacing);
   
    // Also collect item-info right at this position 
    m_Map.push_back(Point(m_x, m_y));
}

void Rover::turnLeft()
{
    // This function is relative to self-orientation
    EDirection newFacing = EnumUtil::getLeftOf(m_CurrentFacing);
    m_CurrentFacing = newFacing;
    
    m_MarsReference->setRoverInfo(Point(m_x, m_y), newFacing);
}

void Rover::turnRight()
{
    // This function is relative to self-orientation
    EDirection newFacing = EnumUtil::getRightOf(m_CurrentFacing);
    m_CurrentFacing = newFacing;

    m_MarsReference->setRoverInfo(Point(m_x, m_y), newFacing);
}

void Rover::move()
{
    std::vector<Point> points = EnumUtil::getPointAheadOf(Point(m_x, m_y), m_CurrentFacing);
    
    if(m_MarsReference->isInsideMap(points[0].x, points[0].y))
    {
        // Check other blockers first.

        
        // TODO : Collect new object here
        // TODO : Trap handling here
        // TODO : Death handling here.

        // Update self movement.
        m_x = points[0].x;
        m_y = points[0].y;

        // Mark on map.
        m_Map.push_back(points[0]); 

        // Notify map about the new move.
        m_MarsReference->setRoverInfo(points[0], m_CurrentFacing);

        // ask mars to check his own gold situation - and notify it is a win.
        //m_MarsReference->update();
    }
}

void Rover::processInput(char c)
{
    m_MarsReference->setDebug(false);
    if(c == 'a' || c == 'A' )
    {
        turnLeft();
    }
    else if(c == 'w' || c == 'W' )
    {
        move();
    }
    else if(c == 'd' || c == 'D' )
    {
        turnRight();
    }
    else if(c == 't' || c == 'T' )
    {
        m_MarsReference->setDebug(true);
    }
}

// TODO : Capture traps and collecting behavior.
void Rover::move(Mars& mars)
{
    //this function will check whats infront of the rover and move it
    //char ahead = ObjAhead(mars);
    //int x = getDimX();
    //int y = getDimY();
    //char curdir = mars.getObject(x,y); //rovers current direction (<,>,v,^)
    //if( curdir != '#' && ahead == ' ')
    //{
    //    basicmove(mars, curdir);
    //}
    //if(ahead == 'X')
    //{
        //trap
        //basicmove(mars, '@');
        //game over ?
    //}
    //if(ahead == '$')
    //{
        //basicmove(mars, curdir);
    //}
    //if(ahead == '#')
    //{
        //hill
        //(doesnt move)
    //}
}

bool Rover::hasTravelled(const int x, const int y) const
{
    for(const Point& p : m_Map)
    {
        if(p.x == x && p.y == y)
        {
            return true;
        }
    }

    return false;
}
