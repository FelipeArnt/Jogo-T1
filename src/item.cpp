#include "item.h"
#include "player.h" 
#include <iostream>

// Consumíveis 

Coco::Coco() : Item("Coco", 1) {}

void Coco::usar(Player& p) {
    p.reduzirSede(20);
    std::cout << "Voce bebeu a agua do coco. Sede reduzida em 20.\n";
}

std::string Coco::descricao() const {
    return "Restaura 20 de sede";
}

Peixe::Peixe() : Item("Peixe", 1) {}

void Peixe::usar(Player& p) {
    p.reduzirFome(25);
    std::cout << "Voce comeu o peixe. Fome reduzida em 25.\n";
}

std::string Peixe::descricao() const {
    return "Restaura 25 de fome";
}

Carne::Carne() : Item("Carne", 2) {}

void Carne::usar(Player& p) {
    p.reduzirFome(40);
    std::cout << "Voce comeu a carne. Fome reduzida em 40.\n";
}

std::string Carne::descricao() const {
    return "Restaura 40 de fome";
}

//  Armas 

Faca::Faca() : Item("Faca", 1), bonusAtaque(5) {}

void Faca::usar(Player& p) {
    p.setAtaque(p.getAtaque() + bonusAtaque);
    std::cout << "Voce equipou a faca. +" << bonusAtaque
              << " de ataque permanente.\n";
}

std::string Faca::descricao() const {
    return "Arma: +5 de ataque";
}

Lanca::Lanca() : Item("Lanca", 3), bonusAtaque(8) {}

void Lanca::usar(Player& p) {
    p.setAtaque(p.getAtaque() + bonusAtaque);
    std::cout << "Voce equipou a lanca. +" << bonusAtaque
              << " de ataque permanente.\n";
}

std::string Lanca::descricao() const {
    return "Arma: +8 de ataque";
}

// Materiais 

Madeira::Madeira() : Item("Madeira", 2) {}

void Madeira::usar(Player& p) {
    (void)p;
    std::cout << "Madeira guardada. Util para construir a jangada.\n";
}

std::string Madeira::descricao() const {
    return "Material: essencial para a jangada";
}

Corda::Corda() : Item("Corda", 1) {}

void Corda::usar(Player& p) {
    (void)p;
    std::cout << "Corda guardada. Util para amarrar a jangada.\n";
}

std::string Corda::descricao() const {
    return "Material: essencial para a jangada";
}
