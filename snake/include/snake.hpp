#include <vector> 

class Snake {
    public:
        int New(int MaxLen);
        void Move(int X, int Y);
        int CheckCollide(int winWidth, int winHeight);
        void Eat();

        int PosY;
        int PosX;

        vector<int> previousPos;
        
    private:
        int Size;
        int Direction;
};