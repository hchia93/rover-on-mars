#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //for time() in srand( time(NULL) );
//#include <unistd.h> //for Sleep()
#include <windows.h> // for Sleep()
#include "mars.h"
#include "rover.h"

using namespace std;

void test1()
{
    Mars mars;
    mars.display();
}

void test2()
{
    Mars mars;
    mars.display();
    cout << "Dim X = " << mars.getDimX() << endl;
    cout << "Dim Y = " << mars.getDimY() << endl;
} 

void test3()
{
    Mars mars;
    mars.display();
    int x,y;
    char obj;
    x = 1; y = 1;
    obj = mars.getObject(x,y);
    cout << "Object at column " << x << " and row " << y << " is ["
        << obj << "]" << endl;
    x = 15; y = 5;
         obj = mars.getObject(x,y);
    cout << "Object at column " << x << " and row " << y << " is ["
        << obj << "]" << endl;
    x = 5; y = 2;
    obj = mars.getObject(x,y);
        cout << "Object at column " << x << " and row " << y << " is ["
        << obj << "]" << endl;
    x = 10; y = 4;
    obj = mars.getObject(x,y);
        cout << "Object at column " << x << " and row " << y << " is ["
        << obj << "]" << endl;
}

void test4()
{
    Mars mars;
    mars.setObject( 1, 1, 'A');
    mars.setObject(15, 1, 'B');
    mars.setObject(15, 5, 'C');
    mars.setObject( 1, 5, 'D');
    mars.display();
    cout << "The object A should be at column 1 and row 1" << endl;
    cout << "The object B should be at column 15 and row 1" << endl;
    cout << "The object C should be at column 15 and row 5" << endl;
    cout << "The object D should be at column 1 and row 5" << endl;
} 


void test5()
{
    Mars mars;
    mars.setObject( 2,  4, 'Z');
    mars.setObject( 10, 3, ' ');
    mars.display();
    
    cout << "Coordinate (2,4) is ";
    if ( mars.isEmpty(2,4) )
        cout << "empty.";
    else
        cout << "Not empty.";
    cout << endl;

    cout << "Coordinate (10,3) is ";
    if ( mars.isEmpty(10,3) )
        cout << "empty.";
    else
        cout << "not empty.";
    cout << endl;

    cout << "Coordinate (15,5) is ";
    if ( mars.isInsideMap(15,5) )
        cout << "inside map.";
    else
        cout << "not inside map.";
    cout << endl;

    cout << "Coordinate (0,0) is ";
    if ( mars.isInsideMap(0,0) )
        cout << "inside map.";
    else
        cout << "not inside map.";
    cout << endl;
}


void test6()
{
    Mars mars;
   Rover curiosity;
   curiosity.land(mars);
   mars.display();
}

void test7()
{
    Mars mars;
        Rover curiosity;

        int x = mars.getDimX();
        int y = mars.getDimY();

        char posiObj = mars.getObject(x,y);

        curiosity.land(mars);
        mars.display();
        cout <<" land" <<endl;
        system("pause");

        curiosity.turnLeft(mars);
        mars.display();
        cout <<" left" <<endl;
        system("pause");

        curiosity.move(mars);
        mars.display();
        cout <<" move" <<endl;
         system("pause");

        curiosity.move(mars);
        mars.display();
        cout <<" move" <<endl;
        system("pause");

        curiosity.turnRight(mars);
        mars.display();
        cout << "right" <<endl;
        system("pause");
        
        curiosity.move(mars);
        mars.display();
        cout << "move " << endl;
        system("pause");
}

int main()
{
    //srand( time(NULL) );
    srand(1);

    Mars mars;
    mars.display();

    system("pause");
}
