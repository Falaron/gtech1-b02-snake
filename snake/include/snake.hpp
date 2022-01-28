class Snake {
    public:
        int New();
        void Move(int X, int Y);
        int CheckCollide();
        void Eat();

        int PosY;
        int PosX;
    private:
        int Size;
        int Direction;
};