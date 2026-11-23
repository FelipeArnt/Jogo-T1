// mapa.cpp
#include "mapa.h"
#include "excecoes.h"
#include "tile.h"
#include "tipoTile.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

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
    return Tile(TipoTile::SPAWN_INIMIGO, false, false);
  default:
    return Tile(TipoTile::PENHASCO, true, false);
  }
}

void Mapa::carregarArquivo(const std::string &caminho) {
  std::ifstream arquivo(caminho);
  if (!arquivo.is_open())
    throw MapaNaoEncontradoException(caminho);

  std::vector<std::string> linhas;
  std::string linha;
  while (std::getline(arquivo, linha)) {
    if (!linha.empty() && linha.back() == '\r')
      linha.pop_back();

    if (linhas.empty() && linha.size() >= 3 &&
        static_cast<unsigned char>(linha[0]) == 0xEF &&
        static_cast<unsigned char>(linha[1]) == 0xBB &&
        static_cast<unsigned char>(linha[2]) == 0xBF) {
      linha = linha.substr(3);
    }
    linhas.push_back(linha);
  }

  while (!linhas.empty() && linhas.front().empty())
    linhas.erase(linhas.begin());
  while (!linhas.empty() && linhas.back().empty())
    linhas.pop_back();

  if (linhas.empty())
    throw std::runtime_error("Mapa vazio: " + caminho);

  size_t maxLarg = 0;
  for (const auto &l : linhas)
    maxLarg = std::max(maxLarg, l.size());
  if (maxLarg == 0)
    throw std::runtime_error("Mapa sem colunas: " + caminho);

  tiles.clear();
  tiles.reserve(linhas.size());
  for (const auto &l : linhas) {
    std::vector<Tile> linhaTiles;
    linhaTiles.reserve(maxLarg);
    for (size_t i = 0; i < maxLarg; ++i) {
      char c = (i < l.size()) ? l[i] : '0'; 
      linhaTiles.push_back(criarTileDeChar(c));
    }
    tiles.push_back(std::move(linhaTiles));
  }

  altura = static_cast<int>(tiles.size());
  largura = static_cast<int>(maxLarg);

  spawnX = spawnY = 0;
  bool achou = false;
  for (int y = 0; y < altura && !achou; ++y) {
    for (int x = 0; x < largura; ++x) {
      if (tiles[y][x].getTipo() == TipoTile::BARCO) {
        spawnX = x;
        spawnY = y;
        achou = true;
        break;
      }
    }
  }
}

Tile &Mapa::getTile(int x, int y) {
  if (x < 0 || y < 0 || x >= largura || y >= altura) {
    throw CoordenadaInvalidaException(x, y);
  }
  return tiles[y][x];
}

const Tile &Mapa::getTile(int x, int y) const {
  if (x < 0 || y < 0 || x >= largura || y >= altura) {
    std::cerr << "[getTile const] coord invalida: (" << x << ", " << y
              << ")  limites: largura=" << largura << " altura=" << altura
              << '\n';
    throw std::out_of_range("Tile fora do mapa!");
  }
  return tiles[y][x];
}
bool Mapa::bloqueado(int x, int y) const {
  if (x < 0 || y < 0 || x >= largura || y >= altura)
    return true;
  return tiles[y][x].bloqueia();
}
