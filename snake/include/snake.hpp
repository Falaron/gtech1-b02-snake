class Snake {
    public:
        int New();
        void Move(int X, int Y);
        int CheckCollide(int winWidth, int winHeight, int Size);
        void Eat();

        int PosY;
        int PosX;

    private:
        int Size;
        int Direction;
};