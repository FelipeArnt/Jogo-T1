#ifndef CARANGUEJO_H
#define CARANGUEJO_H

#include "inimigo.h"

class Caranguejo : public Inimigo {
public:
    Caranguejo(int x, int y) : Inimigo("Caranguejo", 30, 6, 5) {
        setPosicao(x, y);
    }

    Acao decidirAcao() const override {
        if (hp < hpMax * 0.3) return Acao::FUGIR;  
        return Acao::ATACAR;
    }
};

#endif
