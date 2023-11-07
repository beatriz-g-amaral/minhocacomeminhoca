#ifndef JogoMinhoca_H
#define JogoMinhoca_H

class JogoMinhoca {
public:
    JogoMinhoca(int w, int h);
    ~JogoMinhoca();

    void Setup();
    void Input();
    void Logic();
    void ClearScreen();
    bool IsGameOver();

private:
    bool gameover;
    const int width;
    const int height;
    int x, y, fruitX, fruitY, score;
    int* tailX;
    int* tailY;
    int nTail;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;
};

#endif
