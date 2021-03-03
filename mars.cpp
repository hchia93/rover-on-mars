#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //for time() in srand( time(NULL) );
#include <windows.h> // for Sleep()
#include "mars.h"
using namespace std;

void Mars::init()
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ',
    'X', '#', '@', '$' };
    int noOfObjects = 10; //number of objects in the objects array

    dimX = 15;
    dimY = 5;

    //create dynamic 2D array using vector
    map.resize(dimY); //create rows
        for (int i=0; i<dimY; ++i){
        map[i].resize(dimX); //resize each rows
        }
    //put random chars into the vector array
        for (int i=0; i<dimY; ++i){
            for (int j=0; j<dimX; ++j){
                int objNo = rand() % noOfObjects;
                map[i][j] = objects[ objNo ];
            }
        }
}

void Mars::display()
{
    system("cls");
    cout << " --_--------------" << endl;
    cout << " = Curiosity, welcome to Mars! =" << endl;
    cout << " ---------------" << endl;
    for (int i=0; i<dimY; ++i)
    {
        cout << " ";
        for (int j=0; j<dimX; ++j){
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(1) << (dimY-i);
        for (int j=0; j<dimX; ++j){
            cout << "|" << map[i][j];
        }
        cout << "|" << endl;
    }

    cout << " ";
    for (int j=0; j<dimX; ++j){
    cout << "+-";
    }
    cout << "+" << endl;

    cout << " ";
    for (int j=0; j<dimX; ++j)
    {
    int digit = (j+1)/10;
    cout << " ";
    if (digit==0)
    cout << " ";
    else
    cout << digit;
    }
    cout << endl;

    cout << " ";
    for (int j=0; j<dimX; ++j)
    {
    cout << " " << (j+1)%10;
    }
    cout << endl << endl;
    }

    int Mars::getDimX() const{
    return dimX;
    }
    int Mars::getDimY() const{
    return dimY;
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
    if(map[dimY-y][x-1]== ' ')
        return true;
    else
        return false;
}

bool Mars::isInsideMap(int x, int y)
{
    if((y > 0 && y <= dimX) && (x > 0 && x <= dimX))
        return true;
    else
        return false;
}

bool Mars::isGold(int x, int y)
{
    //checks if position given has gold
    if(map[dimY-y][x-1]== '$')
        return true;
    else
        return false;
}

bool Mars::isThereGold()
{
    // checks if there is gold IN FRONT of the rover
    int x = getDimX();
    int y = getDimY();
    if (isGold(x+1,y) || isGold(x-1,y) || isGold(x,y+1) || isGold(x+1,y-1)){
        return true;
    }
    else
        return false;
};
