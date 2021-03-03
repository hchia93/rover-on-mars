#pragma once
#include "types.h"
#include <vector>

class Mars
{
    public:
        Mars() { init(); }
        void init();
        void display();
    
        inline const int getDimX() const { return m_DimX; } //If not called, remove this.
        inline const int getDimY() const { return m_DimY; } //If not called, remove this.
        char getObject(int, int) const; 
        char setObject(int,int,char);
    
        bool isEmpty(int, int);
        bool isInsideMap(int, int);
        bool isGold(int, int);
        bool isThereGold();

        void setRoverInfo(const Point& location, EDirection facing);
        void setDebug(bool isDebug) { m_IsDebug = isDebug; }
    
    private:
        void drawSeparator();
        void drawRow(const int i);
        bool matchPoints(int i, int j, std::vector<Point> points);

        std::vector <std::vector<char>> map;
        
        // Required to deduce visibility on draw()
        Point m_RoverLocation;
        EDirection m_RoverFacing;

        int m_DimX, m_DimY;
        bool m_IsDebug = false;
};
