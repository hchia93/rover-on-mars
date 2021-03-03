#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //for time() in srand( time(NULL) );
#include <windows.h> // for Sleep()
#include "mars.h"

void Mars::init()
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'X', '#', '@', '$' };
    int numOfObjects = (sizeof(objects)/sizeof(*objects)); 

    // TODO : Size to be random generated, perhaps multiplication of 5
    dimX = 25;
    dimY = 25;

    // Allocation
    map.resize(dimY); 
    for(int i = 0 ; i < dimY ; ++i)
    {
        map[i].resize(dimX); //resize each rows
    }

    // Map object initialization
    for (int i = 0; i <dimY; ++i)
    {
        for (int j = 0 ; j < dimX; ++j)
        {
            int objectID = std::rand() % numOfObjects;
            map[i][j] = objects[objectID];
        }
    }
}

void Mars::display()
{
    system("cls");
    std::cout << " -------------------------------" << std::endl;
    std::cout << " = Curiosity, Welcome to Mars! =" << std::endl;
    std::cout << " -------------------------------" << std::endl;
    for (int i = 0 ; i < dimY; ++i)
    {
        // Reserve space for index
        std::cout << "  ";
        for (int j = 0; j < dimX; ++j)
        {
            std::cout << "+-";
        }
        std::cout << "+" << std::endl;

        // Row Index Handling
        // Fill in a space for digit less than 10 that causes alignment on rows.
        const int rowIndex = dimY - i;
        if(rowIndex < 10) 
            std::cout<< " ";
        std::cout << std::setw(1) << rowIndex;

        for (int j = 0; j < dimX; ++j)
        {
            std::cout << "|" << map[i][j];
        }
        std::cout << "|" << std::endl;
    }

    // TODO : Comment (This is repeated with a chunk above, consider make it a separate helper draw function)
    std::cout << "  ";
    for (int j = 0; j < dimX; ++j)
    {
        std::cout << "+-";
    }
    std::cout << "+" << std::endl;

     // Column Index Handling - Tenth digit
    std::cout << "  ";
    for (int j = 0; j < dimX; ++j)
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
    for (int j=0; j<dimX; ++j)
    {
        std::cout << " " << (j+1)%10;
    }
    std::cout << std::endl << std::endl;
}


char Mars::getObject(int x, int y) const //this is to flip the y axis array (dimY-y)
{
    return map[dimY-y][x-1];
}

char Mars::setObject(int x, int y, char c)
{
    return map[dimY-y][x-1] = c;
}

bool Mars::isEmpty(int x, int y)
{
    return map[dimY-y][x-1]== ' ';
}

bool Mars::isInsideMap(int x, int y)
{
    return (y > 0 && y <= dimX) && (x > 0 && x <= dimX);
}

bool Mars::isGold(int x, int y)
{
    return map[dimY-y][x-1]== '$';
}

bool Mars::isThereGold()
{
    // checks if there is gold IN FRONT of the rover
    int x = getDimX();
    int y = getDimY();
    
    return (isGold(x+1,y) || isGold(x-1,y) || isGold(x,y+1) || isGold(x+1,y-1));
};
