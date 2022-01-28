class Snake {
    public:
        int New();
        void Move(int X, int Y);
        int CheckCollide();
        void Eat();
        void CheckKeys();

        int PositionX;
        int PositionY;

    private:
        int Size;
        int Direction;
};