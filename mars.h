#ifndef MARS_H
#define MARS_H
#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //for time() in srand( time(NULL) );
#include <windows.h> // for Sleep()
using namespace std;

class Mars
{
    private:
        vector < vector<char> > map;
        int dimX, dimY;
    public:
        Mars()
        {
            init();
        }
        void init();
        void display();
        int getDimX() const;
        int getDimY() const;
        char getObject(int, int) const; 
        char setObject(int,int,char);
        bool isEmpty(int, int);
        bool isInsideMap(int, int);
        bool isGold(int, int);
        bool isThereGold();
};
#endif
