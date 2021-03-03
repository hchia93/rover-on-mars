#prama once
#include <vector>

class Mars
{
    public:
        Mars() { init(); }
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
    
    private:
        std::vector <std::vector<char>> map;
        int dimX, dimY;
};
