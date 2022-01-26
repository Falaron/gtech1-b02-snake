class Snake {
    public:
        int New();
        void Move();
        int CheckCollide();
        void Eat();
        void CheckKeys();

    private:
        int Size;
        int Direction;
};