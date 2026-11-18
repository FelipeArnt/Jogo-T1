#ifndef MAPALOADER_H
#define MAPALOADER_H

#include "tile.h"
#include <string>
#include <vector>

class MapaLoader {
private:
  static Tile criarTileDeChar(char c) {
    switch (c) {
    case '0':
      return Tile(TipoTile::PENHASCO, true, false);
    case ' ':
      return Tile(TipoTile::AREIA, false, false);
    case 'T':
      return Tile(TipoTile::ARVORE, true, true);
    case 'B':
      return Tile(TipoTile::BARCO, true, true);
    case 'A':
      return Tile(TipoTile::AGUA_DOCE, false, true);
    case 'F':
      return Tile(TipoTile::FOGUEIRA, false, true);
    case 'I':
      return Tile(TipoTile::SPAWN_INIMIGO, true, false);
    default:
      return Tile(TipoTile::DESCONHECIDO, true, false);
    }
  }

public:
  static std::vector<std::vector<Tile>> carregar(const std::string &caminho);
};

#endif
