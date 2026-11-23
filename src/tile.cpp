#include "tile.h"
#include "inventario.h"
#include "itemFactory.h"
#include "player.h"
#include <iostream>

bool Tile::bloqueia() const { return obstaculo; }

char Tile::simbolo() const { // ← se ainda não for const no .h, ajuste lá também
  switch (tipo) {
  case TipoTile::PENHASCO:
    return '0';
  case TipoTile::AREIA:
    return ' ';
  case TipoTile::ARVORE:
    return 'T';
  case TipoTile::BARCO:
    return 'B';
  case TipoTile::AGUA_DOCE:
    return 'A';
  case TipoTile::FOGUEIRA:
    return 'F';
  case TipoTile::SPAWN_INIMIGO:
    return 'I';
  default:
    return '?';
  }
}

char Tile::serializar() const { return simbolo(); }

TipoTile Tile::getTipo() const { return tipo; }

bool Tile::isInteragivel() const { return interagivel; }

void Tile::interagir(Player &p) {
  switch (tipo) {
  case TipoTile::AGUA_DOCE:
    p.reduzirSede(30);
    break;

  case TipoTile::FOGUEIRA:
    p.reduzirFome(20);
    break;

  case TipoTile::ARVORE:
    try {
      p.getInventario().adicionar(ItemFactory::criar("madeira"));
      std::cerr << "[arvore] +1 madeira\n";
    } catch (const std::exception &) {
      std::cerr << "[arvore] inventario cheio\n";
    }
    break;

  case TipoTile::BARCO: {
    std::cerr << "[barco] Jangada precisa de 5 madeiras + 2 cordas\n";
    break;
  }

  default:
    break;
  }
}
