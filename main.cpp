#include "minhoca.h"

int main() {
    JogoMinhoca game(20, 20);

    while (!game.IsGameOver()) {
        game.Setup();
        game.Input();
        game.Logic();
        Sleep(100); 
    }

    std::cout << "Dormiu no ponto! Seus pontos:" << game.IsGameOver() << std::endl;

    return 0;
}
