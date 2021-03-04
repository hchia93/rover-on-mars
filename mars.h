#pragma once
#include "types.h"
#include <vector>

class Mars
{
    public:
        Mars() { init(); }
        void init();
        void display();
    
        inline const int getDimX() const { return m_DimX; } 
        inline const int getDimY() const { return m_DimY; } 

        char getObject(const Point& point) const; 
        char setObject(const Point& point, char c);
    
        bool isEmpty(const Point& point);
        bool isInsideMap(const Point& point);
        bool isGold(const Point& point);
        bool isTrap(const Point& point);
        bool isHill(const Point& point);

        void setRoverInfo(const Point& location, EDirection facing);
        void setDebug(bool isDebug) { m_IsDebug = isDebug; }
        void setDisplayScore(int score) { m_DisplayScore = score; }
        void setGameOver() { m_GameOver = true; }
    
    private:
        void drawSeparator();
        void drawRow(const int i);
        bool matchPoints(const Point& point, std::vector<Point> points);

        std::vector <std::vector<char>> map;
        
        // Required to deduce visibility on draw()
        Point m_RoverLocation;
        EDirection m_RoverFacing;

        int m_DimX, m_DimY;
        bool m_IsDebug = false;

        int m_DisplayScore = 0;
        bool m_GameOver = false;
};
