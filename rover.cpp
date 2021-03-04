#include "rover.h"
#include "mars.h"
#include "types.h"
#include <cstdlib>
#include <cmath>
#include <vector>

void Rover::land(Mars& mars)
{
    m_MarsReference = &mars;

    const int startingFacing =  std::rand() % 4;
    m_CurrentFacing = static_cast<EDirection>(startingFacing);

    m_Location.x = std::rand() % mars.getDimX() + 1;
    m_Location.y = std::rand() % mars.getDimY() + 1;
    
    // Reroll until it is valid
    while(!m_MarsReference->isInsideMap(m_Location))
    {
        m_Location.x = std::rand() % mars.getDimX() + 1;
        m_Location.y = std::rand() % mars.getDimY() + 1;
    }

    m_MarsReference->setRoverInfo(m_Location, m_CurrentFacing);
    m_MarsReference->setMap(&m_Map);
   
    m_Map.push_back(m_Location);
    explore();
}

void Rover::turnLeft()
{
    // This function is relative to self-orientation
    EDirection newFacing = EnumUtil::getLeftOf(m_CurrentFacing);
    m_CurrentFacing = newFacing;
    
    m_MarsReference->setRoverInfo(m_Location, newFacing);
    explore();
}

void Rover::turnRight()
{
    // This function is relative to self-orientation
    EDirection newFacing = EnumUtil::getRightOf(m_CurrentFacing);
    m_CurrentFacing = newFacing;

    m_MarsReference->setRoverInfo(m_Location, newFacing);
    explore();
}

void Rover::move()
{
    // Peek ahead , do not mark explored yet. Current location should already mark explored.
    std::vector<Point> points = EnumUtil::getPointRowAheadOf(m_Location, m_CurrentFacing);
    
    if(m_MarsReference->isInsideMap(points[0]))
    {
        if(m_MarsReference->isHill(points[0]))
        {
            // Do not move if it is hill ahead.
            return;
        }
       
        // Commit movement
        m_Location = points[0];
        m_MarsReference->setRoverInfo(points[0], m_CurrentFacing);

        // Post movement handling
        if(!m_MarsReference->isEmpty(points[0])) 
        {
            if(m_MarsReference->isGold(points[0]))
            {
                m_GoldScore++;
                m_MarsReference->setObject(points[0], ' ');
            }

            if(m_MarsReference->isTrap(points[0]))
            {
                m_MarsReference->setGameOver();
            }
        }
        
        m_MarsReference->setDisplayScore(m_GoldScore);
        
        explore();
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

void Rover::explore()
{
    // Explore the next direction row.
    for(const Point& p : EnumUtil::getPointRowAheadOf(m_Location, m_CurrentFacing))
    {
        if(!m_MarsReference->isExplored(p))
        {
            m_Map.push_back(p);
        }
    }
}