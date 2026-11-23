#ifndef INIMIGO_H
#define INIMIGO_H

#include "acao.h"
#include "personagem.h"
#include <memory>
#include <string>

class Item;

class Inimigo : public Personagem {
public:
  Inimigo() = default;

  Inimigo(std::string n, unsigned int h, unsigned int atk, unsigned int def) {
    nome = std::move(n);
    hp = h;
    hpMax = h;
    ataque = atk;
    defesa = def;
  }

  virtual Acao decidirAcao() const = 0;

  virtual std::unique_ptr<Item> soltarMochila();

  void agir(Personagem &alvo) override;
};

#endif // INIMIGO_H
