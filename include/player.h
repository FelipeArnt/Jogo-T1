#ifndef PLAYER_H
#define PLAYER_H

#include "inventario.h"
#include "personagem.h"


class Player : public Personagem {
private:
  unsigned int fome = 0;
  unsigned int sede = 0;
  unsigned int energia = 100;
  Inventario inventario;

public:
  Player() = default;
  void agir(Personagem &alvo) override;
  bool podeAgir() const;
  
  unsigned int getFome() const {return fome;}
  unsigned int getSede() const {return sede;}
  unsigned int getEnergia() const {return energia;}
  
  void reduzirFome(unsigned int qtd);
  void reduzirSede(unsigned int qtd);
  
  Inventario &getInventario();
  const Inventario& getInventario() const;
  void passarTempo();
};

#endif // !PLAYER_H
