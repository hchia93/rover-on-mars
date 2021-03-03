#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //for time() in srand( time(NULL) );
#include <windows.h> // for Sleep()
#include "mars.h"
#include "rover.h"
using namespace std;

void Rover::land(Mars& mars)
{
    char possibleHeading[] = {'^', '>', '<', 'v'};
    x = (mars.getDimX() + 1) / 2;
    y = (mars.getDimY() + 1) / 2;
    heading = possibleHeading[ rand() % 4 ]; 
    mars.setObject(x,y,heading);
}

void Rover::turnLeft(Mars& mars){
        mars.setObject(x,y,'<');
}

void Rover::turnRight(Mars& mars){
        mars.setObject(x,y,'>');
}

void Rover::basicmove(Mars& mars, char ahead){
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

void Rover::move(Mars& mars){
    //this function will check whats infront of the rover and move it
        char ahead = ObjAhead(mars);
        int x = getDimX();
        int y = getDimY();
        char curdir = mars.getObject(x,y); //rovers current direction (<,>,v,^)
        if( curdir != '#' && ahead == ' '){
            basicmove(mars, curdir);
        }
        if(ahead == 'X'){
            //trap
            basicmove(mars, '@');
            //game over ?
        }
        if(ahead == '$'){
            basicmove(mars, curdir);
        }
        if(ahead == '#'){
            //hill
            //(doesnt move)
        }

            
}

int Rover::getDimX() const{
    return x;
}

int Rover::getDimY() const{
    return y;
}

char Rover::ObjAhead(Mars mars)
{
    // returns what the rover is facing
    int x = getDimX();
    int y = getDimY();
    char posiObj = mars.getObject(x,y);
        if(posiObj == '>')
        {
            return mars.getObject(x+1,y);
        }
        if(posiObj == '<')
        {
            return mars.getObject(x-1,y);
        }
        if(posiObj == '^')
        {
            return mars.getObject(x,y+1);
        }
        if(posiObj == 'v')
        {
            return mars.getObject(x,y-1);
        }
};
