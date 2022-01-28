#include <vector> 

class Snake {
    public:
        int New(int MaxLen);
        void Move(int X, int Y);
        int CheckCollide();
        void Eat();

        int PosY;
        int PosX;

        vector<int> previousPos;
        
    private:
        int Size;
        int Direction;
};