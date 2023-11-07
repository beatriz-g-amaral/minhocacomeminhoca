#include "minhoca.hpp"
#include <iostream>
#include <thread>
#include <cstdlib>

using namespace std;

JogoMinhoca::JogoMinhoca(int w, int h) : width(w), height(h) {
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
    tailX = new int[width * height];
    tailY = new int[width * height];
}

JogoMinhoca::~JogoMinhoca() {
    delete[] tailX;
    delete[] tailY;
}

void JogoMinhoca::ClearScreen() {
    cout << "\033[2J\033[1;1H"; 
}

void JogoMinhoca::Setup() {
    ClearScreen();
    for (int i = 0; i < width + 2; i++)
       cout << "#";
   cout <<endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
               cout << "#";
            if (i == y && j == x)
               cout << "O";
            else if (i == fruitY && j == fruitX)
               cout << "*";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                       cout << "o";
                        print = true;
                    }
                }
                if (!print)
                   cout << " ";
            }

            if (j == width - 1)
               cout << "#";
        }
       cout <<endl;
    }

    for (int i = 0; i < width + 2; i++)
       cout << "#";
   cout <<endl;
   cout << "Score:" << score <<endl;
}

void JogoMinhoca::Input() {
  if (cin) {
      char key;
      cin >> key;
      switch (key) {
          case 'a':
              dir = LEFT;
              break;
          case 'd':
              dir = RIGHT;
              break;
          case 'w':
              dir = UP;
              break;
          case 's':
              dir = DOWN;
              break;
          case 'x':
              gameover = true;
              break;
      }
  }
}

void JogoMinhoca::Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameover = true;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

bool JogoMinhoca::IsGameOver() {
    return gameover;
}
