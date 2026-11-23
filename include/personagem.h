#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>

class Personagem {
protected:
  unsigned int hp = 100;
  unsigned int hpMax = 100;
  unsigned int xp = 0;
  std::string nome = "Personagem";
  unsigned int ataque = 10;
  unsigned int defesa = 3;
  int x = 0;
  int y = 0;

public:
  Personagem();
  virtual ~Personagem() = default;

  unsigned int getVida() const;
  unsigned int getMaxVida() const;
  unsigned int getXp() const;
  unsigned int getAtaque() const;
  unsigned int getDefesa() const;
  std::string getNome() const;
  int getX() const;
  int getY() const;

  void setAtaque(unsigned int a);
  void setPosicao(int novoX, int novoY);
  void receberDano(unsigned int dano);
  bool vivo() const;

  virtual void agir(Personagem &alvo) = 0;
};

#endif // PERSONAGEM_H
