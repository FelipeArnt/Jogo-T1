#ifndef JAVALI_H
#define JAVALI_H

#include "inimigo.h"

class Javali : public Inimigo {
public:
    Javali(int x, int y) : Inimigo("Javali", 45, 10, 3) {
        setPosicao(x, y);
    }

    Acao decidirAcao() const override {
        return Acao::ATACAR;
    }
};

#endif