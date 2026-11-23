#ifndef ESTADOEXPLORACAO_H
#define ESTADOEXPLORACAO_H

#include "estadoJogo.h"

class EstadoExploracao : public EstadoJogo{
private:
    void tentarMover(Jogo& jogo, int nx, int ny);
    void interagir(Jogo& jogo);
public:
    void atualizar(Jogo& jogo) override;
    void renderizar(const Jogo& jogo) const override;
};


#endif