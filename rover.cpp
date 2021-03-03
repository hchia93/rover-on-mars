#include "rover.h"
#include "mars.h"
#include "types.h"
#include <cstdlib>
#include <cmath>

void Rover::land(Mars& mars)
{
    m_MarsReference = &mars;

    m_x = std::rand() % mars.getDimX() + 1;
    m_y = std::rand() % mars.getDimY() + 1;
    
    // Resolve random of 0 - 3 into 2^N form to get 0x01,0x02,0x04,0x08, then resolve into enum
    // Reason is the the same enum will be use to reveal front-adjacent cell (3 cell) without calling 1 function per direction.
    const int startingFacing =  std::rand() % 4;
    m_CurrentFacing = static_cast<EDirection>(std::pow(2, startingFacing));
    
    // Render self on mars
    m_MarsReference->setObject(m_x, m_y, EnumUtil::toSymbol(m_CurrentFacing));

    // Also collect item-info right at this position 
    m_Map.push_back(Point(m_x, m_y));
}

void Rover::turnLeft()
{
    // This function is relative to self-orientation
    EDirection newFacing = EnumUtil::getLeftOf(m_CurrentFacing);
    m_MarsReference->setObject(m_x, m_y, EnumUtil::toSymbol(newFacing));
    m_CurrentFacing = newFacing;
}

void Rover::turnRight()
{
    // This function is relative to self-orientation
    EDirection newFacing = EnumUtil::getRightOf(m_CurrentFacing);
    m_MarsReference->setObject(m_x, m_y, EnumUtil::toSymbol(newFacing));
    m_CurrentFacing = newFacing;
}

void Rover::basicmove(Mars& mars, char ahead)
{
    //this function will move the rover
    int x = getDimX();
    int y = getDimY();
    char posiObj = mars.getObject(x,y);
    if(posiObj == '>' && mars.isInsideMap(x+1,y))
    {
        mars.setObject(x+1,y, ahead);
        mars.setObject(x,y,' ');
    }
    if(posiObj == '<' && mars.isInsideMap(x-1,y))
    {
        mars.setObject(x-1,y, ahead);
        mars.setObject(x,y,' ');
    }
    if(posiObj == 'v' && mars.isInsideMap(x,y-1))
    {
        mars.setObject(x,y-1, ahead);
        mars.setObject(x,y,' ');
    }
    if(posiObj == '^' && mars.isInsideMap(x,y+1))
    {
        mars.setObject(x,y+1, ahead);
        mars.setObject(x,y,' ');
    }
}

void Rover::move()
{
    // TODO : Collect new object here
    // TODO : Mark to map here
    // TODO : Trap handling here
    // TODO : Death handling here.

    // ask mars to check his own gold situation - and notify it is a win.
    //m_MarsReference->update();
}

void Rover::processInput(char c)
{
    //no implemented yet
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
}

// I find this bit weird on the indexing order.
void Rover::move(Mars& mars)
{
    //this function will check whats infront of the rover and move it
    char ahead = ObjAhead(mars);
    int x = getDimX();
    int y = getDimY();
    char curdir = mars.getObject(x,y); //rovers current direction (<,>,v,^)
    if( curdir != '#' && ahead == ' ')
    {
        basicmove(mars, curdir);
    }
    if(ahead == 'X')
    {
        //trap
        basicmove(mars, '@');
        //game over ?
    }
    if(ahead == '$')
    {
        basicmove(mars, curdir);
    }
    if(ahead == '#')
    {
        //hill
        //(doesnt move)
    }
}

char Rover::ObjAhead(Mars& mars)
{
    int x = getDimX();
    int y = getDimY();
    char posiObj = mars.getObject(x,y);

    if(posiObj == '>')
    {
        return mars.getObject(x+1,y);
    } 
    else if(posiObj == '<')
    {
        return mars.getObject(x-1,y);
    }
    else if(posiObj == '^')
    {
        return mars.getObject(x,y+1);
    }
    else if(posiObj == 'v')
    {
        return mars.getObject(x,y-1);
    }

    // TODO : Check default case.
    return posiObj;
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
