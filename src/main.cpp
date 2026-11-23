// main.cpp
#include "jogo.h"
#include "terminal.h"
#include "excecoes.h"
#include <cstdlib>
#include <iostream>
#include <unistd.h>

int main() {
    try {
        GuardTerminal guard;
        Jogo jogo;
        jogo.iniciar();
        jogo.loop();
    } catch (const JogoException& e) {
        std::cerr << "Jogo abortado: " << e.what() << '\n';
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << '\n';
        return 2;
    }
    return 0;
}
