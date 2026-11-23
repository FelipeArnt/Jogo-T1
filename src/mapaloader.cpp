#include "mapaloader.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <string>

/* Carregar o mapa a partir do txt  */
std::vector<std::vector<Tile>>
MapaLoader::carregar(const std::string &caminho) {
  std::ifstream arquivo(caminho);
  if (!arquivo.is_open()) {
    throw std::runtime_error("Não foi possivel carregar o mapa: " + caminho);
  }

  std::vector<std::string> linhas;
  std::string linha;
  while (std::getline(arquivo, linha)) {
    if (!linha.empty() && linha.back() == '\r') {
      linhas.push_back(linha);
    }
  }

  size_t largura = 0;
  for (const auto &l : linhas) {
    largura = std::max(largura, l.size());
  }

  std::vector<std::vector<Tile>> matriz;
  matriz.reserve(linhas.size());

  for (const auto &l : linhas) {
    std::vector<Tile> linhaTiles;
    linhaTiles.reserve(largura);
    for (size_t i = 0; i < largura; i++) {
      char c = (i < l.size()) ? l[i] : '0';
      linhaTiles.push_back(criarTileDeChar(c));
    }
    matriz.push_back(std::move(linhaTiles));
  }
  return matriz;
}
