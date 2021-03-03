#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //for time() in srand( time(NULL) );
#include <windows.h> // for Sleep()
#include "mars.h"
#include "types.h"

void Mars::init()
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'X', '#', '@', '$' };
    int numOfObjects = (sizeof(objects)/sizeof(*objects)); 

    // TODO : Size to be random generated, perhaps multiplication of 5
    m_DimX = 15;
    m_DimY = 15;

    // Allocation
    map.resize(m_DimY); 
    for(int i = 0 ; i < m_DimY ; ++i)
    {
        map[i].resize(m_DimX); //resize each rows
    }

    // Map object initialization
    for (int i = 0; i <m_DimY; ++i)
    {
        for (int j = 0 ; j < m_DimX; ++j)
        {
            int objectID = std::rand() % numOfObjects;
            map[i][j] = objects[objectID];
        }
    }
}

void Mars::display()
{
    // TODO : Update this to read rover flag, or vice-versa -> display needs to be marsked!
    system("cls");
    std::cout << " -------------------------------" << std::endl;
    std::cout << " = Curiosity, Welcome to Mars! =" << std::endl;
    std::cout << " -------------------------------" << std::endl;
    for (int i = 0 ; i < m_DimY; ++i)
    {
        std::cout << "  "; drawSeparator();

        // Row Index Handling
        // Fill in a space for digit less than 10 that causes alignment on rows.
        const int rowIndex = m_DimY - i;
        if(rowIndex < 10) 
            std::cout<< " ";
        std::cout << std::setw(1) << rowIndex;

        drawRow(i);
    }

    // Reserve space for index then start draw boarder
    std::cout << "  "; drawSeparator();

     // Column Index Handling - Tenth digit
    std::cout << "  ";
    for (int j = 0; j < m_DimX; ++j)
    {
        int digit = (j+1)/10;
        std::cout << " ";

        if(digit == 0)
        {
            std::cout << " ";
        }
        else
        {
            std::cout << digit;
        }
    }
    std::cout << std::endl;

    // Column Index Handling - Single digit
    std::cout << "  ";
    for (int j=0; j< m_DimX; ++j)
    {
        std::cout << " " << (j+1)%10;
    }
    std::cout << std::endl << std::endl;
}


char Mars::getObject(int x, int y) const //this is to flip the y axis array (m_DimY-y)
{
    return map[m_DimY-y][x-1];
}

char Mars::setObject(int x, int y, char c)
{
    return map[m_DimY-y][x-1] = c;
}

bool Mars::isEmpty(int x, int y)
{
    return map[m_DimY-y][x-1]== ' ';
}

bool Mars::isInsideMap(int x, int y)
{
    return (y > 0 && y <= m_DimX) && (x > 0 && x <= m_DimX);
}

bool Mars::isGold(int x, int y)
{
    return map[m_DimY-y][x-1]== '$';
}

bool Mars::isThereGold()
{
    // checks if there is gold IN FRONT of the rover
    /// TODO : No longer relevant.
    int x = getDimX();
    int y = getDimY();
    
    return (isGold(x+1,y) || isGold(x-1,y) || isGold(x,y+1) || isGold(x+1,y-1));
};

void Mars::setRoverInfo(const Point& point, EDirection facing)
{
    m_RoverLocation = point;
    m_RoverFacing = facing;
}

void Mars::drawSeparator()
{
    for (int j = 0; j < m_DimX; ++j)
    {
        std::cout << "+-";
    }
    std::cout << "+" << std::endl;
}

void Mars::drawRow(const int i)
{
    for (int j = 0; j < m_DimX; ++j)
    {
        char display = '?'; 
        
        const bool isPlayer = (m_RoverLocation.x == i && m_RoverLocation.y == j);
        const bool shouldReveal = m_IsDebug || matchPoints(i, j, EnumUtil::getPointAheadOf(m_RoverLocation, m_RoverFacing)) || matchPoints(i, j, EnumUtil::getPointAdjacentOf(m_RoverLocation, m_RoverFacing)); 
        if (isPlayer)
        {
            display = EnumUtil::toSymbol(m_RoverFacing);
        }
        else if(shouldReveal) 
        {
            display = map[i][j];
        }
        
        std::cout << "|" << display;
    }
    std::cout << "|" << std::endl;
}

bool Mars::matchPoints(int i, int j, std::vector<Point> points)
{
    for(Point& p : points)
    {
        if(i == p.x && j == p.y)
        {
            return true;
        }
    }

    return false;
}