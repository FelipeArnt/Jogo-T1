#ifndef TILE_H
#define TILE_H

#include "tipoTile.h"
#include <string>

class Player;

class Tile {
private:
  TipoTile tipo;
  bool obstaculo;
  bool interagivel;

public:
  Tile(TipoTile t = TipoTile::AREIA, bool obs = false, bool inter = false)
      : tipo(t), obstaculo(obs), interagivel(inter) {}
  bool bloqueia() const;
  virtual void interagir(Player &p);
  char simbolo() const;
  char serializar() const;
  TipoTile getTipo() const;
  bool isInteragivel() const;
};

#endif
