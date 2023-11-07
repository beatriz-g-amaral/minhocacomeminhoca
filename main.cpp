#include <iostream>
#include <thread>
#include "minhoca.hpp"
using namespace std;

int main() {
    JogoMinhoca game(20, 20);

    while (!game.IsGameOver()) {
        game.Setup();
        game.Input();
        game.Logic();
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "Dormiu no ponto! Seus pontos:" << game.IsGameOver() << endl;

    return 0;
}
