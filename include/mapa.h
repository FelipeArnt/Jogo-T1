#ifndef MAPA_H
#define MAPA_H

#include "tile.h"
#include <stdexcept>
#include <string>
#include <vector>

class Mapa {
private:
  std::vector<std::vector<Tile>> tiles;
  int largura = 0;
  int altura = 0;
  int spawnX = 0, spawnY = 0;

public:
  void carregarArquivo(const std::string &caminho);
  Tile& getTile(int x, int y);
  const Tile& getTile(int x, int y) const;
  bool bloqueado(int x, int y) const;

  int getLargura() const { return largura; }
  int getAltura() const { return altura; }
  int getSpawnX() const { return spawnX; }
  int getSpawnY() const { return spawnY; }

};

#endif
