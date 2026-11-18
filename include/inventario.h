#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "item.h"
#include <memory>
#include <vector>

class Player;

class Inventario {
private:
  std::vector<std::unique_ptr<Item>> itens;
  int capacidade;

public:
  explicit Inventario(int capacidade = 10);

  // Lança std::runtime_error se estiver cheio.
  void adicionar(std::unique_ptr<Item> item);

  // Lança std::out_of_range se índice inválido.
  std::unique_ptr<Item> remover(int index);

  // Usa o item e remove se for consumível.
  void usar(int index, Player &p);

  void listar() const;

  bool cheio() const;
  int getTamanho() const { return static_cast<int>(itens.size()); }
  int getCapacidade() const { return capacidade; }
  const Item *getItem(int index) const;
};
#endif
