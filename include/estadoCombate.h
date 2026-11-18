#ifndef ESTADOCOMBATE_H
#define ESTADOCOMBATE_H
#include "estadoJogo.h"
#include "acao.h"

class Inimigo;
class Jogo;


class EstadoCombate : public EstadoJogo {
private:
    Inimigo* inimigo = nullptr;
    bool terminou = false;
    bool defendendo = false;

    Acao lerAcaoPlayer() const;
    void executarAcaoPlayer(Jogo& jogo, Acao a);
    void executarAcaoInimigo(Jogo& jogo, Acao a);
    void finalizar(Jogo& jogo);
public:
    explicit EstadoCombate(Inimigo* i) : inimigo(i) {}
    void atualizar(Jogo& jogo)  override;
    void renderizar(const Jogo &jogo) const override;
};


#endif