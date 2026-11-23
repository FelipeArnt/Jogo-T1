#ifndef PIRATA_H
#define PIRATA_H

#include "inimigo.h"

class Pirata : public Inimigo {
public:
    Pirata(int x, int y) : Inimigo("Pirata", 40, 6, 7) {
        setPosicao(x, y);
    }

    Acao decidirAcao() const override {
        if (hp > hpMax * 0.6) return Acao::ATACAR;
        return Acao::DEFENDER;
    }
};

#endif