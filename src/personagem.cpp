#include "personagem.h"

Personagem::Personagem()
    : hp(100), hpMax(100), xp(0), nome("Naufrago"), ataque(10), defesa(3), x(0),
      y(0) {}

unsigned int Personagem::getVida() const { return hp; }
unsigned int Personagem::getMaxVida() const { return hpMax; }
unsigned int Personagem::getXp() const { return xp; }
unsigned int Personagem::getAtaque() const { return ataque; }
unsigned int Personagem::getDefesa() const { return defesa; }
std::string Personagem::getNome() const { return nome; }

int Personagem::getX() const { return x; }
int Personagem::getY() const { return y; }

void Personagem::setAtaque(unsigned int a) { ataque = a; }
void Personagem::setPosicao(int novoX, int novoY) {
  x = novoX;
  y = novoY;
}

void Personagem::receberDano(unsigned int dano) {
  unsigned int real = (dano > defesa) ? (dano - defesa) : 1;
  hp = (real >= hp) ? 0 : (hp - real);
}

bool Personagem::vivo() const { return hp > 0; }
