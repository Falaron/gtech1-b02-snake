class Snake {
    public:
        int New();
        void Move(int X, int Y);
        int CheckCollide(int winWidth, int winHeight);
        void Eat();

        int PositionX;
        int PositionY;


    private:
        int Size;
        int Direction;
};