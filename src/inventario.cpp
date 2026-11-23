#include "inventario.h"
#include "player.h"
#include "excecoes.h"
#include <iostream>
#include <stdexcept>

Inventario::Inventario(int cap) : capacidade(cap) {}

void Inventario::adicionar(std::unique_ptr<Item> item) {
    if (!item) return;
    if (cheio())
        throw InventarioCheioException(capacidade);
    itens.push_back(std::move(item));
}

std::unique_ptr<Item> Inventario::remover(int index) {
    if (index < 0 || index >= static_cast<int>(itens.size()))
        throw std::out_of_range("Indice de inventario invalido: " +
                                std::to_string(index));
    auto item = std::move(itens[index]);
    itens.erase(itens.begin() + index);
    return item;
}

void Inventario::usar(int index, Player& j) {
    if (index < 0 || index >= static_cast<int>(itens.size()))
        throw std::out_of_range("Indice de inventario invalido: " +
                                std::to_string(index));

    Item* item = itens[index].get();
    item->usar(j);

    // Consumíveis desaparecem após o uso
    if (item->consumivel())
        itens.erase(itens.begin() + index);
}

void Inventario::listar() const {
    std::cout << "\n=== Inventario (" << itens.size()
              << "/" << capacidade << ") ===\n";
    if (itens.empty()) {
        std::cout << "  (vazio)\n";
        return;
    }
    for (size_t i = 0; i < itens.size(); ++i) {
        std::cout << "  [" << i << "] " << itens[i]->getNome()
                  << "  —  " << itens[i]->descricao() << '\n';
    }
}

bool Inventario::cheio() const {
    return static_cast<int>(itens.size()) >= capacidade;
}

const Item* Inventario::getItem(int index) const {
    if (index < 0 || index >= static_cast<int>(itens.size())) return nullptr;
    return itens[index].get();
}
