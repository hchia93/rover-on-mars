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
    if(m_GameOver)
    {
        system("cls");
        std::cout << "Game Over" << std::endl;
        std::cout<<"Gold Count: " <<m_DisplayScore << std::endl;
        return;
    }

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
        const int rowIndex = i;
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
        int digit = (j)/10;
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
        std::cout << " " << (j)%10;
    }
    std::cout << std::endl << std::endl;

    std::cout<<std::endl;
    std::cout<<"Gold Count: " <<m_DisplayScore << std::endl;
}

char Mars::getObject(const Point& point) const 
{
    return map[point.y][point.x];
}

char Mars::setObject(const Point& point, char c)
{
    return map[point.y][point.x] = c;
}

bool Mars::isEmpty(const Point& point)
{
    return map[point.y][point.x] == ' ';
}

bool Mars::isInsideMap(const Point& point)
{
    return (point.y > 0 && point.y < m_DimX) && (point.x > 0 && point.x < m_DimX);
}

bool Mars::isGold(const Point& point)
{
    return map[point.y][point.x] == '$';
}

bool Mars::isTrap(const Point& point)
{
    return map[point.y][point.x] == 'X';
}

bool Mars::isHill(const Point& point)
{
    return map[point.y][point.x] == '#';
}

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
        
        Point p = Point(j, i);
        const bool isPlayer = (m_RoverLocation == p);
        const bool shouldReveal = m_IsDebug || matchPoints(p, EnumUtil::getPointAheadOf(m_RoverLocation, m_RoverFacing)) || matchPoints(p, EnumUtil::getPointAdjacentOf(m_RoverLocation, m_RoverFacing)); 
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

bool Mars::matchPoints(const Point& point, std::vector<Point> points)
{
    for(Point& p : points)
    {
        if(p == point)
        {
            return true;
        }
    }

    return false;
}