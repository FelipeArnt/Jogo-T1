#include "estadoGameOver.h"
#include "jogo.h"
#include <iostream>

void EstadoGameOver::atualizar(Jogo& jogo) {jogo.encerrar();}
void EstadoGameOver::renderizar(const Jogo& ) const {
    std::cout << "[GAME OVER]" << motivo << '\n';
}
