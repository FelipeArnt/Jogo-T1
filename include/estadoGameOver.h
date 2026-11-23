#ifndef ESTADOGAMEOVER_H
#define ESTADOGAMEOVER_H

#include "estadoJogo.h"
#include <string>


class EstadoGameOver : public EstadoJogo{
private:
    std::string motivo;
public:
    explicit EstadoGameOver(std::string m) : motivo(std::move(m)){}
    void atualizar(Jogo& jogo) override;
    void renderizar(const Jogo&) const override;

};
#endif