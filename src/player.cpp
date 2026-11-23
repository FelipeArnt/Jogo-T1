#include "player.h"

void Player::agir(Personagem &alvo) { alvo.receberDano(getAtaque()); }

bool Player::podeAgir() const { return vivo() && energia > 0; }

void Player::reduzirFome(unsigned int qtd) {
  fome = (fome > qtd) ? (fome - qtd) : 0;
}

void Player::reduzirSede(unsigned int qtd) {
  sede = (sede > qtd) ? (sede - qtd) : 0;
}

Inventario &Player::getInventario() { return inventario; }
const Inventario &Player::getInventario() const { return inventario; }

void Player::passarTempo() {
  fome += 3;
  sede += 5;
  energia = (energia > 2) ? (energia - 2) : 0;
}
